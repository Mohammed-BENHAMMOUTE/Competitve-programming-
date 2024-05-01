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
const int MAX_INT = 1e9;
static int first1iNBINARYString(string s) {
    for(int i = 0; i< s.size(); i++) {
        if(s[i] == '1') {
            // cout<< i << endl;
            return i;
        }
    }
    return MAX_INT;
};

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve()
{
    string s; cin >> s;
    string copy = s;
    sort(copy.begin(), copy.end());
    if(copy == s) {
        cout << 0 << endl;
        return;
    };
    int Frst1 = first1iNBINARYString(s) ;
    if(Frst1 == MAX_INT) {
        cout << 0 << endl;
        return;
    };
    if(s.size() ==1){
        cout << 0 << endl;
        return;
    };
    ll cost = 0;
    for(int i = 0; i<s.size(); i++) {
        if(s[i] == '0' && i >= Frst1) {
            cost += abs(i-Frst1+1);
            Frst1++;
        };
    };
    cout << cost << endl;
};
int main()
{
    fastio();
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}