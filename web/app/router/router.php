<?php

//Home Page
$app->get('/', function () use ($app) {
	$app->render('index.twig', array(
			'app' => $app
	));
})->name("Home Page");


//Visualizzazione dei dati
$app->get('/visualizza', function () use ($app) {
	$app->render('visualizza.twig', array(
			'app' => $app,
			'sensori' => Model::factory('Sensore')->find_many()
	));
})->name("Visualizza");


//Ricevi dati
$app->post('/ricevi', function () use ($app) {
	
	$postVars = $app->request()->post();
	$temperatura = "";
	$umidita = "";
	$pressione = "";
	$date = date('Y-m-d H:i:s');
	
	if(isset($_POST['t'])){
		$temperatura = $_POST['t'];
	}
	
	if(isset($_POST['u'])){
		$umidita = $_POST['u'];
	}
	
	if(isset($_POST['p'])){
		$pressione = $_POST['p'];
	}
	
	//echo ("Temperatura: " . $temperatura . "/n");
	//echo ("Umidità: " . $umidita . "/n");
	//echo ("Pressione: " . $pressione . "/n");
	
	
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
	
})->name("Ricevi");


//Pagina non trovata
$app->notFound(function () use ($app) {
	$app->redirect('/');
});
