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
// const int MOD=998244353;
// const int root = 3;
// const int root_1 = 332748118;
// const int root_pw = 1 << 23;
const int MOD = 7340033;
const int root = 5;
const int root_1 = 4404020;
const int root_pw = 1 << 20;
int bpow(int x,int n){
    if(n==1)return x;
    int v = bpow(x,n/2);
    v = (v*v)%MOD;
    return (n&1?(x*v)%MOD:v);
}
inline int add(int x,int y){return (x+y)%MOD;}
inline int mul(int x,int y){return (x*y)%MOD;}
inline int modinv(int x){return bpow(x,MOD-2);}
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
        int n_1 = modinv(n);
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
map<int,vi>ncrs;
void calc1(int n){
    if(ncrs.count(n))return;
    vi ncr1(n+1,1);
    int num=1,den=1;
    int mid = (n+1)/2;
    for(int i=0;i<n;i++){
        num = mul(num,n-i);
        den = mul(den,i+1);
        ncr1[i+1] = mul(num,modinv(den))%MOD;
        // if(i>=mid)ncr1[i]=0;
    }
    ncrs[n] = ncr1;
}
void solve()
{
    int n;cin>>n;
    vi a(n),count(31,0);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        for(int bit=0;bit<30;++bit){
            if((a[i]&(1LL<<bit)) > 0)count[bit]++;
        }
    }
    for(auto v:count){
        calc1(v);
        calc1(n-v);
    }
    vector<string>pattern(n+1);
    int q;cin>>q;
    vi ans1(n);
    calc1(n);
    int ans = 0;
    vi odds(30,1);
    for(int bit=0;bit<30;++bit)
    {
        if(count[bit]==0)continue;
        int prev = 0;
        vi temp;
        for(int m=1;m<=n;++m)
        {
            int val = (1LL<<bit);
            if(count[bit]==n){
                if(m&1){
                    ans1[m-1] = add(ans1[m-1],mul(val,ncrs[n][m]));
                }
                continue;
            }
            int N = n-count[bit],i=0,st,odd=1;
            if(m-odds[bit]>N)odds[bit]+=2;
            odd = odds[bit];
            st = m - odd;
            // odd = count[bit]-odd;
            int val1 = 0;
            while(st>=0 and odd<=count[bit]){
                int v = mul(ncrs[N][st],mul(val,ncrs[count[bit]][odd]));
                int r1 = st,r2 = odd;
                if(r1>=(N+1)/2)r1 = N-r1;
                if(r2>=(count[bit]+1)/2)r2 = count[bit]-r2;
                // string s = to_string(N)+"C"+to_string(r1)+"*"+to_string(count[bit])+"C"+to_string(r2)+" ";
                // pattern[m].append(s);
                // printf("%lldC%lld*%lldC%lld ",N,r1,count[bit],r2);
                ans1[m-1] = add(ans1[m-1],v);
                val1 = add(val1,v);
                st -= 2;
                odd += 2;
            }
            printf("%lld\n",val1/val);
            prev=val1;
        }
        cout<<endl;
        int v = count[bit];
        vi c(ncrs[v].begin(),ncrs[b].end());
        for(int i=0;i<len(c);i+=2;)c[i]=0;
        auto a = mul1(ncrs[n-count[bit]],c);
        auto b = mul1(ncrs[n-count[bit]],ncrs[count[bit]]);
        print(a);
    }
    // sort(pattern.begin(), pattern.end());
    // for (int i = 1; i <= n; ++i)
    // {
    //     print(pattern[i]);
    // }
    for(int i=1;i<n;i++)ans1[i]=add(ans1[i-1],ans1[i]);
    for(int i=0;i<q;++i){
        int m;cin>>m;
        print(ans1[m-1]);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}