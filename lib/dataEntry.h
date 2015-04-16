/**
file: dataEntry.h
class: Data Entry
author: Caio Viktor and Cristiano Melo
abstract: 
*/

class DataEntry{
	
	int key;
	
	int rid;

	bool isEmpty = true;

public:
	DataEntry(string data);
	DataEntry(int key, set<int> *generatedRids );

	int getKey();

	int getRid(); 
	string getEntry();
	
	bool itDoesntContainValue(); 

};