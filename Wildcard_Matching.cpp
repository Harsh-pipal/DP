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

bool find(ll i, ll j , string &s , string &p, vector<vector<ll>>&dp){

    if(i<0 and j<0)return true;
    if(i<0 and j>=0)return false;
    if(i>=0 and j<0){
        for(int it=0;it<=i;it++){
            if(s[it]!='*')
                return false;
        }
        return true;
    }
    if(dp[i][j]!=-1)
        return dp[i][j];

    if(s[i]==p[j] or s[i]=='?'){
        return dp[i][j] = find(i-1,j-1,s,p,dp);
    }
    if(s[i]=='*'){
        return dp[i][j] = find(i,j-1,s,p,dp) || find(i-1,j,s,p,dp);
    }
    return false;
}

void solve(){
    ll n,w,m;
    cin >> n >> m;
    string s,p;
    cin>>s>>p;
    vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));
    //cout<<find(n-1,m-1,s,p,dp)<<nl;
    
    dp[0][0] = 1;  ////true basically

    for(int i=1;i<=m;i++){
        dp[0][i] = 0;     //false from base condition in recursive solution
    }

    for(int i=1;i<=n;i++){
        bool flag = true;
        for(int it=1;it<=i;it++){
            if(s[it-1]!='*'){
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1] == p[j-1] or s[i-1]=='?')
                dp[i][j] = dp[i-1][j-1];
            else if(s[i-1]=='*')
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            else
                dp[i][j] = 0;
        }
    }
    cout<<dp[n][m]<<nl;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    ll t = 1, i = 1;
    //cin >> t;
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
