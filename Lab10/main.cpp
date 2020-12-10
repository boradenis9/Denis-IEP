#include <bits/stdc++.h>
using namespace std;

class pasare{
	public:
	 	virtual void zboara(int n) = 0;
	 	virtual void sunet() = 0;
};

class papagal:public pasare{
	public:
		papagal(){
		}
		void sunet(){
			cout<<"Pipiri"<<endl;
		}
		
		void zboara(int n){
			cout << "Papagalul a zburat "<<n<<" metri"<<endl; 
		}
		
		void adaugaCuvant(string cuvant){
			cuvinte.push_back(cuvant);
		}
		
		void arataVocabular(){
			
			list <string> :: iterator it; 
		    for(it = cuvinte.begin(); it != cuvinte.end(); ++it) 
		        cout << *it<<endl;
		}
	private:
		list<string> cuvinte;
		
};

class gaina:public pasare{
	public:

	gaina(){
		contor++;
		if(contor>30){
			throw logic_error("Cannot create another instance");
		}
	}
	void sunet(){
		cout << "Cotcodac"<<endl;
	}
	void zboara(int n){
		if(n>10){
			cout<<"Gaina nu poate zbura mai mult de 10 metri"<<endl;
		}
		else cout <<"Gaina a zburat "<<n<<" metri"<<endl; 
	}
	pasare* sell(pasare* a){
		return a;
	}
	static void kill(){
		contor--;
	}
	static void showContor(){
		cout<<contor<<endl;
	}
	private:
		static int contor;
};

class strut:public pasare{
	private:
		strut() {}
		static strut *instanta;
		int nrGaini;
		public:
		
	static strut *getInstanta() {
      	if (!instanta){
      		instanta = new strut;
  			instanta->nrGaini=0;
		}
      return instanta;
   }	
   strut& operator+(gaina& rhs){
   		gaina::kill();
   		nrGaini++;
   }
   void showNrGaini(){
   		cout<< nrGaini<<endl;
   }
   void sunet(){
   		cout<<"Cum o face si strutu"<<endl;
   }
   void zboara(int n){
   		cout<<"Strutii nu zboara lol"<<endl;
   }
};

int gaina::contor;
strut* strut::instanta;

int main(){
	papagal p;
	p.sunet();
	p.zboara(5);
	p.adaugaCuvant("mama");
	p.adaugaCuvant("tata");
	p.arataVocabular();
	
	gaina g= gaina();
	g.sunet();
	g.zboara(15);
	g.zboara(6);
	gaina::showContor();
	gaina g5,g6,g7,g8,g9,g10,g11,g12,g13,g14,g15,g16,g17,g18,g19,g20,g21,g22,g23,g24,g25,g26,g27,g28,g29;//,g30;
	gaina::kill();
	gaina::showContor(); //25
	
	pasare* h= new papagal();
	pasare* r= g.sell(h);
	
	r->sunet(); //r este acum un papagal.
	gaina* g1= new gaina();
	gaina* g2= new gaina();
	gaina* g3= new gaina();
	gaina* g4= new gaina();
	
	gaina::showContor(); //29
	//strut s; error, since is it singleton;
	strut* s= strut::getInstanta();
	s->sunet();
	s->zboara(6);
	*s+*g1;
	*s+*g2;
	*s+*g3;
	*s+*g4;
	
	
	s->showNrGaini();//4
	gaina::showContor();//25
	
	return 0;
}