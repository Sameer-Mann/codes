#include <iostream>
#include<unordered_map>
#include<queue>
using namespace std;
class custom{
public:
	int data;
	unordered_map<int,int>m;
	custom(int data,unordered_map<int,int>mp){
		this->data = data;
		m = mp;
	}
	int frequency(int a){
		return m[a];
	}
}
class compare{
public:
	void operator()(custom a,custom b){
		return b.frequency(a.data) < b.frequency(b.data);
	}
}
void print_heap(priority_queue<int,vector<int>,compare> p){
	while(!p.empty()){
		cout<<p.top()->data<<" ";
		p.pop()
	}
}
int main(){
	// int a[10] = {1,1,1,2,4,4,9,9,9,10};
	int t;cin>>t;
	while(t--){
		int n;int k;cin>>n>>k;
		unordered_map<int,int>freq;
		priority_queue<custom,vector<custom>,compare> pq;
		for(int i=0;i<n;i++){
			int temp;cin>>temp;
			freq[temp]++;
			if(count < k){
				pq.push(new custom(temp,mp));
				print_heap(pq)
			} else {
				int tp = pq.top();
				if(temp > tp){
					pq.pop();
					pq.push(new custom(temp,mp));
					print_heap(pq);
				}
			}
		}
	}
	for(int i=0;i<10;i++){
		freq[a[i]]++;
	}
	for(auto i:freq){
		cout<<i.first<<" "<<i.second<<endl;
	}
	return 0;
}