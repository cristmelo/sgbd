/**
file: bucket.h
class: Bucket
author: Caio Viktor and Cristiano Melo
abstract: 
*/

class Bucket{

	int localDepth;

	int *dataEntry;

	int numberOfTheDataEntry;

public:

	Bucket findDataEntry( key );

	void insertDataEntry( key, Page.rid );

	void removeDataEntry( key, Page.rid );

}