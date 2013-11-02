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
	$temperatura = "";
	$umidita = "";
	$pressione = "";
	
	if(isset($_POST['t'])){
		$temperatura = $_POST['t'];
	}
	
	if(isset($_POST['u'])){
		$umidita = $_POST['u'];
	}
	
	if(isset($_POST['p'])){
		$pressione = $_POST['p'];
	}
	
	$api = new Api();
	$api->saveData($temperatura, $umidita, $pressione);
	
})->name("Ricevi");


//Ajax requests
$app->post('/ajax/dataSensori/', function () use ($app) {
	$numero = 0;
	if(isset($_POST['numero'])){
		$numero = $_POST['numero'];
	}
	
	$api = new Api();
	echo $api->getDataForChart($numero);
})->name("DataSensori");


//Pagina non trovata
$app->notFound(function () use ($app) {
	$app->redirect('/');
});
