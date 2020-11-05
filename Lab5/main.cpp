#include <bits/stdc++.h>
using namespace std;

class Pasta{
	public:
	Pasta(const int& boilingTime)
		:boilingTime(boilingTime)
		{
		}
	Pasta(const Pasta& rhs)
	:boilingTime(rhs.boilingTime)
		{
		}	
	
	virtual void cook(){
	};
	virtual ~Pasta(){
	}

	Pasta& operator=(const Pasta& rhs){
		int *original;
		original=&boilingTime;
		boilingTime=rhs.boilingTime;
		delete original;
		
		return *this;
	}
	protected:
		int boilingTime;
		
};

class Carbonara:public Pasta{
	public:
	Carbonara(const int& boilingTime, const int& numberOfEggs, const int& baconQuantity)
	:Pasta(boilingTime),
	 numberOfEggs(numberOfEggs),
	 baconQuantity(baconQuantity)
	 {
	 }
	 
	Carbonara(const Carbonara& rhs)
	:Pasta(rhs),
	 numberOfEggs(rhs.numberOfEggs),
	 baconQuantity(rhs.baconQuantity)
	{	
	} 
	~Carbonara(){
		cout<<"Carbonara deleted"<<endl;
	}
	Carbonara& operator=(const Carbonara& rhs){
		Pasta::operator=(rhs);
		
		numberOfEggs=rhs.numberOfEggs;
		baconQuantity=rhs.baconQuantity;
		return *this;
	}
	void cook(){
		cout<< "We are cooking Carbonara for "<<boilingTime <<". We are using " <<numberOfEggs<<" eggs and "<<baconQuantity<< "g of bacon. Bon apetit."<<endl;
	}
	private:
	int numberOfEggs;
	int baconQuantity;	
};


int main(){
	Carbonara *a1=new Carbonara(5,2,200);
	Pasta *a2;
	a2=a1;
	delete a2; //Item 7 respected.
	Carbonara a3(10,3,100);
	a3.cook();
	Carbonara a4(a3);
	a4.cook();
	Carbonara a5=a4;
	a5.cook();
	return 0;
}