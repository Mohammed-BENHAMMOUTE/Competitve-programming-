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
bool correct(int x, vector<int> &v, int c) {
    int count = 1;
    int current = v[0];
    for(int i = 1; i < v.size(); i++) {
        if(v[i] - current >= x){
            count++;
            current = v[i];
        }
    }
    return  count  >= c;
}

void solve()
{
    int n;cin >> n;
    int c;cin >> c;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    };
    sort(v.begin(), v.end());
    int low =1, high = MOD;
    int mid;
    while(low<high-1) {
        mid = low + (high - low)/2;
        if(correct( mid, v , c)) {
            low = mid;
        }else{
            high = mid-1;
        }
    }
    if(correct(low, v, c)) {
        cout << low << endl;
    }else{
        cout << high << endl;
    };
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