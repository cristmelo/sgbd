#include "../lib/main.h"

int main(){

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

		// Directory *dic = Directory::readDirectory(0,"db.dic");
		Directory *dic = new Directory(2,"db.dic");
		cout << "Diretório " << dic->position << "\nProfundidade: " << dic->globalDepth << "\nNúmero de buckets: " << dic->numberOfBuckets << "\nNúmero de Bytes: " << dic->bytes << endl;
		for(int i = 0; i < dic->numberOfBuckets; i++ )
			cout << "Bucket :" << dic->positionBucket[i] << "\tProfundidade: " << dic->localDepthBucket[i] << endl;
		file->close();
	}else{
		cout << "Erro Banco de dados não encontrado" << endl;
	}

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