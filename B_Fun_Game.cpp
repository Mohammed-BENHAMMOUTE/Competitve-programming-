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
    string s1,s2; cin >> s1 >> s2;
    if(n ==1 )
    {
        if(s2[0] == '0' || s1[0] == s2[0]){
            cout << "YES" <<endl;return;
        };
        cout<< "NO" <<endl;return;
    };
    int s11 = -1;
    for(int i =0 ; i < n ; i++) {
        if(s1[i] == '1'){
            s11 = i;break;
        }
    };
    int s21 = -1;
    for(int i = 0; i < n ;i++) {
        if(s2[i] == '1'){
            s21 = i;break;
        }
    };
    if(s21 == s11 || s21 == -1){
        cout << "YES" <<endl;return;
    };
    if(s11 == -1 && s21 != -1){
        cout << "NO" <<endl;
        return;
    };
    if(s21 < s11){
        cout << "NO" <<endl;return;
    }   
    cout << "YES" <<endl;
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