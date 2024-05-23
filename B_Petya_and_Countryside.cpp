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
    if(n==1){
        cout << 1<<endl;
        return;
    };
    vector<int> v;
    for(int i =0 ; i< n ;i++){
        int x; cin >> x;
        v.pb(x);
    };

    int max= 0;
    for(int i = 0; i < n ; i++) {
        int count  = 1;
        for(int j = i + 1; j<n && v[j]<=v[j-1] ; j++) {
            count++;
        };
        for(int j = i-1; j>=0  && v[j] <= v[j+1]; j--) {
            count++;
        };
        max = std::max(max, count);
    };
    cout << max<< endl;   
}

int main()
{
    fastio();
    ll t;
    solve(); 
    return 0;
}