<?php

/**
* Rappresentazione della tabella Sensore.
* @author <a href="https://github.com/DavidePastore">Davide Pastore</a>
*
*/
class Sensore extends Model{
        public static $_id_column = 'IDSensore';
        
        /**
         * Restituisce tutte le letture di un Sensore.
         */
        public function ordini(){
                return $this->has_many('Lettura', 'IDSensore');
        }
}