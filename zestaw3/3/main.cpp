#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

double suma_tab(double *tab,int n){
	double sum=0;
	for(int i=0;i<n;i++)sum=sum+tab[i];
	return sum;
}

double srednia_arytmetyczna(double *tab, int n){
	return suma_tab(tab,n)/n;
}

double srednia_geometryczna(double *tab, double n){
	double licz=1;
	for(int i=0;i<n;i++)licz=licz*tab[i];
	return pow(licz,1/n);
}

double mediana (double *tab,int n){
	sort(tab,tab+n);
	if(n%2==1)return tab[n/2];
	else return (tab[(n-1)/2]+tab[n/2])/2;
}

int main(int argc, char** argv) {
	
	vector <double> tmpdane;
	int ilosc_elementow=0;
	
	fstream plik;
	
	plik.open("liczby.txt",ios::in| ios::out);
	if(plik.good()==true){
        while( !plik.eof() )
        {
        	double tmp;
            plik>>tmp;
            
            tmpdane.push_back(tmp);

            ilosc_elementow++;
        } 
	
		plik.close();
		
		double tab[ilosc_elementow]= {0};
		for(int i=0;i<tmpdane.size();i++)tab[i]=tmpdane[i];
		
		for(int i=0;i<ilosc_elementow;i++)cout<<tab[i]<<" ";
		cout<<endl;
		cout<<"Suma elementow: "<<suma_tab(tab,ilosc_elementow)<<endl;
		cout<<"Srednia arytmetyczna: "<<srednia_arytmetyczna(tab,ilosc_elementow)<<endl;
		cout<<"Srednia geometryczna: "<<srednia_geometryczna(tab,ilosc_elementow)<<endl;
		cout<<"Mediana: "<<mediana(tab,ilosc_elementow)<<endl;
		
	}
	
	
	
	
	return 0;
}
