/**
file: dataEntry.h
class: Data Entry
author: Caio Viktor and Cristiano Melo
abstract: 
*/

class DataEntry{
	
	int key;
	
	Rid *rid;


public:

	DataEntry(int key, Rid *rid);

	int getKey();

	Rid* getRid(); 
	
};