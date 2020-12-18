#include <bits/stdc++.h>
#include <math.h>
using namespace std;





class punct{
	public:
		punct(float x, float y):
			x(x),
			y(y)
		{
			
		}
		float distanta(punct b){
			return sqrt((b.x-x)*(b.x-x) + (b.y-y)*(b.y-y));
		}
		punct& operator=(punct& rhs){
			x=rhs.x;
			y=rhs.y;
			
			return *this;
		}
		void setX(const float x){
			this->x=x;
		}
		void setY(const float y){
			this->y=y;
		}
		float getX(){
			return x;
		}
		float getY(){
			return y;
		}
		void toString(){
			cout<< "x = "<< x<<",y = "<<y<<endl;
		}
	private:
		float x;
		float y;
};

class figura{
	public:
	 	virtual float perimetru() = 0;
		void toString(){
					for (auto i = puncte.begin(); i != puncte.end(); ++i)
 					i->toString();
		}
		vector<punct> getPuncte(){
			return puncte;
		}
	protected:
		vector<punct> puncte;
};

class triunghi: public figura{
	public:
		triunghi(punct a, punct b, punct c)
		{
			puncte.push_back(a);
			puncte.push_back(b);
			puncte.push_back(c);
		}
		
		float perimetru(){
			return puncte[0].distanta(puncte[1])+puncte[1].distanta(puncte[2])+puncte[2].distanta(puncte[0]);
		}
};

class tetraedru:public figura{
	public:
		tetraedru(punct a, punct b, punct c, punct d){
			puncte.push_back(a);
			puncte.push_back(b);
			puncte.push_back(c);
			puncte.push_back(d);
		}
		
		float perimetru(){
			return puncte[0].distanta(puncte[1]) + puncte[1].distanta(puncte[2]) + puncte[2].distanta(puncte[3]) + puncte[3].distanta(puncte[0]);
		}
};

class hexagon:public figura{
	public:
		hexagon(punct a, punct b, punct c, punct d, punct e, punct f){
			puncte.push_back(a);
			puncte.push_back(b);
			puncte.push_back(c);
			puncte.push_back(d);
			puncte.push_back(e);
			puncte.push_back(f);
		}
		
		float perimetru(){
			return puncte[0].distanta(puncte[1]) + puncte[1].distanta(puncte[2]) + puncte[2].distanta(puncte[3]) + puncte[3].distanta(puncte[4]) + puncte[4].distanta(puncte[5]) + puncte[5].distanta(puncte[0]);
		}
};

class cerc{
	
	private:
		cerc(punct c, float r):
		centru(c.getX(),c.getY()),
		raza(r)
		{
		}
		cerc(cerc& rhs);
		cerc& operator=(cerc& rhs);
		
		static cerc* mCerc;
		punct centru;
		float raza;
	
	public:
		
		static cerc* sCerc(punct c, float r){
			
			try{
			
				if(mCerc==0){
					mCerc= new cerc(c,r);
					return mCerc;
				}
				else throw 404;
			}
			catch(...){
				cout<<"Deja exista un cerc"<<endl;
			}
		}
		void setC(punct c){
			centru=c;
		}
		void setR(float r){
			raza=r;
		}
		punct getCentru(){
			return centru;
		}
		float getR(){
			return raza;
		}
};

cerc* cerc::mCerc=0;

template <class T, class U>

void peCerc(T a, U* b){
	
	vector<punct>g1 = a->getPuncte();
    for (auto i = g1.begin(); i != g1.end(); ++i){
 		//cout<<((i->getX()-b.getCentru().getX()) * (i->getX()-b.getCentru().getX()) + (i->getY()-b.getCentru().getY()) * (i->getY()-b.getCentru().getY()))<< " = "<<(b.getR()*b.getR()) <<endl;
        if( ((i->getX()-b->getCentru().getX()) * (i->getX()-b->getCentru().getX()) + (i->getY()-b->getCentru().getY()) * (i->getY()-b->getCentru().getY())) != (b->getR()*b->getR()) ){
        	cout<< "Nu e pe cerc"<<endl;
        	return;
		} 
	}
	
	cout<<"E pe cerc"<<endl;
}

template <class U>
float panta(U a){
	vector <punct>temp = a->getPuncte();
	return (temp[0].getY()-temp[1].getY())/(temp[0].getX()-temp[1].getX());
}


int main(){
	int input;
	float x;
	float y;
	int contorP=0;
	int contorF=0;
	int fig;
	figura* f;
	vector <punct> puncte;
	vector <figura* > figuri;
	cerc *c=0;
	do{
		cout<<"1: Adauga punct"<<endl;
		cout<<"2: Adauga figura"<<endl;
		cout<<"3: Modifica puncte"<<endl;
		cout<<"4: Afiseaza panta unei drepte dintr-o figura"<<endl;
		cout<<"5: Creeaza un cerc"<<endl;
		cout<<"6: Verifica daca o figura e pe cerc"<<endl;
		cout<<"7: Afiseaza punctele"<<endl;
		cout<<"8: Afiseaza figurile"<<endl;
		cout<<"0: Iesi din program"<<endl;
		cout<<"Alegeti o varianta:"<<endl;
		cin>>input;
		
		switch(input){
			case 1:
			{
				cout<<"Alegeti coordonatele punctului"<<endl;
				cin>> x>>y;
				punct temp(x,y);
				puncte.push_back(temp);
				contorP++;
				break;
			}
			case 2:
			{
				cout<<"Alegeti ce figura "<<endl;
				cout<<"1: Triunghi"<<endl;
				cout<<"2: Tetraedru"<<endl;
				cout<<"3: Hexagon"<<endl;
				cin>>fig;
				switch(fig){
					case 1:
					{
						cout<<"Alegeti coordonatele punctelor(2 cate 2)"<<endl;
						cin>> x>>y;
						punct temp1(x,y);
						cin>> x>>y;
						punct temp2(x,y);
						cin>> x>>y;
						punct temp3(x,y);
						f=new triunghi(temp1,temp2,temp3);
						figuri.push_back(f);
					}
						break;
					case 2:
					{	
						cout<<"Alegeti coordonatele punctelor(2 cate 2)"<<endl;
						cin>> x>>y;
						punct temp1(x,y);
						cin>> x>>y;
						punct temp2(x,y);
						cin>> x>>y;
						punct temp3(x,y);
						cin>> x>>y;
						punct temp4(x,y);
						f= new tetraedru(temp1,temp2,temp3,temp4);
						figuri.push_back(f);
						break;
					}
					case 3:
					{
						cout<<"Alegeti coordonatele punctelor(2 cate 2)"<<endl;
						cin>> x>>y;
						punct temp1(x,y);
						cin>> x>>y;
						punct temp2(x,y);
						cin>> x>>y;
						punct temp3(x,y);
						cin>> x>>y;
						punct temp4(x,y);
						cin>> x>>y;
						punct temp5(x,y);
						cin>> x>>y;
						punct temp6(x,y);
						
						f = new hexagon(temp1,temp2,temp3,temp4, temp5, temp6);
						figuri.push_back(f);
						
						break;
					}
					default:{
						cout<< "Wrong figure number"<<endl;
						contorF--;
						break;
					}
				}
				cout<<"Aceasta este figura cu nr "<<contorF<<endl;
				contorF++;
				break;
			}
			case 3:{//modifica puncte
				cout<<"Momentan exista "<<contorP<< " puncte. Introduceti indexul punctului pe care il vreti schimbat"<<endl;
				int i;
				cin>>i;
				cout<<"Introduceti noile coordonate"<<endl;
				cin>>x>>y;
				puncte[i].setX(x);
				puncte[i].setY(y);
				puncte[i].toString();
				
				break;
			}
			case 4:{//panta
				if(contorF==0){
					cout<< "Nu exista figuri"<<endl;
				}
				else{
					cout<<"Despre care figura e vorba? Se introduce indexul figurii. Momentan sunt "<<contorF<<" figuri"<<endl;
					int i;
					cin>>i;
					cout<<"Panta primei drepte din figura nr "<< i<< " este "<<panta(figuri[i])<<endl;
				}
				break;
			}
			case 5:{
				cout<<"Introduceti va rog coordonatele centrului si raza cercului"<<endl;
				float r;
				cin>>x>>y;
				cin>>r;
				punct temp(x,y);
				c= cerc::sCerc(temp, r);
				break;
			}
			case 6:
			{
				if(c==0)
				cout<<"Nu exista cerc"<<endl;
				else{
					cout<<"Care este figura pe care vrem sa o verificam? Se alege indexul figurii. Exista "<< contorF<<" figuri"<<endl;
					int i;
					cin>>i;
					peCerc(figuri[i],c);
				}
				
				break;
			}
			case 7:
			{
				for (auto i = puncte.begin(); i != puncte.end(); ++i)
 					i->toString();
				break;
			}
			case 8:{
				for(int i=0;i<contorF;i++){
					cout<< "Figura cu nr "<<i<<endl;
					figuri[i]->toString();
				}
				break;
			}
			default:
				cout<<"Wrong input"<<endl;
		}
	}while(input!=0);
	
	return 0;
}