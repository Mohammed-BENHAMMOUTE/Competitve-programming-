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
    string s; cin >> s;
    int n = s.size();
    int count1 = count(s.begin(), s.end(), '1');
    string K;
    for(int i = 0 ; i< count1; i++) K.pb('1');
    s.erase(remove(s.begin(), s.end(), '1'), s.end());
    size_t pos = s.find('2');
    if(pos != string::npos) {
        s.insert((int)pos, K);
    }else{
        if(s.size() == 0) {
            s = K;
        } else {
            s.insert(s.size(), K);
        }
    }
    cout << s << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}