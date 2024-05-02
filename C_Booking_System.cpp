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

void solve()
{
    int n; cin >> n;// umber o frequests from the evesitors
    vector<pair<pair<int,int>,int>> cp; // the first is the num of vist // y is the total sum of money 
    for(int i = 1; i<=n; i++) {
        int x, y; cin >> x >> y;
        cp.pb(mp(mp(x, y),i));
    };
    int k; cin >> k;
    vector<pair<int, int>> table;
    for(int i = 1; i<=k; i++) {
        int x; cin >> x;
        table.pb(mp(x,i));
    };
    sort(table.begin(), table.end());
    sort(cp.begin(), cp.end(), [](const pair<pair<int,int>,int>& a, const pair<pair<int,int>,int>& b){
        if(a.first.first == b.first.first) {
            return a.first.second > b.first.second;
        };
        return a.first.first > b.first.first;
    });
    int requests = 0;
    int money =  0;
    vector<pair<int, int>> ans;
    for(pair<int, int> x : table){
        auto it = upper_bound(cp.begin(), cp.end(), mp(x,0), [](const pair<pair<int,int>,int>& a, const pair<pair<int,int>, int>& b){
            return a.first.first > b.first.first;
        });
        if(it == cp.end()) continue;
        if(it != cp.begin()){
            it -=1;
        }
        requests++;
        money += it->first.second;
        ans.pb(mp(it->second, x.second));
        cp.erase(it);
    };
    cout << requests << " " << money << endl;
    for(pair<int, int> x : ans) {
        cout << x.first << " " << x.second << endl;
    };
}

int main()
{
    fastio();
    solve();
    return 0;
}