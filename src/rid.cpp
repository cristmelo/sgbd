#include "../lib/main.h"


Rid::Rid( int numberOfThePage, int numberOfTheSlot ){

	this->numberOfThePage = numberOfThePage;

	this->numberOfTheSlot = numberOfTheSlot;

}


int Rid::getNumberOfPage(){

	return this->numberOfThePage;

}

int Rid::getNumberOfSlot(){

	return this->numberOfTheSlot;

}