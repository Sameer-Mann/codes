#include<iostream>
using namespace std;
class Car {
private:
	int price;
// is a access modifier
public:
	// const functions do not update the data members of the class
	int model_no;
	char *name;
	// if there is a const member it must be intilised in an intilisation list
	// all other members can be assigned directly in the costructor
	const int tyres;
	// this : operator is used to initialise the members
	Car():name(NULL),tyres(4){
		cout<<"Making a Car.."<<endl;
		// tyres = 4;// assignment
	}
	// parameterised constructor
	// here we have done initiallisation list
	Car(int p,int mn,char *n,int t=4):price(p),model_no(mn),tyres(t){
		name = new char[strlen(n)+1];
		strcpy(name,n);
	}
	//deep copy constructor
	Car(Car &X):tyres(X.tyres){
		price = X.price;
		model_no = X.model_no;
		int l = strlen(X.name);
		name = new char[l+1];
		strcpy(name,X.name);
	}
	void operator = (const Car &X){
		cout<<"in copy assignment operator"<<endl;
		price = X.price;
		model_no = X.model_no;
		int l = strlen(X.name);
		name = new char[l+1];
		strcpy(name,X.name);
	}
	void setName(const char *n){
		if(name == NULL){
			name = new char[strlen(n)+1];
			strcpy(name,n);
		}else{

		}
	}
	void start() const{
		cout<<"starting....... "<<name<<endl;
	}
	void setPrice(const int p){
		if(p>1000){
			price = p;
		}else{
			price = 1000;
		}
		price = p;
	}
	void print() const{
		cout<<name<<endl;
		cout<<model_no<<endl;
		cout<<price<<endl<<endl;
	}
	int getPrice() const{
		return price;
	}
	~Car(){
		cout<<"Destroying the carr "<<name<<endl;
		// code to delete all dynamic members
		if(name != NULL){
			delete [] name;
		}
	}
};
int main(){
	Car C;
	C.setPrice(1500);
	C.setName("Nano");
	C.model_no = 1001;
	//C.start();
	C.print();
	cout<<C.tyres<<endl;
	Car D(100,200,"BMW");
	Car E(200,400,"Audi");
	D=E;
	D.name[0] = 'O';
	D.print();
	E.print();
	Car *DC = new Car(100,200,"Dynamic Tesla Car");
	delete DC;
	return 0;
}