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
    std::cin.tie(0);
    std::cout.tie(0);
};
void solve()
{
    ll n; cin >> n;
    multiset<pair<int, int>> set;
    unordered_set<int> set1;
    for(int i = 0; i <n ; i++) {
        int x; cin >> x;
        set.insert({x,i+1});
        set1.insert(x);
    };
    auto y = lower_bound(set.begin(), set.end(), mp(0,0));
    if(y == set.end() || (*y).first != 0) {
        std::cout << "Impossible" <<endl;
        return;
    };
    vector<int> ans;
    int count = 0;
    int cpt = 0;
    while(count < n) {
        auto it = lower_bound(set.begin(), set.end(), mp(cpt, 0));
        if(it!= set.end() && (*it).first > cpt) {
            std::cout << "Impossible"<<endl;
            return;
        };
        while(it == set.end()) {
            if(cpt < 3) {std::cout << "Impossible" << endl;return;}
            cpt -=3;
            it = lower_bound(set.begin(), set.end(), mp(cpt, 0));
            if(it != set.end() && (*it).first > cpt) {
                std::cout << "Impossible" << endl;
                return;
            };
        };
        if(it != set.end()){
            ans.pb((*it).second);
            set.erase(it);
        }else{
            std::cout << "Impossible" << endl;
            return;
        };
        count++;
        cpt++;
    };
    std::cout << "Possible"<<endl;
        for(auto x : ans) 
        {
            std::cout << x << " ";
        };
        return;
};
int main()
{
    fastio();
    solve();
    return 0;
};