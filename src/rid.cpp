#include "../lib/main.h"


Rid::Rid( int numberOfThePage, int numberOfTheSlot ){

	this->numberOfThePage = numberOfThePage;

	this->numberOfTheSlot = numberOfTheSlot;

}


int Rid::getNumberOfThePage(){

	return this->numberOfThePage;

}

int Rid::getNumberOfTheSlot(){

	return this->numberOfTheSlot;

}