/**
file: database.h
class: Data Base
author: Caio Viktor and Cristiano Melo
abstract: 
*/

class Database{

	ifstream *DB;


public:
	Database(String path);

	Record* search(int key);

	void insert(Record reg);

	bool remove(int key);

	bool open(String path);

	bool close();


}