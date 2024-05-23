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
};
void solve()
{
    string l1,l2,l3; cin >> l1;cin >> l2; cin >> l3;
    unordered_set<int> s;
    
    map<char, int> m;
    m['A'] = 0;
    m['B'] = 0;
    m['C'] = 0;
    if(l1[1] == '>') {
        m[l1[0]]++;
    }else{
        m[l1[2]]++;
    };
    if(l2[1] == '>') {
        m[l2[0]]++;
    }else{
        m[l2[2]]++;
    };
    if(l3[1] == '>') {
        m[l3[0]]++;
    }else{
        m[l3[2]]++;
    };
    vector<pair<int ,char>> ans;
    for(auto x : m) {
        ans.pb(mp(x.second, x.first));
        s.insert(x.second);
    };
    sort(ans.begin(), ans.end());
    
    if(s.size() <3) {
        cout << "Impossible" <<endl;
        return;
    };
    // reverse(ans.begin() , ans.end());
    for(pair<int, char>  y : ans){
        std::cout<<y.second;
    };
    return;
};

int main()
{
    fastio();
    solve();
}