//Author @Harsh_xerus   

#include<bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#define rep(i,n) for (int i = 0; i < n; i++)
#define mem0(arr) memset(arr, 0, sizeof(arr))
#define mod 1000000007
#define mod2 998244353
#define pb push_back
#define ff first
#define ss second
#define ll long long 
#define pll pair<ll,ll>
#define pss pair<ll,string>
#define vpss vector<pss>
#define vll vector<ll>
#define vpll vector<pll>
#define INF 1e18
#define nl '\n'
#define vi vector<int>
#define rep(i, a, b) for (int i = a; i < b; i++)
const ll maxn = 1e6 + 2;
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
typedef unsigned long long ull;
typedef long double lld;
using namespace std;
// Pragmas
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

//------------------------------Debugger-----------------------------------//

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//--------------------------Helper_functions-------------------------------//

//-------------------------------GCD---------------------------------------//

ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}

//-------------------------------LCM---------------------------------------//

ll lcm(ll a, ll b){return (a * b) / gcd(a, b);}

//----------------------------Factorial------------------------------------//

ll fact(ll x){if(x==0)return 1;return (x*fact(x-1))%mod;}

//-----------------------------Bin_Expo------------------------------------//

ll binpow(ll a,ll b) {
    //a%=mod;                 //here too
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a);  //add mod if needed
        a = (a * a);          //add mod if needed
        b >>= 1;
    }
    return res;
}

//-------------------------Sum/Count of digits----------------------------//

ll sd(ll x){ll temp=0;while(x>0){temp+=x%10;x/=10;}return temp;}
ll cd(ll x){ll temp=0;while(x>0){temp++;x/=10;}return temp;}

//-------------------------------START------------------------------------//

ll find(ll ind, ll w, vector<ll>&value, vector<ll>&wt,vector<vector<ll>>&dp){
    if(ind==0){
        if(w>=wt[ind])
        {
            return value[ind];
        }
        else{
            return 0;
        }
    }
    if(dp[ind][w]!=-1)
        return dp[ind][w];
    //pick
    ll take = -1;
    if(wt[ind]<=w)
        take = value[ind]+ find(ind-1,w-wt[ind],value,wt,dp);

    ll notake = find(ind-1,w,value,wt,dp);
    return dp[ind][w] = max(take,notake);
}

void solve(){
    ll n,w;
    cin >> n;
    vll value(n),wt(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    cin>>w;
    vector<vector<ll>>dp(n,vector<ll>(w+1,0));
    //cout<<find(n-1,w,value,wt,dp)<<nl;
    //dp[i][j] stores the maximum profit i can make using elements
    //upto ith index and restricted by wt limit j
    dp[0][0]=0;
    for(int i=1;i<=w;i++){
        if(i>=wt[0])
            dp[0][i]=value[0];
    }
    for(int i=1;i<n;i++){
        ll ans=0;
        for(int j=0;j<=w;j++){
            ll notake = dp[i-1][j];
//
            ll take = 0;
            if(j>=wt[i]){
                take = dp[i-1][j-wt[i]] + value[i];
            }
            ans=max(notake, take);
            dp[i][j]=max(dp[i][j],ans);
        }
        
    }
    debug(dp)
    cout<<dp[n-1][w]<<nl;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    ll t = 1, i = 1;
    cin >> t;
    cout << std::setprecision(15);
    //presolve();
    clock_t start, end;
    start = clock();
    while (t--)
    {
        //cout << "Case #" << i << ": ";   //only during google contest
        //i++;                             //only during google contest

        solve();
    }
    end = clock();
    double Time = double(end - start) / double(CLOCKS_PER_SEC);
    debug(Time)
}
