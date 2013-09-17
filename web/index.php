<?php
require 'vendor/autoload.php';

$app = new \Slim\Slim(array(
		'view' => new \Slim\Views\Twig()
));

$view = $app->view();

$view->parserExtensions = array(
    new \Slim\Views\TwigExtension(),
);

//Configurazione del database
ORM::configure('sqlite:./database/db.sqlite');

//Query logging
ORM::configure('logging', true);

$db = ORM::get_db();

require 'app/createDB.php';

require 'app/router/router.php';

$app->run();