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
	~Carbonara(){
		cout<<"Carbonara deleted"<<endl;
	}
	void cook(){
		cout<< "We are cooking Carbonara for "<<boilingTime <<". We are using " <<numberOfEggs<<" eggs and "<<baconQuantity<< "g of bacon. Bon apetit."<<endl;
	}
	private:
	Carbonara& operator=(const Carbonara&);
	Carbonara(const Carbonara&);	
	int numberOfEggs;
	int baconQuantity;	
};

void item13and15(){
	std::tr1::shared_ptr<Carbonara> pt1(new Carbonara(5,2,100)); // item 13 exemplified. Using smart pointer tr1::shared_ptr because its "copy-friendly".
																 // Smart pointers are more efficient with memory, because they don't leak it. They call the destructor whenever their scope it finished. 
	pt1.get()->cook(); //item 15 exemplified with memory acces using get()->cook(). We could also access every public member of Carbonara like this.
}

void item14(){
	Carbonara p1(10,5,200);
	//Carbonara p2(p1); //uncomment this line for compile error.
	//I know it's not exactly what was asked, but I went with the not copyable one. Examples in the course book where too specific for me to recreate in an another example.
	//I didn't know how to form another example. It's kinda like ITEM 6 all over again.
}

int main(){
	item13and15();
	item14();
	return 0;
}