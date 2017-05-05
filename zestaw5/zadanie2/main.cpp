#include <iostream>
using namespace std;

class dana{
	protected:
	double x;
	public:
	dana(double X):x(X){}
	virtual string zacheta()=0;	
	virtual double get()=0;
	virtual void set(double A)=0;
	virtual int isvalid(double A)=0;
};


class bok:public dana{
	
	public:	
	bok(double X):dana(X){}
	
	string zacheta(){
		return "Podaj wartosc: ";
	}	
	double get(){
		return x;
	}
	void set(double A){
		x=A;
	}
	int isvalid(double A){
		if(A>0)return 1;
		else return 0;
	}
};


class kat:public dana{
	
	public:	
	kat(double X):dana(X){}
	
	string zacheta(){
		return "Podaj wartosc: ";
	}	
	double get(){
		return x;
	}
	void set(double A){
		x=A;
	}
	int isvalid(double A){
		if(A>0&&A<360)return 1;
		else return 0;
	}
};

int main(int argc, char** argv) {
	bok a(0);
	kat alfa(0);
	double i;
	
	cout<<"BOK "<<endl;
	cout<<"Poczatkowa wartosc: "<<a.get()<<endl;
	cout<<a.zacheta();
	cin>>i;
	if(a.isvalid(i)==1){
		a.set(i);
		cout<<"Wprowadzono poprawna wartosc rowna: "<<a.get()<<endl;
	}
	else cout<<"Wprowadzono bledna wartosc!!!"<<endl;
	cout<<endl<<endl;
	
	cout<<"KAT "<<endl;
	cout<<"Poczatkowa wartosc: "<<alfa.get()<<endl;
	cout<<alfa.zacheta();
	cin>>i;
	if(alfa.isvalid(i)==1){
		alfa.set(i);
		cout<<"Wprowadzono poprawna wartosc rowna: "<<alfa.get()<<endl;
	}
	else cout<<"Wprowadzono bledna wartosc!!!"<<endl;
	cout<<endl<<endl;
	
	return 0;
}
