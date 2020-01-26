#include <iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;
class compare{
public:
	bool operator()(pair<int,int> a,pair<int,int> b){
			return a.first > b.first;
	}
};
int main(){
	// int n;cin>>n;
	// cout<<n<<endl;
	// all k arrays have the size k
	priority_queue<pair<int,int> ,vector<pair<int,int> >,compare >pq;
	int a[][5]={{1,2,3,7,9},{3,5,8,9,16},{5,8,10,13,20}};
	for (int i = 0; i < 5; i++)
	{
		pq.push(make_pair(a[i][0],i));
		cout<<a[i][0]<<endl;
	}
	while(!pq.empty()){
		pair<int,int> t = pq.top();
		cout<<t.first;
		pq.pop();
	}
	cout<<endl;
	return 0;
}