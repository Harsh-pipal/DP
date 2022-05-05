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

int collect(int x1, int y1, int x2, int y2, int n, int m, vector<vector<int>>&arr, vector<vector<vector<int>>>&dp){
    if(y1<0 or y1>=m or y2<0 or y2>=m or x1==n or x2==n)
        return -1e8;
    if(x1==n-1){
        if(y1==y2){
            return arr[x1][y1];
        }
        else{
            return arr[x1][y1] + arr[x2][y2];
        }
    }
    if(dp[x1][y1][y2]!=-1)
        return dp[x1][y1][y2];
    //we have 9 total possibilities for all the movements
    //for every direction alice chooses we have 3 options for bob
    //int dy[] = {-1,0,1};
    int maxi = -1e9;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            int left=-1e9 ,right=-1e9;
            if(y2==y1){
                left = arr[x1][y1] + collect(x1+1,y1+i,x2+1,y2+j,n,m,arr,dp);
            }
            else{
                right = arr[x1][y1] + arr[x2][y2] + collect(x1+1,y1+i,x2+1,y2+j,n,m,arr,dp);
            }
            maxi=max(maxi,(max(left,right)));
        }
    }

    return dp[x1][y1][y2] = maxi;
}

void solve(){
    ll n, k ,m,a,b; 
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m,0));
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(i==j)
                dp[0][i][j]=arr[0][i]; 
            else
                dp[0][i][j]=arr[0][i] + arr[0][j];
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<m;k++){
                //my current state is dp[i][j][k]
                int maxi=-1e8; 
                for(int dy1=-1;dy1<=1;dy1++){
                    for(int dy2=-1;dy2<=1;dy2++){
                        int value=-1e9;
                        if(j==k){
                            value = arr[i][j];
                        }
                        else{
                            value = arr[i][k] + arr[i][j] ;
                        }
                        if(j+dy1>=0 and j+dy1<m and k+dy2>=0 and k+dy2<m){
                            value += dp[i-1][j+dy1][k+dy2];
                        }
                        else{
                            value = -1e9;
                        }
                        maxi=max(maxi,value);
                    }
                }
                dp[i][j][k]=maxi;
            }
        }
    }
    int ans=-1e9;

    doubt in what to print

    where is my answer?
    ///for(int i=0;i<m;i++){
    ///    
    ///      ans=max(ans,dp[n-1][0][i]);  
    ///    
    ///    
    ///}
    debug(dp)
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
