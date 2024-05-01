#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define tc     \
    ll tc;     \
    cin >> tc; \
    while (tc--)
#define pb push_back
#define mp make_pair
const ll MOD = 1e9 + 7;

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve(int n)
{
    vector<ll> v;
    vector<ll> last1;
    vector<ll> last2;
    for(int i =0; i< n; i++) {
        ll x,y;
        cin >> x >> y;
        v.pb(x);
        v.pb(y);
        if(i>=n/2) {
            last1.pb(x);
            last2.pb(y);
        };
    };
    sort(v.begin(), v.end());
    string s1 = "";
    string s2 = "";
    for(int i = 0; i<n/2; i++) {
        s1 += "1";
        s2 += "1";
    };
    for(int i = 0; i<last1.size(); i++) {
        auto dist1 = distance(v.begin(), lower_bound(v.begin(), v.end(), last1[i]));
        if(dist1 >= n) {
            s1 += "0";
        } else {
            s1 += "1";
        };
        auto dist2 = distance(v.begin(), lower_bound(v.begin(), v.end(), last2[i]));
        if(dist2 >= n) {
            s2 += "0";
        } else {
            s2 += "1";
 
        };
    };
    while(s1.size() < n) {
        s1 += "0";
    };
    while(s2.size() < n) {
        s2 += "0";
    };
    cout << s1<< endl;
    cout << s2 << endl;
}

int main()
{
    fastio();
    int n;
    cin >> n;
    solve(n);

    return 0;
}