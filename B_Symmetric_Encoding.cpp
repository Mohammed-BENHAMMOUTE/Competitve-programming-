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

void solve()
{
    int n; cin >> n;
    string s; cin >>s;
    set<char> s1;
    for(char x : s) {
        s1.insert(x);
    };
    vector<char> r;
    for(char x : s1){
        r.pb(x);
    };
    sort(r.begin(), r.end());
    int start = 0, end = r.size()-1;
    map<char , char> m;
    if(r.size()% 2 ==1)m[r[(end+1)/2]] = r[(end+1)/2];
    while(start < end){
        m[r[start]] = r[end];
        m[r[end]] = r[start];
        start++;end--; 
    };
    for(char x : s)
    {
        cout << m[x];
    };
    cout << endl;
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