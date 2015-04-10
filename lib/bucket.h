/**
file: bucket.h
class: Bucket
author: Caio Viktor and Cristiano Melo
abstract: 
*/

class Bucket:Record{

	int localDepth;

	DataEntry** dataEntry;

	int numberOfTheDataEntry;

public:
	Bucket(string bucket);

	Bucket(int numberEntry);

	DataEntry* findDataEntry( int key );

	void insertDataEntry(int key, int rid );

	void removeDataEntry(int key);

	string toString();
};