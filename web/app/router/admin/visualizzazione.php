<?php
//Visualizzazione dei dati
$app->get('/visualizza/', function () use ($app) {
	$app->render('index.twig');
});