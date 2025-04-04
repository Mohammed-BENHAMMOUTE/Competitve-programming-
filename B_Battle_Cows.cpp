#pragma once

/****************************** begin /template.h ******************************/

/*** begin includes ***/
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpi> vvpi;
typedef vector<vpl> vvpl;
typedef set<int> si;
typedef multiset<int> msi;
typedef set<ll> sl;
typedef multiset<ll> msl;
typedef long double ld;
template<class T> using func = function<T>;

/*** begin #defines ***/
#define clrcin cin.ignore(numeric_limits<streamsize>::max(),'\n');
#define GOGOGO ios::sync_with_stdio(false); cin.tie(nullptr);
#define BYEBYE return 0;

#define all(cn) (cn).begin(), (cn).end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define csz(c) ((int)c.size())
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#define popcnt __builtin_popcount
#define popcntll __builtin_popcount_ll

#define what(x) cout << #x << " = " << x << '\n'
/*** end #defines ***/

const int INFI = 1e9 + 5;
const ll INFL = 1e18 + 5;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;
const ld PI = 3.14159265358979323846;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto dist = uniform_int_distribution<int>(0, INFI);
auto distll = uniform_int_distribution<ll>(0, INFL);
int rnd() { return dist(rng); }
ll rndl() { return distll(rng); }

void solve() {
    int n,k; cin >> n >> k;k--;
    vl a(n);
    rep(i, n) cin >> a[i];
    int b[n];rep(i,n)b[i]=a[i];
    swap(b[k], b[0]);
    int sum1 = 0;
    for(int i = 1; i < n; i++) {
        if(b[i] < b[0]) sum1++;
        else break;
    };
    for(int i = 0; i < k; i++) {
        if(a[i] > a[k])
        {
            swap(a[i], a[k]);
            k = i;
            break;
        };
    };
    
    int ans = 0;
    for(int j =k+1; j < n ;j++){
        if(a[k] > a[j]) ans++;
        else{
            break;
        };
    };
    if(k-1 >= 0) ans++;
    cout << max(ans, sum1) << endl;
}

int main() {
    GOGOGO
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    BYEBYE
}
/****************************** end /template.h ******************************/
