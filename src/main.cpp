#include "../lib/main.h"



int main(){

	set<int> *generatedRids = new set<int> ();

	// Database db("db");

	// db.close();
	
	fstream *file = new fstream("db.db", ios::in | ios::out );
	if(*file){
		file->seekg (0, file->beg);
		// cout << "Banco de dados aberto com sucesso\n";
		// Bucket *bucket = new Bucket("db.db",0,2);
		// cout << "bucket\nslots: " << bucket->numberOfTheDataEntry <<"\nVazios: "<< bucket->numberOfTheDataEntryEmpty <<"\nposition: " << bucket->position << "\nnivel: " << bucket->localDepth << endl;
		// for(int i = 0 ; i < bucket->numberOfTheDataEntry ; i++)
		// 	cout << bucket->isUse[i] << endl;
		// cout << "Entradas de dados:\n";
		// for(int i = 0 ; i < bucket->numberOfTheDataEntry ; i++)
		// 	cout << "entrada: " << i<< " Valor:" << bucket->teste[i] << endl;
		// bucket->write();


		// Bucket *novo = new Bucket("db.db",2);
		// cout << "novo\nslots: " << novo->numberOfTheDataEntry <<"\nVazios: "<< novo->numberOfTheDataEntryEmpty <<"\nposition: " << novo->position << "\nnivel: " << novo->localDepth << endl;
		// for(int i = 0 ; i < novo->numberOfTheDataEntry ; i++)
		// 	cout << novo->isUse[i] << endl;
		// novo->write();

		// Bucket *bucket2 = new Bucket("db.db",256,2);
		// cout << "bucket2\nslots: " << bucket2->numberOfTheDataEntry <<"\nVazios: "<< bucket2->numberOfTheDataEntryEmpty <<"\nposition: " << bucket2->position << "\nnivel: " << bucket2->localDepth << endl;
		// for(int i = 0 ; i < bucket2->numberOfTheDataEntry ; i++)
		// 	cout << bucket2->isUse[i] << endl;
		// cout << "Entradas de dados:\n";
		// for(int i = 0 ; i < bucket2->numberOfTheDataEntry ; i++)
		// 	cout << "entrada: " << i << " Valor:" << bucket2->teste[i] << endl;

		Directory *dic = Directory::readDirectory(0,"db.dic"); // ler
		// // Directory *dic = new Directory(2,"db.dic"); // cria
		dic->findBucket(0);
		dic->findBucket(1);
		dic->findBucket(2);
		dic->findBucket(3);
		dic->findBucket(4);
		// cout << "Diretório " << dic->position << "\nProfundidade: " << dic->globalDepth << "\nNúmero de buckets: " << dic->numberOfBuckets << "\nNúmero de Bytes: " << dic->bytes << endl;
		// for(int i = 0; i < dic->numberOfBuckets; i++ )
		// 	cout << "Bucket :" << dic->positionBucket[i] << "\tProfundidade: " << dic->localDepthBucket[i] << endl;
		// dic->write();
		// file->close();
	}else{
		cout << "Erro Banco de dados não encontrado" << endl;
	}

	//DataEntry *data = new DataEntry(23);
	DataEntry *data = new DataEntry(1, generatedRids);
	
	cout << generatedRids->count(1000) << endl;

	//cout << data->getKey()<<endl<<data->getRid()<<endl<<data->getEntry() << endl;
	return 0;

}
string stringNBytes(int num, int bytes){
	string numS = to_string(num);
	int addDigit = bytes - numS.length();
	string r = "";
	for(int i = 0 ; i < addDigit ; i++)
		r+="0";
	r+=numS;
	return r;
}
