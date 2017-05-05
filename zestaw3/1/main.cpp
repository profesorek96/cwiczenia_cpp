#include <iostream>
#include <cmath>
using namespace std;

double pierw(double liczba){
	if(liczba>=0)return sqrt(liczba);
	else return -1./0;
}
double pierw(double liczba, double n){
	if(liczba>=0)return pow(liczba, 1/n);
	else if(liczba<0&&(int)n%2==1)return (-1)*pow(((-1)*liczba), 1/n);
	else return -1./0;
}

int main() {
	cout<<"Pierwiastek 2 stopnia"<<endl;
	for(double i=1;i<=5;i++)cout<<i<<" "<<pierw(i)<<endl;
	cout<<endl<<endl;
	cout<<"Pierwiastek 3 stopnia"<<endl;
	for(double i=1;i<=5;i++)cout<<i<<" "<<pierw(i,3)<<endl;
	
	
	
	return 0;
}
