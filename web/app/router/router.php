<?php

//Home Page
$app->get('/', function () use ($app) {
	$app->render('index.twig');
})->name("HomePage");

//Visualizzazione dei dati
$app->get('/visualizza', function () use ($app) {
	$app->render('visualizza.twig');
})->name("Visualizza");

//Pagina non trovata
$app->notFound(function () use ($app) {
	$app->redirect('/');
});

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
})->name("Ricevi");