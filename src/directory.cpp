#include "../lib/main.h"

Directory::Directory( int globalDepth,int position,string path ){
	this->position = position;
	this->globalDepth = globalDepth;
	this->path = path;
	numberOfBuckets = pow(2,globalDepth);
	localDepthBucket = new int[numberOfBuckets];
	positionBucket = new int[numberOfBuckets];
	bytes = ( LENGTH_DEPTH + (numberOfBuckets * (LENGTH_DEPTH + LENGTH_ID_BUCKET)) );
}
Directory* Directory::readDirectory(int position, string path){
	fstream *dic = new fstream(path.c_str(), ios::in | ios::out );
	dic->seekg(position);
	char *buffer = new char[LENGTH_DEPTH];
	dic->read(buffer,LENGTH_DEPTH);
	string globalDepth;
	globalDepth = buffer;
	int iglobalDepth = stoi(globalDepth);

	Directory *directory = new Directory(iglobalDepth,position,path);
	
	delete buffer;

	buffer = new char[directory->bytes];
	dic->seekg(position);
	dic->read(buffer,directory->bytes);
	string data;

	for(int i = 0 ; i < directory->numberOfBuckets; i++){
		data = "";
		for(int j = 0; j < (LENGTH_ID_BUCKET + LENGTH_DEPTH) ; j++)
			data += buffer[LENGTH_DEPTH + i*(LENGTH_ID_BUCKET + LENGTH_DEPTH) + j];
		directory->positionBucket[i] = stoi(data.substr (0 , LENGTH_ID_BUCKET)) * LENGTH_PAGE * LENGTH_BUCKETS;
		directory->localDepthBucket[i] = stoi(data.substr (LENGTH_ID_BUCKET , data.length()));
	}
	dic->close();
	return directory;
}

Directory::Directory( int globalDepth,string path ){

}

Bucket** Directory::findBucket( int key ){

}

void Directory::insertPage( int key, int Page ){

}

void Directory::duplicate(){

}

void Directory::removePage( int key ){

}

void Directory::write(){

}
