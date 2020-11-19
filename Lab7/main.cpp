#include <bits/stdc++.h>
#include <tr1/memory>
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
	
	virtual ~Pasta(){
	}
	void boil() const{
		cout<<"Pasta is boiled for "<<boilingTime<< " minutes."<<endl;
	}
	Pasta& operator=(const Pasta& rhs){
		int *original;
		original=&boilingTime;
		boilingTime=rhs.boilingTime;
		delete original;
		
		return *this;
	}
	int getBoilingTime(){
		return boilingTime;
	}
	private:		//item 22, declare every member private.
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
	~Carbonara(){
		cout<<"Carbonara deleted"<<endl;
	}
	void addEggs() const{
		cout<< numberOfEggs<< " eggs were added"<<endl;
	}
	void addBacon() const{
		cout<< baconQuantity<< "g of bacon was added"<<endl;
	}
	int getNumberOfEggs(){
		return numberOfEggs;
	}
	int getbaconQuantity(){
		return baconQuantity;
	}
	private:
	Carbonara& operator=(const Carbonara&);
	Carbonara(const Carbonara&);	
	int numberOfEggs; //item 22, declare every member private.
	int baconQuantity;	//item 22, declare every member private.
};

void cook(const Carbonara& cb /*Item 20 respected here(pass by const reference)*/ ){ //item 23 respected (non member, non friends function)
	cb.boil();
	cb.addEggs();
	cb.addBacon();	
}
int main(){
	const Carbonara c1(10,5,200);
	cook(c1);
	return 0;
}