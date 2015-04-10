/**
file: directory.h
class: Directory
author: Caio Viktor and Cristiano Melo
abstract: 
*/

class Directory:Record{

	int globalDepth;

	Bucket **bucketVector;

	int numberOfBuckets;


public:

	Directory(string directory);

	Directory( int globalDepth, int numberOfBuckets );

	Bucket** findBucket( int key );

	void insertPage( int key, int Page );

	void duplicate();

	void removePage( int key );

	string toString();

};