/*
 * Author: Mohammed BENHAMMOUTE
 * Created: 2025-03-15 22:23:55
 */
#include <bits/stdc++.h>
using namespace std;

// Debug macros
#define debug(x) cerr << #x << " = " << x << endl
#define debugv(v) cerr<<#v<<" = ";for(auto e:v)cerr<<e<<" ";cerr<<endl
#define debugm(m) cerr<<#m<<endl;for(auto e:m)cerr<<e.first<<" "<<e.second<<endl
#define debuga(a,n) cerr<<#a<<" = ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<endl
#define debugma(a,n,m) cerr<<#a<<":\n";for(int i=0;i<n;i++){for(int j=0;j<m;j++)cerr<<a[i][j]<<" ";cerr<<endl;}

// Type definitions
#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define vpii vector<pii>
#define vpll vector<pll>

// Shortcuts
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) (int)x.size()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=b-1;i>=a;i--)

// Constants
const int MOD = 1e9+7;
const ll INF = 1e18;
const ld PI = acos(-1.0);
const int dx[8] = {1,-1,0,0,1,1,-1,-1};
const int dy[8] = {0,0,1,-1,1,-1,1,-1};

// Utility functions
template<typename T> inline T gcd(T a, T b) {return b ? gcd(b, a%b) : a;}
template<typename T> inline T lcm(T a, T b) {return a * (b/gcd(a,b));}
template<typename T> inline T mod(T a, T b) {return (a%b + b)%b;}
template<typename T> inline T modpow(T a, T b, T m) {T r=1; while(b) {if(b&1) r=r*a%m; a=a*a%m; b>>=1;} return r;}

// Vector operations
template<typename T> void amax(T &a, T b) {if(b > a) a = b;}
template<typename T> void amin(T &a, T b) {if(b < a) a = b;}
template<typename T> void print(vector<T> &v) {for(auto x:v) cout<<x<<" "; cout<<endl;}
template<typename T> void print2d(vector<vector<T>> &v) {for(auto x:v) {for(auto y:x) cout<<y<<" "; cout<<endl;}}

// Fast I/O
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif
}
vector<int> Rank;
vector<int> parent;
int findParent(int x){
    while(x != parent[x]){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
   return x;
}
void UNION(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if(Rank[a] < Rank[b]){
        parent[a]=b;
    }else if(Rank[a] > Rank[b]){
        parent[b] = a;
    }else{
        parent[a] = b;
        Rank[b]++;
    }
}
vector<pair<int,pair<int,int>>> edges;

template<class T>
class matrix{
    size_t ROW,COL;
    vector<vector<T>> mat;
public:
    matrix(size_t N, size_t M, int populate = 0){
        this->ROW = N;
        this->COL = M;
        this->mat = vector<vector<T>> (ROW,vector<T> (COL,populate));
    }
    matrix(size_t N, int populate = 0){
        this->ROW = N;
        this->COL = N;
        this->mat = vector<vector<T>> (ROW,vector<T> (COL,populate));
    }
    void __init(){
        for(int i = 0; i < ROW; ++i){
            for(int j = 0; j < COL; ++j){
                cin  >> this->mat[i][j];
            }
        }
    }
    void __display(){
        for(int i = 0; i < ROW; ++i){
            for(int j = 0; j < COL; ++j){
                cout << this->mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    matrix<T> operator*(const matrix &rhs)const{
        if(this->COL != rhs.ROW){
            throw "MATRIX MULTIPLICATION CANNOT HAPPEN WITH THE GIVEN MATRICES"
        }
        matrix<T> result(this->ROW,rhs.COL);
        for(int _i = 0; _i < this->ROW; _i++){
            for(int _j = 0; _j < rhs.COL; _j++){
                result[_i][_j] = 0;
                for(int _k = 0; _k < this->COL; ++_k){
                    result[_i][_j]+=(this->mat[_i][_k]*rhs.mat[_k][_j]);
                }
            }
        }
        return result;
    }
    matrix<T> power(int n){
        if(n == 0)return matrix<T>(this->ROW, this->COL,1);
        if(n == 1)return *this;
        matrix p = power(n/2);
        p = p*p;
        if(n%2)p = p*(*this);
        return p;
    }
};

int main() {
    fastIO();
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}