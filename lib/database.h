/**
file: database.h
class: Data Base
author: Caio Viktor and Cristiano Melo
abstract: 
*/

class Database{

	File *DB;


public:

	Register searchRegister();

	void insert();

	bool remove();

}