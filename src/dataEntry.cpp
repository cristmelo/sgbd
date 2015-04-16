
#include "../lib/main.h"

bool DataEntry::itDoesntContainValue(){

    return isEmpty;

}


DataEntry::DataEntry( string data ){

    if( data != "$$$$$$$$"){
        
        key = stoi( data.substr ( 0 , LENGTH_ID_BUCKET ) );

        rid = stoi( data.substr ( LENGTH_ID_BUCKET , data.length()) );

        isEmpty = false;
    }

}

DataEntry::DataEntry( int key, set<int> *generatedRids ){
    
            if( key > 0 && key < 9999 ){
                    
                    this->key = key;

            }else{

                cout << "This number is out of range\nPlease insert a number between 0 and 10000" << endl;

            }

            bool verify = false;

            do{
                    

                    int number;

                    srand ( time (NULL) );
                    number = 1000 + rand()%8999;
                    

                    if( number > 999 && number < 9999 && !generatedRids->count(number) ){

                        verify = true;
                        this->rid = number;
                        generatedRids->insert(number);

                    }

                        
            }while( verify == false );

            isEmpty = false;

}
           
int DataEntry::getKey(){
    if(isEmpty)
        return -999999999;
    return this->key;
    
}

int DataEntry::getRid(){
    if(isEmpty)
        return -999999999;
    return this->rid;
    
}           

string DataEntry::getEntry(){
  
  if(isEmpty)  
    return "$$$$$$$$";
  
  string keyString, ridString;
    

  keyString = stringNBytes( key, LENGTH_ID_BUCKET );
  ridString = stringNBytes( rid, LENGTH_ID_BUCKET );
    
  return keyString+ridString;
    
}

