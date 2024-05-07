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
class group {
    public :
    int id;
    int size;
    int income;
};
class table {
    public:
    int id;
    int size;
};
bool byIncomeDescending(const group &g1, const group &g2) {
    return g1.income> g2.income;
};
bool bySize(const table &t1, const table &t2) {
    return t1.size < t2.size;
};
bool canFit(const table &t , const group &g) {
    return t.size < g.size;
};
void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
};
void solve()
{
    int n; cin >> n;
    vector<group> groups(n);
    for(int i = 0 ; i < n ; i++) {
        groups[i].id = i+1;
        cin >> groups[i].size >> groups[i].income;
    }
    sort(groups.begin() ,groups.end() , byIncomeDescending);
    int m; cin >> m;
    vector<table> tables(m);
    for(int i = 0; i<m;i++) {
        tables[i].id = i+1;
        cin >> tables[i].size;
    };
    sort(tables.begin(), tables.end() ,bySize);
    int sum =0;
    vector<pair<int, int>> ans;
    for(int i =0; i< n ; i++) {
        auto it =  lower_bound(tables.begin(), tables.end(), groups[i], canFit);
        if(it != tables.end()) {
            sum += groups[i].income;
            ans.push_back({groups[i].id, it->id});
            tables.erase(it);
        };
    };
    cout << ans.size() << " " << sum << endl;
    for(auto p : ans) {
        cout << p.first << " " << p.second << endl;
    };
};
int main()
{
    fastio();
    solve();
    return 0;
}