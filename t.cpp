#pragma GCC optimize("Ofast") 
#pragma GCC target("avx,avx2,fma")
#include "bits/stdc++.h"
#define int long long
#define fi first
#define se second
#define pb push_back
#define se second
#define vi vector<int>
#define vvi vector<vi>
#define len(x) (int)x.size()
#define pi pair<int,int>
#define vpi vector<pi>
#define maxheap priority_queue<int>
#define minheap priority_queue<int,vi,greater<int>>
#define bits(x) __builtin_popcount(x)
#define fixed(x) cout<<fixed<<setprecision(x);
using namespace std;
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {return os << "(" << P.first << "," << P.second << ")";}
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
const int MOD = 998244353;
const int N = 2e5+1;
// const int MOD = 7340033;
const int root = 363395222;
const int root_1 = 704923114;
const int root_pw = 1 << 19;
int A[N],ans[N];
int bpow(int x,int n){
    if(n==1)return x;
    int v = bpow(x,n/2);
    v = (v*v)%MOD;
    return (n&1?(x*v)%MOD:v);
}
inline int add(int x,int y){return (x+y)%MOD;}
inline int mul(int x,int y){return (x*y)%MOD;}
int modinv(int x){return bpow(x,MOD-2);}
void ntt(int a[],int n, bool invert=0)
{
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1){
            j ^= bit;
        }
        j ^= bit;
        if (i < j){
            swap(a[i], a[j]);
        }
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1){
            wlen = (1LL * wlen * wlen % MOD);
        }
        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (1LL * a[i+j+len/2] * w % MOD);
                a[i+j] = (u + v < MOD) ? u + v : u + v - MOD;
                a[i+j+len/2] = (u - v >= 0) ? u - v : u - v + MOD;
                w = (1LL * w * wlen % MOD);
            }
        }
    }
    if (invert) {
        int n_1 = modinv(n);
        for(int i=0;i<n;i++)
            a[i] = (1LL * a[i] * n_1 % MOD);
    }
}
void calc1(int b[],int n){
    int num=1,den=1;
    b[0]=1;
    int mid = (n+1)/2;
    for(int i=0;i<mid;i++){
        num = mul(num,n-i);
        den = mul(den,i+1);
        b[i+1] = mul(num,modinv(den))%MOD;
    }
}
void print1(int a[],int n){
    for(int i=1;i<n and a[i]>0;i++)cout<<a[i]<<' ';
    cout<<endl;
}
void mul1(int a[],int b[],int n1,int n2){
    int n = n1 + n2 - 1, i;
    int m = 1; while(m<n) m<<=1;
    for(i=n1;i<m;++i) a[i]=0;
    for(i=n2;i<m;++i) b[i]=0;
    ntt(a,m,0);ntt(b,m,0);
    for(i=0;i<m;++i) a[i]=mul(a[i],b[i]);
    ntt(a,m,1);
}
void solve()
{
    int n;cin>>n;
    int ans[N],arr1[root_pw>>1],arr2[root_pw>>1];
    memset(ans, 0, sizeof(ans));
    memset(arr1, 0, sizeof(arr1));
    memset(arr2, 0, sizeof(arr2));
    for(int i=0;i<n;++i)
    {
        cin>>A[i];
    }
    // print1(A,n); 
    int bits =0,val=1;
    while(bits<30)
    {
        int count=0,m;
        val = 1LL<<bits;
        for(int i=0;i<n;i++){
            if((A[i]&val)>0)count++;
        }
        if(count == 0){
            bits++;
            continue;
        }
        m=n-count;
        calc1(arr1,count);
        calc1(arr2,m);
        for(int i=0;i<=count;i+=2)arr1[i]=0;
        for(int i=count+1;i<(root_pw>>1);i++)arr1[i]=0;
        for(int i=m+1;i<root_pw>>1;i++)arr2[i]=0;
        mul1(arr1,arr2,count+1,m+1);

        print1(arr1,n);
        for(int i=0;i<=n;i++){
            ans[i] = add(ans[i],mul(arr1[i],1));
        }
        bits++;
        break;
    }
    cout<<endl;
    // int q;cin>>q;
    // for(int i=2;i<=n;i++)ans[i]=add(ans[i-1],ans[i]);
    // for(int i=0;i<q;++i){
        // int m;cin>>m;
        // print(ans[m]);
    // }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}