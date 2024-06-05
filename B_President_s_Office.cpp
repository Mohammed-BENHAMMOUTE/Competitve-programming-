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
vector<int> dr = {0, 0, 1, -1};
vector<int> dc = {1, -1, 0, 0};
void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve()
{
    int n, m; cin >> n >> m;
    char s; cin >> s;
    map<char, int> mp;
    vector<string> v(n);
    vector<pair<int, int>> k;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        for(int j = 0; j < m ; j++) {
            if(v[i][j] == s){
                k.pb({i,j});
            }
        }
    };
    for(auto x : k) 
    {
        for(int i = 0; i < 4; i++) {
            int r = x.first +dr[i];
            int c = x.second + dc[i];
            if(r >= 0 && r < n && c >= 0 && c < m && v[r][c] != s && v[r][c] != '.') {
                mp[v[r][c]]++;
            };
        }
    };
    cout << mp.size() << endl;
    return;
}

int main()
{
    fastio();
    solve();
    return 0;
}