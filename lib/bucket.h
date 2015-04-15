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
	string path;

	string* teste;

// public:
	Bucket(string path,int localDepth);
	Bucket(string path, int position, int localDepth);

	DataEntry* findDataEntry( int key );

	void insertDataEntry(int key);

	void removeDataEntry(int key);

	void write();

	bool isFull();

	void incrementLocalDepth();

	int getPosition();
	int getLocalDepth();


};