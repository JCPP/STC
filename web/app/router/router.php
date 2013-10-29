<?php

require 'admin/visualizzazione.php';

//Pagina non trovata
$app->notFound(function () use ($app) {
	$app->redirect('/');
});