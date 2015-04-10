/**
file: bucket.h
class: Bucket
author: Caio Viktor and Cristiano Melo
abstract: 
*/

class Bucket{

	int localDepth;

	DataEntry **dataEntry;

	int numberOfTheDataEntry;

public:

	Bucket(int numberEntry);

	Bucket findDataEntry(int key );

	void insertDataEntry(int key, int rid );

	void removeDataEntry(int key);

}