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

	Bucket** findBucket( int key );

	int getLocalDepthBucket(int id);

	void insertPage( int key, int Page );

	void duplicate();

	void removePage( int key );

	void write();
	static Directory* readDirectory(int position, string path);

};