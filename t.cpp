#pragma GCC optimize("Ofast") 
#pragma GCC target("avx,avx2,fma")
#include "bits/stdc++.h"
// #define int long long
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
const int N = 2e5+1;
const int MOD = 998244353;
const int root = 363395222;
const int root_1 = 704923114;
const int root_pw = 1 << 19;
int A[N],ans[N];
inline int add(int a,int b){a+=b;if(a>=MOD)a-=MOD;return a;}
inline int sub(int a,int b){a-=b;if(a<0)a+=MOD;return a;}
inline int mul(int a,int b){return (a*1ll*b)%MOD;}
inline int bpow(int a,int b){int rt=1;while(b>0){if(b&1)rt=mul(rt,a);a=mul(a,a);b>>=1;}return rt;}
inline int MODINV(int x){return bpow(x,MOD-2);}
void ntt(vector<int> & a, bool invert)
{
    int n = a.size();
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
        int n_1 = MODINV(n);
        for (int & x : a)
            x = (1LL * x * n_1 % MOD);
    }
}
vi mul1(vi a,vi b)
{
    int n1=a.size(),n2=b.size();
    int n = n1 + n2 - 1, i;
    int m = 1; while(m<n) m<<=1;
    a.resize(m);
    b.resize(m);
    ntt(a,0);ntt(b,0);
    vi c(m);
    for(i=0;i<m;++i) c[i]=mul(a[i],b[i]);
    ntt(c,1);
    return c;
}
vi calc1(int n){
    vi ncr1(n+1,1);
    int num=1,den=1;
    for(int i=0;i<n;i++){
        num = mul(num,n-i);
        den = mul(den,i+1);
        ncr1[i+1] = mul(num,MODINV(den))%MOD;;
    }
    return ncr1;
}
void solve()
{
    int n;cin>>n;
    int ans[N];
    memset(ans, 0, sizeof(ans));
    for(int i=0;i<n;++i){
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
        vi arr1,arr2;
        arr1 = calc1(count);
        if(count==n){
            for(int m=1;m<=n;m+=2){
                ans[m-1] = add(ans[m-1],mul(val,arr1[m]));
            }
            continue;
        }
        for(int i=0;i<len(arr1);i+=2)arr1[i]=0;
        arr2 = calc1(n-count);
        vi ans1 = mul1(arr1,arr2);
        for(int i=1;i<=n;i++){
            ans[i] = add(ans[i],mul(ans1[i],val));
        }
        bits++;
    }
    int q;cin>>q;
    for(int i=2;i<=n;i++)ans[i]=add(ans[i-1],ans[i]);
    for(int i=0;i<q;++i){
        int m;cin>>m;
        print(ans[m]);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
