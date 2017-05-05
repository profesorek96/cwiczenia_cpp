#include <iostream>
#include <cmath>
using namespace std;

class wektor{
	double x,y;
	
	public:
		
		wektor(double X,double Y) : x(X),y(Y)
		{
			
		}
		double get_x(){
			return x;
		}
		double get_y(){
			return y;
		}
		double dlugosc(){
			double l= sqrt(x*x + y*y);
			return l;
		}
		
		double il_skal(wektor v, wektor w){
			return v.x*w.x+v.y*w.y;
		}
		
		wektor il_wek(wektor v, wektor w){
			wektor a(0,0);
			a.x=v.x*w.x;
			a.y=v.y*w.y;
			return a;
		}
};

int main(int argc, char** argv) {
	
	wektor a(3,8);
	wektor b(6,2);
	wektor c(0,0);
	
	cout<<"Wektor a :"<<endl;
	cout<<"X: "<<a.get_x()<<endl;
	cout<<"Y: "<<a.get_y()<<endl;
	cout<<"Dlugosc wektora: "<<a.dlugosc()<<endl;
	cout<<endl<<endl;
	cout<<"Wektor b :"<<endl;
	cout<<"X: "<<b.get_x()<<endl;
	cout<<"Y: "<<b.get_y()<<endl;
	cout<<"Dlugosc wektora: "<<b.dlugosc()<<endl;
	cout<<endl<<endl;
	cout<<"Wektor c :"<<endl;
	cout<<"X: "<<c.get_x()<<endl;
	cout<<"Y: "<<c.get_y()<<endl;
	cout<<"Dlugosc wektora: "<<c.dlugosc()<<endl;
	cout<<endl<<endl;
	cout<<"Iloczyn skalrany wektora a z b: "<<a.il_skal(a,b)<<endl;
	c=a.il_wek(a,b);
	cout<<"Iloczyn wektorowy wektora a z b powstaje wektor c: "<<endl;
	cout<<"Wektor c :"<<endl;
	cout<<"X: "<<c.get_x()<<endl;
	cout<<"Y: "<<c.get_y()<<endl;
	cout<<"Dlugosc wektora: "<<c.dlugosc()<<endl;
	
	
	return 0;
}
