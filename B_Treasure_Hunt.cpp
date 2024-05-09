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
    ll n; cin >> n;
    string Kuro; cin >> Kuro; 
    map<char, int> kuro;
    int mxKuro = 0 ;
    string Shiro; cin >>Shiro;
    int mxShiro= 0;
    map<char, int> shiro;
    string Katie; cin >> Katie;
    int mxKatie = 0;
    map<char, int> katie;
    int m = max(max(Kuro.size(), Shiro.size()), Katie.size());
    for(int i = 0; i< m; i++) {
        if(i < Kuro.size()) {
            kuro[Kuro[i]]++;
            mxKuro = max(mxKuro, kuro[Kuro[i]]);
        };
        if(i < Shiro.size()) {
            shiro[Shiro[i]]++;
            mxShiro = max(mxShiro, shiro[Shiro[i]]);
        };
        if(i < Katie.size()) {
            katie[Katie[i]]++;
            mxKatie = max(mxKatie, katie[Katie[i]]);
        };
    };
    int ansKuro = Kuro.size() - mxKuro;
    if(ansKuro <= n) {
        if(n == 1 && ansKuro == 0){
            ansKuro++;
        }else{
            ansKuro = 0;
        }
    } else {
        ansKuro = ansKuro - n;
    };
    int ansShiro = Shiro.size() - mxShiro;
    if(ansShiro <= n) {
        if(n == 1 && ansShiro == 0){
            ansShiro++;
        }else{
            ansShiro = 0;
        }
    } else {
        ansShiro -= n;
    } ;
    int ansKatie = Katie.size() - mxKatie;
    if(ansKatie <= n) {
        if(n == 1 && ansKatie == 0){
            ansKatie++;
        }else{
            ansKatie = 0;
        }
    } else {
        ansKatie = ansKatie - n;
    };
    vector<pair<int , string>> ans;
    ans.push_back({ansKuro, "Kuro"});
    ans.push_back({ansShiro, "Shiro"});
    ans.push_back({ansKatie, "Katie"});
    sort(ans.begin(), ans.end());
    if(ans[0].first == ans[1].first && ans[1].first == ans[2].first) {
        cout << "Draw" << endl;
        return;
    } else if(ans[0].first == ans[1].first) {
        cout << "Draw" << endl;
        return;
    } else {
        for(int i= 0; i<3; i++ ) {
            if(ans[i].first >=0) {
                cout << ans[i].second << endl;
                return;
            };
        };
    };
    return;
}

int main()
{
    fastio();
    solve();
    return 0;
}