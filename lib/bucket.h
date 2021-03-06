/**
file: bucket.h
class: Bucket
author: Caio Viktor and Cristiano Melo
abstract: 
*/

class Bucket{
// public:
	int localDepth;
	int position;

	DataEntry** dataEntry;
	bool *isUse;

	int numberOfTheDataEntry;
	int numberOfTheDataEntryEmpty;
	string path;

	string* teste;

public:
	Bucket(string path,int localDepth);
	Bucket(string path, int position, int localDepth); // Na realidade esse construtor ler um buncket do disco

	DataEntry* findDataEntry( int key );

	void insertDataEntry(int key, set<int> *generatedRids);
	void insertDataEntry(DataEntry *data);

	void removeDataEntry(int key);

	void write();

	bool isFull();

	void incrementLocalDepth();

	int getPosition();
	int getLocalDepth();

	void repartBucket(int indexBucket,Bucket* bucket);


};