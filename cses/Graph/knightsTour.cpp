#include <bits/stdc++.h>
using namespace std;
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {return os << P.first << " " << P.second;}
template<class T> ostream& operator<<(ostream &os, vector<T> V) {for(auto v : V) os << v << " ";return os<<"";}
template<class T> ostream& operator<<(ostream &os, set<T> S){os << "{ ";for(auto s:S) os<<s<<" ";return os<<"}";}
template<class T> ostream& operator<<(ostream &os, unordered_set<T> S){os << "{ ";for(auto s:S) os<<s<<" ";return os<<"}";}
template<class T> ostream& operator<<(ostream &os, multiset<T> S){os << "{ ";for(auto s:S) os<<s<<" ";return os<<"}";}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {os << "{ ";for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";return os<<"}";}
template<class L, class R> ostream& operator<<(ostream &os, unordered_map<L,R> M) {os << "{ ";for(auto m:M) os<<"("<<m.fi<<":"<<m.se<<") ";return os<<"}";}
template<typename T>
void print(T t){cout<<(t);cout<<'\n';}
template<typename T, typename... Args>
void print(T t, Args... args){cout << (t) <<' ';print(args...);}
int n,m;
int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 }; 
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 }; 
int ans[8][8];
bool check(int i,int j){
    return i >= 0 and i < 8 and j >= 0 and j < 8 and ans[i][j]==-1;
}
vector<pair<int,int>>nbrs(int x,int y){
    vector<pair<int,int>>a;
    for (int i = 0; i < 8; ++i)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(check(nx,ny)){
            a.push_back(make_pair(nx,ny));
        }
    }
    return a;
}
int helper1(pair<int,int>&x){
    int ct=0;
    for (int i = 0; i < 8; ++i)
    {
        int nx=x.first+dx[i],ny=x.second+dy[i];
        if(check(nx,ny))
            ct++;
    }
    return ct;
}
int helper(pair<int,int>&x,pair<int,int>&y){
    
    return helper1(x)<helper1(y);
}
pair<int,int>get(int i,int j){
    auto a = nbrs(i,j);
    sort(a.begin(), a.end(),helper);
    return a[0];
}
void f(int i,int j,int move){
    ans[i][j]=move;
    if(move == 64)return;
    pair<int,int>t = get(i,j);
    f(t.first,t.second,move+1);
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>m>>n;
    n--,m--;
    memset(ans,-1,sizeof(ans));
    f(n,m,1);
    for (int i = 0; i < 8; ++i)
    {
        for(int j=0;j<8;j++)cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}