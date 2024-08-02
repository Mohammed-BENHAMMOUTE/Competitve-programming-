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
    int n; cin >> n;
    string s1,s2;
    cin >> s1 >> s2;
    int count = 0;
    for(int i = 1 ;i < n-1; i++) {
        if(s1[i] == '.' && s1[i+1] == '.' && s1[i-1] == '.' && s2[i] == '.' && s2[i+1] == 'x' && s2[i-1] == 'x'){count++;continue;};
        if(s2[i] == '.' && s2[i+1] == '.' && s2[i-1] == '.' && s1[i] == '.' && s1[i+1] == 'x' && s1[i-1] == 'x'){count++;};
    };
    cout << count << endl;return;
}

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