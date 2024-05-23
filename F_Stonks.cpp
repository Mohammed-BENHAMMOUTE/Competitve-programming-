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
struct Purchase {
    string name;
    ll price;
    ll freq;
};
void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
};


void solve()
{
    int q; cin >> q;
    unordered_map<string, Purchase> a;
    unordered_set<string> names;
    ll maxfreq = 0, maxprice = 0;
    string maxname = "";

    while(q--) {
        ll n; cin >> n;
        if(n == 1) {
            string s; cin >> s;
            int in; cin >> in;
            if(names.find(s) == names.end()) {
                names.insert(s);
                a[s].name = s;
                a[s].price = in;
                a[s].freq = 1;
            } else {
                a[s].price += in;
                a[s].freq++;
            };
            if(a[s].freq > maxfreq || (a[s].freq == maxfreq && a[s].price > maxprice )|| (a[s].freq == maxfreq && a[s].price == maxprice && s < maxname)) {
                maxfreq = a[s].freq;
                maxprice = a[s].price;
                maxname = s;
            };
        } else {
            cout << maxname <<"\n";
        }
    }

}


int main()
{
    fastio();
    solve();
    return 0;
}