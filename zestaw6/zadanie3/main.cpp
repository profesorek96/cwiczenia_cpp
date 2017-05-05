#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main(int argc, char** argv) {
	
	map<string, int> imiona;
	
	fstream plik;
	plik.open("imiona.txt", ios::in | ios::out);
	if(plik.good()==true){
		while(!plik.eof()){
			string imie;
			plik>>imie;
			if(imiona.count(imie)==true){
				imiona[imie]++;
			}			
			else {
				imiona[imie]=1;
			}
		}
		plik.close();
	}
	
	cout<<"Statystyka imion zczytanych z pliku"<<endl;
	
	typedef map<string, int>::iterator MapIterator;
		for(MapIterator it=imiona.begin(); it!=imiona.end(); ++it)
	{	
    	cout<<"Imie: "<<it->first<<": "<<it->second<<std::endl;
	}
	
	
	
	return 0;
}
