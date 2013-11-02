<?php
	/**
	* API class to get data from the database.
	*/
	class Api{
		
		/**
		* Save data into the database.
		* @param $temperatura: the temperature.
		* @param $umidita: the humidity.
		* @param $pressione: the pressure.
		*/
		public function saveData($temperatura, $umidita, $pressione){
			$date = date('Y-m-d H:i:s');
			$letture = array(
				"Temperatura" => $temperatura,
				"Umidità" => $umidita,
				"Pressione" => $pressione
			);
			
			//Inserisce i dati nel database
			foreach ($letture as $nomeSensore => $lettura){
				$modelLettura = Model::factory('Lettura')->create();
				$modelLettura->ValoreLettura = $lettura;
				$modelLettura->DataLettura = $date;
				$modelLettura->IDSensore = Model::factory('Sensore')->where_equal("NomeSensore", $nomeSensore)->find_one()->IDSensore;
				$modelLettura->save();
			}
		}
		
		/**
		* Read data from the database.
		* @param $numero: the number of element to get.
		* @return Return the string into flot chart.
		*/
		public function getDataForChart($numero){
			$result = '[{
					"label": "Temperatura (°C)",
					"data": [%s]
				},
				{
					"label": "Umidità (%%)",
					"data": [%s],
					"yaxis": 2
				},
				{
					"label": "Pressione (Pa)",
					"data": [%s],
					"yaxis": 3
				}]';
			
			$datiTemperatura = "";
			$datiUmidita = "";
			$datiPressione = "";
			
			$letture = Model::factory('Lettura')
				->join('Sensore', array(
                        'Lettura.IDSensore', '=', 'Sensore.IDSensore'
                ))
				->order_by_desc('Lettura.DataLettura');
				
			
			if($numero != 0){
				$letture = $letture->limit($numero);
			}
			
			$letture = $letture->find_many();
			
			
			foreach ($letture as $lettura) {
				$date = date_parse_from_format ('Y-m-d H:i:s' , $lettura->DataLettura);
				$time = mktime($date['hour'], $date['minute'], $date['second'], $date['month'], $date['day'], $date['year']) * 1000;
				switch($lettura->NomeSensore ){
					case "Temperatura":
						$datiTemperatura .=  '[' . strval($time) . ',' . floatval($lettura->ValoreLettura) . '],';
						break;
					case "Umidità":
						$datiUmidita .=  '[' . strval($time) . ',' . floatval($lettura->ValoreLettura) . '],';
						break;
					case "Pressione":
						$datiPressione .=  '[' . strval($time) . ',' . floatval($lettura->ValoreLettura) . '],';
						break;
				}
			}
			
			//Elimina l'ultima virgola
			$datiTemperatura = substr($datiTemperatura, 0, -1);
			$datiUmidita = substr($datiUmidita, 0, -1);
			$datiPressione = substr($datiPressione, 0, -1);
			
			$result = sprintf($result, $datiTemperatura, $datiUmidita, $datiPressione);
			
			return $result;
		}
		
	}