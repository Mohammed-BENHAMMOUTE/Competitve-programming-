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
    string s; cin >> s;
    deque<char> ans;
    for(int i = 1; i <= n; i++) 
    {
        if(i%2 == 0){
            ans.push_front(s[i-1]);
        }else{
            ans.push_back(s[i-1]);
        };
    };
    if(n%2 == 0) {
        reverse(ans.begin(), ans.end());
    };
    for(char x :ans)
    {
        cout << x;
    }
    return;
};
int main()
{
    fastio();
    solve();
    return 0;
}