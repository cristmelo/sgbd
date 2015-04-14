/**
file: database.h
class: Data Base
author: Caio Viktor and Cristiano Melo
abstract: 
*/

class Database{

	fstream *DB,*Dic;
	string dbName,dicName;

	void openDB(string path);
public:
	Database(string path);

	Record* search(int key);

	void insert(Record reg);

	bool remove(int key);

	bool open(string path);

	bool close();


};