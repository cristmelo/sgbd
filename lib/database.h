/**
file: database.h
class: Data Base
author: Caio Viktor and Cristiano Melo
abstract: 
*/

class Database{

	fstream *DB,*Dic;
	string dbName,dicName;

	set<int> *generatedRids;

public:
	Database(string path);

	int search(int key);

	void insert(int key);

	bool remove(int key);

	void create();

	bool close();

	void status();
};