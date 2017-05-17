#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

	
class stringiii{
	
	vector <string> wiersze;
	public:
	
	void dodaj(string Wiersz){
		wiersze.push_back(Wiersz);
		
	}
	void pokaz(){
		cout<<"Zawartosc klasy:"<<endl<<endl;
		for(int i=0;i<wiersze.size();i++)cout<<wiersze[i]<<endl;
		cout<<endl;
	}
	private:
	
	static	bool dlugosci(string a,string b){
			if(a.length()<b.length())return 1;
			else return 0;
		}
	
	public:
	
	void sortuj(){
		sort(wiersze.begin(),wiersze.end(),dlugosci);
		
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
		
		smoj.pokaz();
		smoj.sortuj();
		smoj.pokaz();
		smoj.najkrotszy();
	}
	else cout<<"Nie ma takiego pliku"<<endl;
	
	//*/
	
	return 0;
}
