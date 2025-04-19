/*
 * Author: Mohammed BENHAMMOUTE
 * Created: 2025-04-19 20:21:09
 */
#include <algorithm>
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

struct Event {
  ll x, y, t;
  bool operator < (const Event& other) const {
    if (t != other.t) return t < other.t;
    if (x != other.x) return x < other.x;
    return y < other.y;
  }
};

bool is_suspect(ll x1 , ll y1 , ll t1 ,ll x2 , ll y2 , ll t2)
{
  ll distance = pow(x1 -x2 , 2) + pow(y1 -y2 , 2);
  ll time = abs(t1 - t2);
  return distance > time * time;
}

// solution using the brute force approach: should give TLE

void solve1() {
  int g , n; cin >> n >> g;
  vector<Event> burns(g);
  for(int i =0 ; i < g; i++)
  {
    cin >> burns[i].x >> burns[i].y >> burns[i].t;
  }
  ll count = 0;
  for(int i =0 ; i < n ; i++)
  {
    int x , y , t; cin >> x >> y >> t;
    for(auto event : burns)
    {
      if(is_suspect(event.x , event.y , event.t , x , y , t))
      {
        count++;
        break;
      }
    }
  }
  cout << count << endl;
}

void solve2()
{
  int g , n; cin >> g >> n;
  vector<Event> burns(g);
  for(int i =0 ; i < g; i++)
  {
    cin >> burns[i].x >> burns[i].y >> burns[i].t;
  }
  ll count = 0;
  sort(burns.begin() , burns.end());
  for(int i =0 ; i < n ; i++)
  {
    int x , y , t; cin >> x >> y >> t;
    Event temp1 = {x , y , t};
    auto it1 = lower_bound(burns.begin() , burns.end() , temp1); 
    
    bool is_suspicious = false;
    if (it1 != burns.end()) {
      is_suspicious |= is_suspect(it1->x, it1->y, it1->t, x, y, t);
    }
    if (it1 != burns.begin()) {
      --it1;
      is_suspicious |= is_suspect(it1->x, it1->y, it1->t, x, y, t);
    }
    if (is_suspicious) {
      count++;
    }
  }
  cout << count << endl;
}



int main() {
    fastIO();
    int t = 1;
    // cin >> t;
    while(t--) {
        // solve1();
        solve2();
    }
    return 0;
}
