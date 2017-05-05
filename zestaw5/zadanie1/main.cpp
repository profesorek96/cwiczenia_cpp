#include <iostream>
#include <cmath>
using namespace std; 

class Figura {
        public:
        virtual double pole()=0; //przez to =0 masz info dla kompilatora ze funkcja bedzie w pelni wirtualna
        virtual double obwod()=0;
};

class Prostokat: public Figura{
	protected: 
	double a;
	double b;
	
	public:
	Prostokat(double A,double B) : a(A),b(B){
	}
	double pole(){
		return a*b;
	}
	double obwod(){
		return 2.0*(a+b);
	}
	
};
class Kwadrat : public Figura {
        protected:
                double a; 
        public:
                Kwadrat(double A) : a(A) {} // konstruktor wraz z list¹ inicjalizacyjn¹
                double pole() { 
                	return a*a; 
                	} 
                double obwod() { 
                	return 4.0 * a; 
                }
};
class Kolo : public Figura{
	protected:
		double r;
	public:
		Kolo(double R): r(R){}
		double pole(){
			return r*r*M_PI;
		}
		double obwod(){
			return 2*r*M_PI;
		}
};

class Figura3d : public Figura{
	public:
        virtual double pole()=0; //przez to =0 masz info dla kompilatora ze funkcja bedzie w pelni wirtualna
        virtual double obwod()=0;
        virtual double objetosc()=0;
	
};

class Szescian: public Figura3d, public Kwadrat{
	protected: //po co on jest tutaj co daje

	public:
	Szescian(double A) : Kwadrat(A){
	}
	double pole(){
		return a*a*6.0;
	}
	double obwod(){
		return -1;
	}
	double objetosc(){
		return a*a*a;
	}
	
};

class Stozek: public Figura3d,public Kolo{
	protected:
	double h;
	double l;
	public:
		Stozek(double R, double H,double L): Kolo(R),h(H),l(L){	}
		
	double pole(){
		return M_PI*r*(r+l);
	}
	double obwod(){
		return -1;
	}
	double objetosc(){
		
		return (r*r*h*M_PI)/3;
	}
};

class Prostopadloscian: public Figura3d, public Prostokat{
	protected:
		double h;
	public:
		Prostopadloscian(double A,double B, double H): Prostokat(A,B),h(H){}
	double pole(){
		return 2*a*b+2*a*h+2*b*h;
	}
	double obwod(){
		return -1;
	}
	double objetosc(){
		return a*b*h;
		
	}
		
};


int main(void) {
	///*
		Prostokat c(3,5);
		cout << "Pole prostokata: " << c.pole() << " Obwod prostokata: " << c.obwod() << endl;
        Kwadrat k(2.5);
        cout << "Pole kwadratu: " << k.pole() << " Obwod kwadratu: " << k.obwod() << endl;
        Kolo d(3);
        cout << "Pole kola: " << d.pole() << " Obwod kola: " << d.obwod() << endl;
        Szescian q(2);
        cout << "Pole szescianu: " << q.pole() << " Obwod szescianu: " << q.obwod() << " Objetosc szescianu: " << q.objetosc()  << endl;
        //*/
		Prostopadloscian f(2,5,8);
        cout << "Pole prostopadloscianu: " << f.pole() << " Obwod prostopadloscianu: " << f.obwod() << " Objetosc prostopadloscianu: " << f.objetosc()  << endl;
        //*/
		Stozek e(2,5,6);
        cout << "Pole stozka: " <<e.pole() << " Obwod stozka: " << e.obwod() << " Objetosc stozka: " << e.objetosc()  << endl;
		return 0;
}
