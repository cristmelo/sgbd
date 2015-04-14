#include "../lib/main.h"
Bucket::Bucket(string path){

}
Bucket::Bucket(string path, int position, int localDepth){

	this->path = path;
	fstream *db = new fstream(path.c_str(), ios::in | ios::out );
	this->position = position;
	this->localDepth = localDepth;
	this->numberOfTheDataEntry = floor((LENGTH_BUCKETS * LENGTH_PAGE)/(1+LENGTH_DATA_ENTRY));
	this->dataEntry = new DataEntry*[numberOfTheDataEntry];
	this->isUse = new bool[numberOfTheDataEntry];
	this->numberOfTheDataEntryEmpty = 0;
	//teste
	this->teste = new string[this->numberOfTheDataEntry];

	int bytesForBucket = LENGTH_BUCKETS * LENGTH_PAGE;
	char *buffer = new char[bytesForBucket];
	db->seekg(this->position,db->beg);
	db->read(buffer,bytesForBucket);

	for(int i = 0; i < this->numberOfTheDataEntry ;i++){
		string current;
		current = buffer[i];
		if(current == "1")
			this->isUse[i] = true;
		else{
			this->isUse[i] = false;
			this->numberOfTheDataEntryEmpty++;
		}
	}
	for(int i = 0; i < numberOfTheDataEntry; i++){
		int indexCurrent = (i * LENGTH_DATA_ENTRY) + numberOfTheDataEntry;
		string data;
		for(int j = 0; j < LENGTH_DATA_ENTRY; j++){
			data += buffer[indexCurrent+j];
		}
		this->dataEntry[i] = new DataEntry(data);
		this->teste[i] = data;
	}
	db->close();
}

DataEntry* Bucket::findDataEntry( int key ){

}

void Bucket::insertDataEntry(int key, int rid ){

}

void Bucket::removeDataEntry(int key){

}

void Bucket::write(){
	fstream *db = new fstream(path, ios::in | ios::out );
	int emptySpace = (LENGTH_BUCKETS * LENGTH_PAGE) - (this->numberOfTheDataEntry + this->numberOfTheDataEntry * LENGTH_DATA_ENTRY);
	db->seekp(position,db->beg);

	int bytesForBucket = LENGTH_BUCKETS * LENGTH_PAGE;
	string buffer;
	for(int i = 0; i < numberOfTheDataEntry; i++){
		if(isUse[i])
			buffer += "1";
		else
			buffer += "0";
	}
	for(int i = 0; i < numberOfTheDataEntry; i++){
		// buffer += dataEntry[i]->getEntry();
		//teste
		buffer += teste[i];
	}
	for(int i = 0 ; i < emptySpace; i++)
		buffer+="$";

	db->write(buffer.c_str(),bytesForBucket);
	db->close();
}

bool Bucket::isFull(){
	if(this->numberOfTheDataEntryEmpty == 0)
		return true;
	return false;
}