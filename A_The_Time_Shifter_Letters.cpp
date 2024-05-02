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
    int n; cin >> n;
    string scrambledString; cin >> scrambledString;
    string unscrambledString; cin >> unscrambledString;
    if(n ==1){
        cout << 1 << endl;
        return;
    };
    ll ans = 0;//distinct ways to tranf s1 to s2?
    for(int i = 0; i<n; i++){
        if(scrambledString[i] == unscrambledString[i]){
            continue;
        };
        if(scrambledString[i] =='z' && scrambledString[i] != unscrambledString[i]){
            cout << -1 << endl;
            return;
        };
        ans+= abs(scrambledString[i] - unscrambledString[i])+1;
    };
    cout << ans << endl;
}
int main()
{
    fastio();
    solve();
    return 0;
}