/**
file: dataEntry.h
class: Data Entry
author: Caio Viktor and Cristiano Melo
abstract: 
*/

class DataEntry{
	
	int key;
	
	int rid;

	string entry;

public:
	DataEntry(string data);
	DataEntry(int key);

	int getKey();

	int getRid(); 
	string getEntry();
	
};