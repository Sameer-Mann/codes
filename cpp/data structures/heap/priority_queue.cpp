#include <iostream>
#include<queue>
using namespace std;
class Car{
public:
	int x;
	int y;
	int id;
	Car(int id,int x,int y){
		this->x = x;
		this->y = y;
		this->id = id;
	}
	int distance(){
		// we have not taken square root as we are going
		// to use this distance only for comparison
		return x*x + y*y;
	}
	void print(){
		cout<<"ID :"<<id;
		cout<<"Location : "<<x<<", "<<y<<endl;
	}
};
// here carcompare is a functor
class CarCompare{
public:
	// method to overload () operator
	bool operator()(Car a,Car b){
			return a.distance() > b.distance();
	}
};
int main(){
	// it creates a max heap
	// priority_queue<int> pq; 
	// here we have considered origin as the center and measuring all distances from it
	// priority_queue<int,vector<int>,greater<int> > pq;
	priority_queue<Car,vector<Car>,CarCompare> pq;
	int x[10] = {5,-6,7,8,9,11,12,-10,-2,-1};
	int y[10] = {2,4,9,20,-1,-7,11,5,0,8};
	for (int i = 0; i < 10; ++i)
	{
		Car c(i,x[i],y[i]);
		pq.push(c);
	}
	int pops = 0;                         
	while(!pq.empty() && pops < 3){
		Car p = pq.top();
		p.print();
		pq.pop();
		pops++;
	}
	return 0;
}