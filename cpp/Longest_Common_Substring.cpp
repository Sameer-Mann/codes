#include "bits/stdc++.h"
#define ll long long
using namespace std;
const ll mod = 1e9+7,Prime=31;
ll add(ll a,ll b){return (a+b+mod)%mod;}
ll mul(ll a,ll b){return (a*b)%mod;}
ll bpow(ll x,ll n){
    if(n==0)return 1;
    ll val = bpow(x,n/2);
    val = mul(val,val);
    return ((n&1)?mul(val,x):val);
}
set<ll> getHashes(int l,vector<int>&a){
    set<ll>s;
    ll hash=0,p=1,invp=bpow(Prime,mod-2);
    for(int i = 0;i<l;i++){
        hash = add(hash,a[i]*p);
        p = mul(p,Prime);
    }
    s.insert(hash);
    p = mul(p,invp);
    for(int i=l;i<a.size();i++){
        hash = add(hash,-a[i-l]);
        hash = mul(hash,invp);
        hash = add(hash,a[i]*p);
        s.insert(hash);
    }
    return s;
}
bool check(int l,vector<int>&a,vector<int>&b){
    set<ll>s1=getHashes(l,a),s2=getHashes(l,b);
    for(ll hash:s1){
        if(s2.count(hash))return true;
    }
    return false;
}
int longestCommonSubstring(string &s,string &t){
    int n=s.size(),m=t.size();
    vector<int>a(n,1),b(m,1);
    for(int i =0;i<n;i++)a[i] += s[i]-'a';
    for(int j = 0;j<m;j++)b[j] +=t[j]-'a';
    int l=1,r=min(n,m),ans=0;
    while(l<=r){
        int mid = (l+r)/2;
        if(check(mid,a,b)){
            ans = max(ans,mid);
            l = mid+1;
        }else r = mid-1;
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s,t;cin>>s>>t;
    cout<<longestCommonSubstring(s,t)<<"\n";
    return 0;
}