/**
file: directory.h
class: Directory
author: Caio Viktor and Cristiano Melo
abstract: 
*/

class Directory{
public:
	int position;
	int globalDepth;

	int *localDepthBucket;
	int *positionBucket;

	int numberOfBuckets;
	int bytes;
	string path;

// public:

	Directory(int globalDepth,int position,string path );
	Directory( int globalDepth, string path );

	int* findBucket( int key );//result[0] = positionBucket[bucket];result[1] = localDepthBucket[bucket];result[3] = bucket;

	int* findBucket( int key , int level);//result[0] = positionBucket[bucket];result[1] = localDepthBucket[bucket];result[3] = bucket;

	int getLocalDepthBucket(int id);

	int getGlobalDepth();

	void duplicate(int positionBucketCurrent, int indexBucketCurrent );

	bool updateReference(int index, int position, int localDepth);

	void write();

	static Directory* readDirectory(int position, string path);

};