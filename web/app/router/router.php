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
	
	if(isset($_POST['t'])){
		$temperatura = $_POST['t'];
	}
	
	if(isset($_POST['u'])){
		$umidita = $_POST['u'];
	}
	
	if(isset($_POST['p'])){
		$pressione = $_POST['p'];
	}
	
	echo ("Temperatura: " . $temperatura . "/n");
	echo ("Umidità: " . $umidita . "/n");
	echo ("Pressione: " . $pressione . "/n");
	
	//Inserisce i dati nel database
	
	/*
	$sensoreDB = Model::factory('Sensore')->create();
	$sensoreDB->NomeSensore = "Temperatura";
	$sensoreDB->DescrizioneSensore = "Descrizione del sensore";
	$sensoreDB->save();
	*/
	
	
})->name("Ricevi");


//Pagina non trovata
$app->notFound(function () use ($app) {
	$app->redirect('/');
});
