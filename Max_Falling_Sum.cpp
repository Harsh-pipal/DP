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
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

int maxfall(int x, int y, int n , int m, vector<vector<int>>&arr,vector<vector<int>>&dp){
    if(x>=n or y<0 or y>=m){
        return -1e9;
    }
    if(x==n-1){
        return arr[x][y];
    }
    if(dp[x][y]!=-1)return dp[x][y];
    int down = arr[x][y] + maxfall(x+1,y,n,m,arr,dp);
    int left = arr[x][y] + maxfall(x+1,y-1,n,m,arr,dp);
    int right = arr[x][y] + maxfall(x+1,y+1,n,m,arr,dp);

    return dp[x][y] = max(max(down,left),right);
}

void solve(){
    ll n, k ,m,a,b; 
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m,0));
    //vector<vector<int>>dp(n,vector<int>(m,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int ans=-1e9;
    
    vector<int>temp(m);
    for(int i=0;i<m;i++){
        temp[i]=arr[0][i];
    }
    for(int i=1;i<n;i++){
        vector<int>curr(m);
        for(int j=0;j<m;j++){
            //my task is to allocate maximum value to i,j from all paths above
            int left = -1e8, right =-1e8;
            int top = arr[i][j] + temp[j];
            if(j>0)
                left = arr[i][j] + temp[j-1];
            if(j<m-1)
                right = arr[i][j] + temp[j+1];

            curr[j]=max(max(top,left),right);
        }
        temp=curr;
    }
    for(int i=0;i<m;i++){
        ans=max(ans,temp[i]);
    }
   
    cout<<ans<<nl;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    ll t = 1, i = 1;
    cin >> t;
    cout << std::setprecision(15);
    
    
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
