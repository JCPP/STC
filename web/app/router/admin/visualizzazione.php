<?php

//Home Page
$app->get('/', function () use ($app) {
	$app->render('index.twig');
});

//Visualizzazione dei dati
$app->get('/visualizza/', function () use ($app) {
	$app->render('visualizza.twig');
});
