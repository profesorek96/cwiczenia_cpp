#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;


double suma3x3(double **tab){
	double suma=0;
	suma+=tab[0][0]+tab[1][1]+tab[2][2]+tab[0][2]+tab[1][1]+tab[2][0];
	return suma;
}

double sumaNxN(double **tab, int n){
	double suma=0;
	for(int i=0;i<n;i++)suma+=tab[i][i];
	int k=n-1;
	for(int i=0;i<n;i++){
		suma+=tab[k][i];
		k--;
	}
	return suma;
}


void ilo_skal(double **tab, int n, double k){
	int max=-99999999;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			tab[i][j]*=k;
			if(max<tab[i][j])max=tab[i][j];
		}
	}
	
	int ilosc=0;
	if(max<0)ilosc=1;
	while(max>0){
		max/=10;
		ilosc++;
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int ilosctmp=0;
			if(tab[i][j]<0)ilosctmp++;
			int tmp=tab[i][j];
			while(tmp>0){
				tmp/=10;
				ilosctmp++;
			}
			
			
			for(int k=0;k<=ilosc-ilosctmp;k++)cout<<" ";
			
			cout<<tab[i][j];
		}
		cout<<endl;
	}
	
}


void mnozeniemac(double **tab,int n) {
  double C[n][n]={0};
  int max=-99999999;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      for(int k = 0; k < n; k++){
      	C[i][j] = C[i][j] + tab[i][k] * tab[k][j];
      	if(max<C[i][j])max=C[i][j];
	  }
        
  int ilosc=0;
	if(max<0)ilosc=1;
	while(max>0){
		max/=10;
		ilosc++;
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int ilosctmp=0;
			if(C[i][j]<0)ilosctmp++;
			int tmp=C[i][j];
			while(tmp>0){
				tmp/=10;
				ilosctmp++;
			}
			
			
			for(int k=0;k<=ilosc-ilosctmp;k++)cout<<" ";
			
			cout<<C[i][j];
		}
		cout<<endl;
	}
        
 
 
}



int main(int argc, char** argv) {
	
	vector <double> tmpdane;
	int ilosc_elementow=0;
	
	
	fstream plik;
	plik.open("macierz.txt", ios::in | ios::out);
	if(plik.good()==true)
	{
		while( !plik.eof() )
        {
        	double tmp;
            plik>>tmp;
            
            tmpdane.push_back(tmp);

            ilosc_elementow++;
        } 
	
		plik.close();
		
		int rozmiar= sqrt(ilosc_elementow);		
		//double tab[rozmiar][rozmiar]={0};
		
		double **tab = (double**)calloc(rozmiar, sizeof(double*));
		for (int i=0;i<rozmiar;i++){
			tab[i] = (double*)calloc(rozmiar, sizeof(double));
		}
		
		int k=0;
		int maxtab=-99999999;
		for(int i=0;i<rozmiar;i++){
			for(int j=0;j<rozmiar;j++){
				tab[i][j]=tmpdane[k];
				if(maxtab<tab[i][j])maxtab=tab[i][j];
				k++;
			}
		}
			
		int ilosc=0;
		if(maxtab<0)ilosc=1;
		while(maxtab>0){
			maxtab/=10;
			ilosc++;
		}
	
		for(int i=0;i<rozmiar;i++){
			for(int j=0;j<rozmiar;j++){
				int ilosctmp=0;
				if(tab[i][j]<0)ilosctmp++;
				int tmp=tab[i][j];
				while(tmp>0){
					tmp/=10;
					ilosctmp++;
				}
			
			
				for(int k=0;k<=ilosc-ilosctmp;k++)cout<<" ";
			
				cout<<tab[i][j];
			}
		cout<<endl;
		}
		
		
		
		
		
		
			cout<<"Suma elementow na diagonali: "<<sumaNxN(tab,rozmiar)<<endl;
			cout<<"Iloczyn macierzy przez skalar: "<<endl;
			ilo_skal(tab,rozmiar,6);
			cout<<endl;
			cout<<"Iloczyn macierzy przez sama siebie:"<<endl;
			mnozeniemac(tab,rozmiar);
			
			
			
			
		for (int i=0;i<rozmiar;i++){
			free(tab[i]);
		}
		free(tab);
	}
	
	
	return 0;
}


