#include "../lib/main.h"

DataEntry::DataEntry( string data ){

	//TODO

}

DataEntry::DataEntry( int key ){
    
            if( key > 999 && key < 9999 ){

                        this->key = key;

            }else{

                cout << "This number is out of range\nPlease insert a number between 999 and 9999" << endl;

            }

            bool verify = false;

            do{
        
                    int number;
         
                    srand ( time (NULL) );
                    number = 1000 + rand()%9999;
        
                    if( number > 999 && number < 9999 ){

                        verify = true;
                        this->rid = number;

                    }
                        
            }while( verify == false );

}


DataEntry::DataEntry( string data ){

}    
           
int DataEntry::getKey(){
    
    return this->key;
    
}

int DataEntry::getRid(){
    
    return this->rid;
    
}           

string DataEntry::getEntry(){
    
    std::stringstream keyString, ridString;
    
    keyString << getKey();
    ridString << getRid();
    
    return keyString.str()+ridString.str();
    
}

