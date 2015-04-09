/**
file: directory.h
class: Directory
author: Caio Viktor and Cristiano Melo
abstract: 
*/

class Directory{

	int globalDepth;

	int *bucketVector;

	int numberOfBuckets;


public:

	Directory();

	Directory( globalDepth, bucketVector, numberOfBuckets );

	Bucket findBucket( key );

	void insertPage( key, Page );

	void duplicate();

	void removePage( key );

}