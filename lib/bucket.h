/**
file: bucket.h
class: Bucket
author: Caio Viktor and Cristiano Melo
abstract: 
*/

class Bucket{
public:
	int localDepth;
	int position;

	DataEntry** dataEntry;
	bool *isUse;

	int numberOfTheDataEntry;
	int numberOfTheDataEntryEmpty;
	fstream *db;

	string* teste;

// public:
	Bucket(fstream *db);
	Bucket(fstream *db, int position, int localDepth);

	DataEntry* findDataEntry( int key );

	void insertDataEntry(int key, int rid );

	void removeDataEntry(int key);

	void write();

	bool isFull();


};