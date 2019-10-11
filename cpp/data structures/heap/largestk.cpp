#include <iostream>
#include<queue>
using namespace std;
int main(){
	priority_queue<int ,vector<int>,greater<int> > pq;
	int k;cin>>k;
	int input;int count=0;
	cin>>input;
	while(input != -1){
		if(count < k){
			pq.push(input);
			count++;
		} else {
			int tp = pq.top();
			if(input > tp){
				pq.pop();
				pq.push(input);
			}
		}
		cin>>input;
	}
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	return 0;
}