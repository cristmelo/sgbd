#include "../lib/main.h"
Database::Database(string path){
	generatedRids = new set<int> ();
	dbName = path + ".db";
	dicName = path + ".dic";
	fstream *file = new fstream(dbName.c_str(), ios::in | ios::out );
	fstream *dic = new fstream(dicName.c_str(),ios::in | ios::out);
	if(*file && *dic){
		file->seekg (0, file->beg);
		this->DB = file;
		dic->seekg(0,file->beg);
		this->Dic = dic;

		cout << "Banco de dados aberto com sucesso\n";
	}else{
		cout << "Erro Banco de dados não encontrado" << endl;
	}

}

int Database::search(int key){	

	Directory *dic = Directory::readDirectory(0, dicName);

	int *result = dic->findBucket( key );

	Bucket *buc = new Bucket( dbName, result[0], result[1] );

	return	buc->findDataEntry( key )->getRid();
}

void Database::insert(int key){
	// cout << "1" << endl;
	int numBucket;
	Directory *dic = Directory::readDirectory(0, dicName);
	// cout << "2" << endl;
	int *result = dic->findBucket(key); //result[0] = positionBucket[bucket];result[1] = localDepthBucket[bucket];result[2] = bucket;
	// cout << "3 " << dbName << endl;
	Bucket *buc = new Bucket(dbName, result[0], result[1]);
	numBucket = result[2];
	// cout << "4" << endl;
	if(!buc->isFull()){
		buc->insertDataEntry(key,generatedRids);
	}else{
		Bucket *newBucket = new Bucket(dbName,buc->getLocalDepth());
		buc->incrementLocalDepth();
		newBucket->incrementLocalDepth();
		if(dic->getGlobalDepth() == buc->getLocalDepth()){
			dic->updateReference(result[2] , buc->getPosition(), buc->getLocalDepth());
			dic->updateReference(result[2] + pow(2,result[1]) , newBucket->getPosition(), newBucket->getLocalDepth());

		}else if(dic->getGlobalDepth() < buc->getLocalDepth()){
			dic->duplicate(newBucket->getPosition(), result[2] );	
		}
		buc->repartBucket(result[2] ,newBucket);
		delete result;
		result = dic->findBucket(key);
		if(buc->getPosition() == result[0])
			buc->insertDataEntry(key,generatedRids);
		else
			newBucket->insertDataEntry(key,generatedRids);
		numBucket = result[2];
		newBucket->write();
	}
	// cout << "5" << endl;
	buc->write();
	// cout << "6" << endl;
	dic->write();
	cout << "Inserção com sucesso no Bucket "<< numBucket <<"!\n";
}

bool Database::remove(int key){
	Directory *dic = Directory::readDirectory(0, dicName);

	int *result = dic->findBucket( key );

	Bucket *buc = new Bucket( dbName, result[0], result[1] );

	buc->removeDataEntry( key );	
	buc->write();
	dic->write();
	cout << "Remoção com sucesso!\n";
}


bool Database::close(){
	if(*(this->DB)){
		// salvar tudo da memória
		// DB->seekg(1,DB->beg);
		// char *buffer = new char[2];
		// DB->read(buffer,2);
		// cout << buffer <<endl;

		DB->close();
		Dic->close();
		delete generatedRids;
		cout << "banco de dados fechado com sucesso\n";
	}
	else
		cout << "Nenhum Banco de dados aberto\n";
}
void Database::create(){
	Directory *dic = new Directory( 2, dicName );
	dic->write();
	Bucket *buc0 = new Bucket(dbName,2);
	buc0->write();
	Bucket *buc1 = new Bucket(dbName,2);
	buc1->write();
	Bucket *buc2 = new Bucket(dbName,2);
	buc2->write();
	Bucket *buc3 = new Bucket(dbName,2);
	buc3->write();


}
void Database::status(){
	Directory *dic = Directory::readDirectory(0, dicName);
	cout << "Nome do banco: " << dbName << "\tNome Diretório: " << dicName <<"\t Profundidade Global: " << dic->getGlobalDepth() << "\nNúmero de Buckets: " << dic->getNumberBuckets()<<endl;
}