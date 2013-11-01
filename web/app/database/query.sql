/**
* Le date sono da considerare nel formato ISO8601 ("YYYY-MM-DD HH:MM:SS").
*/



/**
* CREAZIONE STRUTTURA TABELLE
*/


/**
* Creazione tabella Sensore
*/
CREATE TABLE IF NOT EXISTS Sensore(
	IDSensore INTEGER PRIMARY KEY,
	NomeSensore VARCHAR(50) NOT NULL,
	DescrizioneSensore VARCHAR(30)
);


/**
* Creazione tabella Lettura
*/
CREATE TABLE IF NOT EXISTS Lettura(
	IDLettura INTEGER PRIMARY KEY,
	ValoreLettura VARCHAR(50) NOT NULL,
	DataLettura VARCHAR(18) NOT NULL,
	IDSensore INTEGER,
	FOREIGN KEY(IDSensore) REFERENCES Sensore(IDSensore)
		ON UPDATE CASCADE
		ON DELETE CASCADE
);




/**
* INSERIMENTO DATI
*/

/**
* Inserimento dei sensori.
*/

INSERT OR IGNORE INTO 'Sensore'
	('IDSensore', 'NomeSensore', 'DescrizioneSensore')
VALUES
	(1, 'Temperatura', 'Sensore della temperatura');

INSERT OR IGNORE INTO 'Sensore'
	('IDSensore', 'NomeSensore', 'DescrizioneSensore')
VALUES
	(2, 'Umidità', 'Sensore dell''umidità');

INSERT OR IGNORE INTO 'Sensore'
	('IDSensore', 'NomeSensore', 'DescrizioneSensore')
VALUES
	(3, 'Pressione', 'Sensore della pressione');