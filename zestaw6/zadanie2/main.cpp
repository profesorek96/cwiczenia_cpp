#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

class stringiii{
	public:
	vector <string> wiersze;
	
	
	void dodaj(string Wiersz){
		wiersze.push_back(Wiersz);
		
	}
	void pokarz(){
		cout<<"Zawartosc klasy:"<<endl<<endl;
		for(int i=0;i<wiersze.size();i++)cout<<wiersze[i]<<endl;
		cout<<endl;
	}
	
	void sortuj(){
		sort(wiersze.begin(),wiersze.end());
		
	}
	void najkrotszy(){
		
		sortuj();
		cout<<"Najkrotszy wyraz: ";
		if(wiersze.size()>0)cout<<wiersze[0]<<endl;
		
		else cout<<"Nie istnieje"<<endl;
		
	}
};



int main(int argc, char** argv) {
	stringiii smoj;
	///*
	fstream plik;
	plik.open("tekst.txt", ios::in | ios::out);
	if(plik.good()==true){
		while(!plik.eof()){
			string wiersz;
			//plik>>wiersz;
			getline(plik,wiersz);
			smoj.dodaj(wiersz);
		}
		
		plik.close();
		
		smoj.pokarz();
		smoj.sortuj();
		smoj.pokarz();
		smoj.najkrotszy();
	}
	else cout<<"Nie ma takiego pliku"<<endl;
	
	//*/
	
	return 0;
}
