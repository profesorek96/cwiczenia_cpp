#include <iostream>
#include <cmath>
using namespace std;

class Wektor{
	public:
	double x;
	double y;
};

class Punkt{
	
	double x;
	double y;
	
	
	
//czy da sei zwrocic obiekt jak bym chcia³ go przekazac z metody i jak to wyglada
	public:

	Punkt(){
		x=0;
		y=0;
	}
	
    void wpisz( double mojeX, double mojeY )
    {
    	x=mojeX;
    	y=mojeY;
    }
    void wypisz(){
    	cout<<"X: "<<x<<endl;
    	cout<<"Y: "<<y<<endl;
    }
    double wypisz_x(){
    	return x;
    }
    double wypisz_y(){
    	return y;
    }
    double odleglosc(Punkt p){
    		return sqrt((p.x-x)*(p.x-x)+(p.y-y)*(p.y-y));
    		//czemu moge sie odwolac mimo ze x jest prywatny?
    }
    void przesuniecie(Wektor k){
    	x=x+k.x;
    	y=y+k.y;
    }
    
    void obrot_kat(double alfa){
    	//http://matematyka.pisz.pl/strona/898.html
    	x=x*cos(alfa)-y*sin(alfa);
    	y=x*sin(alfa)+y*cos(alfa);
    }
    
};

class okrag{
	Punkt s;
	
	double r;
	
	public:
	
	okrag(){
		s.wpisz(0,0);
		r=0;
	}
	
	void wpisz(double x,double y, double R){
		s.wpisz(x,y);
		r=R;
	}
	void wypisz(){
		cout<<"Wspolzedne srodka: X:"<<s.wypisz_x()<<" Y:"<<s.wypisz_y()<<endl;
		cout<<"Dlugosc promiewnia: "<<r<<endl;
	}
	
	double pole(){
		return (3.14*r*r);
	}
	
	void wspolne(okrag a){
		//http://matematyka.pisz.pl/strona/473.html
		
		if(s.odleglosc(a.s)>r+a.r)cout<<"Okregi rozlaczne zewnetrznie"<<endl;
		else if(s.odleglosc(a.s)==r+a.r)cout<<"Okregi styczne zewnetrznie"<<endl;
		else if(abs(r-a.r)<s.odleglosc(a.s)&&s.odleglosc(a.s)<r+a.r)cout<<"Okregi przecinaja sie"<<endl;
		else if(s.odleglosc(a.s)==abs(r-a.r))cout<<"Okregi styczne wewnetrznie"<<endl;
		else if(s.odleglosc(a.s)<abs(r-a.r))cout<<"Okregi rozlaczne wewnetrznie"<<endl;
		else cout<<"Okregi wspolsrodkowe"<<endl;
	}
	
	
};



int main() {
	///*
	cout<<"zadanie 1"<<endl;
	Punkt A;
	Punkt B;
	Wektor k;
	
	A.wpisz(0,5);
	A.wypisz();
	
	B.wpisz(9,5);
	B.wypisz();
	cout<<"Odleglosc wynosi: "<<A.odleglosc(B)<<endl;
	
	k.x=5;
	k.y=6;
	
	A.przesuniecie(k);
	A.wypisz();
	
	
	A.obrot_kat(5);
	A.wypisz();
	 
	
	//*/
	cout<<endl<<endl;
	cout<<"zadanie 2"<<endl;
	
	okrag C;
	okrag D;
	
	C.wpisz(5,8,6);
	C.wypisz();
	cout<<"Pole wynosi:"<<C.pole()<<endl;
	
	D.wpisz(5,8,6);
	D.wypisz();
	cout<<"Pole wynosi:"<<D.pole()<<endl;
	
	C.wspolne(D);
	
	return 0;
}