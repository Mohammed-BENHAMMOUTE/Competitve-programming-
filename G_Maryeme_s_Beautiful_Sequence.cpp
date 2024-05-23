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
    vector<int> v;
    for(int i = 0; i < n; i++) 
    {
        int x;cin >> x;
        v.push_back(x);
    };
    int countCost = 0;
    for(int i =0,j=1; i <n-1 && j<n; i++,j++){
        if(__gcd(v[i], v[j])<=1 && i+1)
        {
            countCost++;
            if(__gcd(abs(v[i]-v[j]), (v[i]+v[j])) <=1){
                cout << "NO1" <<endl;
                return;
            };
            v[j] = v[i]+v[j];
        }else{
            continue;
        }
    }
    cout << "YES" <<endl;
    cout << countCost << endl; 
}

int main()
{
    fastio();
    solve();
    return 0;
}