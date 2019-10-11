#include <iostream>
#include<queue>
using namespace std;
class Car{
public:
	int x;
	int y;
	Car(int x,int y){
		this->x = x;
		this->y = y;
	}
	int distance(){
		return x*x + y*y;
	}
};
class CarCompare{
public:
	bool operator()(Car a,Car b){
			return a.distance() < b.distance();
	}
};
void kthNearest(priority_queue<Car,vector<Car>,CarCompare> p,int k){
	int count = 0;
	while(count < k){
		p.pop();
		count++;
	}
	Car temp = p.top();
	cout<<temp.distance()<<endl;
}
int main(){
	priority_queue<Car,vector<Car>,CarCompare> pq;
	long long int q;cin>>q;long long int k;cin>>k;
	for(int i = 0 ; i<q;i++){
		int type;cin>>type;
		if(type == 1){
			int x;int y;cin>>x>>y;
			Car c(x,y);
			pq.push(c);
		}
		if(type == 2){
			kthNearest(pq,k);
		}
	}
	return 0;
}