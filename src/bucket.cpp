#include "../lib/main.h"
Bucket::Bucket(string path, int localDepth){
	this->path = path;
	fstream *db = new fstream(path.c_str(), ios::in | ios::out );
	this->localDepth = localDepth;
	this->numberOfTheDataEntry = floor((LENGTH_BUCKETS * LENGTH_PAGE)/(1+LENGTH_DATA_ENTRY));
	this->dataEntry = new DataEntry*[numberOfTheDataEntry];
	this->isUse = new bool[numberOfTheDataEntry];
	this->numberOfTheDataEntryEmpty = LENGTH_BUCKETS * LENGTH_PAGE;

	//teste
	// this->teste = new string[this->numberOfTheDataEntry];

	for(int i = 0; i < this->numberOfTheDataEntry ;i++){
		isUse[i] = 0;
		dataEntry[i] = new DataEntry("$$$$$$$$");
		// teste[i] = "$$$$$$$$";
	}
	db->seekg (0,db->end);
  	this->position = db->tellg();

	db->close();
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
	// this->teste = new string[this->numberOfTheDataEntry];

	int bytesForBucket = LENGTH_BUCKETS * LENGTH_PAGE;
	char *buffer = new char[bytesForBucket];
	db->seekg(this->position,db->beg);
	db->read(buffer,bytesForBucket);
	// cout << bytesForBucket << " buffer "<< buffer<<endl;
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
		// cout << data << endl;
		this->dataEntry[i] = new DataEntry(data);
		// cout << "foi\n";
		// this->teste[i] = data;
	}
	delete buffer;
	db->close();
}

DataEntry* Bucket::findDataEntry( int key ){
	for(int i = 0 ; i < numberOfTheDataEntry; i++)
		if(dataEntry[i]->getKey() == key && isUse[i]){
			return dataEntry[i];
		}
	return new DataEntry("$$$$$$$$");
}

void Bucket::insertDataEntry(int key, set<int> *generatedRids){
	if(isFull())
		return ;
	for(int i = 0 ; i < numberOfTheDataEntry; i++)
		if(!isUse[i]){
			dataEntry[i] = new DataEntry(key,generatedRids);
			isUse[i] = true;
			numberOfTheDataEntryEmpty--;
			return;
		}
}

void Bucket::removeDataEntry(int key){
	for(int i = 0 ; i < numberOfTheDataEntry; i++)
		if(dataEntry[i]->getKey() == key){
			isUse[i] = false;
			numberOfTheDataEntryEmpty++;
		}
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
		if(isUse[i])
			buffer += dataEntry[i]->getEntry();
		else
			buffer += "$$$$$$$$";
		//teste
		// buffer += teste[i];
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

void Bucket::incrementLocalDepth(){
	localDepth++;
}

int Bucket::getPosition(){
	return position;
}

int Bucket::getLocalDepth(){
	return localDepth;
}

void Bucket::repartBucket(int indexBucket, Bucket* bucket){
	for(int i = 0; i < numberOfTheDataEntry ; i++){
		string binary = bitset<32>(dataEntry[i]->getKey()).to_string();
		string binaryG = binary.substr(32 - localDepth,32);
		int newIndexBucket = bitset<32>(binaryG).to_ulong();
		if(indexBucket != newIndexBucket){
			isUse[i] = false;
			numberOfTheDataEntryEmpty++;
			bucket->insertDataEntry(dataEntry[i]);
		}
	}
}
void Bucket::insertDataEntry(DataEntry *data){
	if(isFull())
		return ;
	for(int i = 0 ; i < numberOfTheDataEntry; i++)
		if(!isUse[i]){
			dataEntry[i] = data;
			isUse[i] = true;
			numberOfTheDataEntryEmpty--;
			return;
		}
}