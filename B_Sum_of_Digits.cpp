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
    string s;cin >> s;
    ll sum = 0;
    if(s.size() == 1) {
        cout << 0 << endl;
        return;
    };
    
    for (int i =0 ; i < s.size(); i++)
    {
        sum+= s[i]-'0';
    };
    int count =1;
    while(sum>9) {
        string  sum1 = to_string(sum);
        sum = 0;
        for(int i = 0; i <sum1.size();i++)
        {
            sum+=sum1[i] -'0';
        };
        count++;
    };
    cout << count << endl;
    return;
}

int main()
{
    fastio();
    solve();
    return 0;
}