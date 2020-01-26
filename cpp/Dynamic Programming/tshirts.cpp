#include <iostream>
#include <bits/stdc++.h>
#define ll long long;
using namespace std;
// it the total no. of persons
int ALL_PERSON;
ll dp[1025][102];
vector<vector<int> >v;
// mask denotes set of people who have got hte tshirts (unique)
// tid denotes the current t-shirt we are going to give to some persong who has that tshirt in his almirah
ll f(int mask,ubt tid){
	if(mask == ALL_PERSON){
		return 1;
	}
	// all tshirts exhausted
	if(tid == 101){
		return 0;
	}
	// ignoring the current tshirts as no. of tshirts are greater than the no. of persons
	f(mask,tid+1);
	ll ans = 0;
	// giving the tshirts to some person who has that tshirt in his almirah but has not been assigned one yet
	for(int p:v[tid]){
		if(mask & (1<<p) == 1){
			ans += f(mask | (1<<p),tid+1);
		}
	}
	return ans;
}
int main(){
	v.reserve(110);
}