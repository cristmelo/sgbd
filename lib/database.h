/**
file: database.h
class: Data Base
author: Caio Viktor and Cristiano Melo
abstract: 
*/

class Database{

	ifstream *DB;


public:
	Database(string path);

	Record* search(int key);

	void insert(Record reg);

	bool remove(int key);

	bool open(string path);

	bool close();


};