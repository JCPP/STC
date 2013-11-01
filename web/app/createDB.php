<?php
/* Qui verranno create le tabelle utilizzando le funzioni di sqlite
 NOTA: Questa pagina dovrà  essere eliminata e non dovrà  essere inserita all'interno del sito almenocchè
non si utilizzi solo da parte dell'amministratore. Per questo facciamo i dovuti controlli.
*/

$queryContent = file_get_contents("app/database/query.sql");


$queryReader = new QueryReader($queryContent);
$queries = $queryReader->asArray();

//print_r($queries);

foreach($queries as $query){
	try{
		$db->exec($query);
	} catch(PDOException $e){
		echo("Errore nella query: <pre>$query</pre> con errore: <b>".$e->getMessage()."</b></br>");
		exit();
	}
}