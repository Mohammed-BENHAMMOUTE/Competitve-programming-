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
bool isComposite(int n){
    if(n<=3) return false;
    if(n%2 == 0 || n%3 == 0) return true;
    for(int i = 5; i*i <=n; i+=6){
        if(n%i == 0 || n%(i+2) == 0) return true;
    }
    return false;
}
pair<int, int> findCompositeSum(const vector<int>& evens, const vector<int>& odds) {
    for (int even : evens) {
        for (int odd : odds) {
            if (isComposite(even + odd)) {
                return make_pair(even, odd);
            }
        }
    }
    return make_pair(-1, -1); 
}



void solve()
{
    int n;cin>>n;
    vector<int> evens;
    vector<int> odds;
    
    for(int i = 1; i <= n; i++){
        if(i % 2 == 0) {
            evens.push_back(i);
        } else {
            odds.push_back(i);
        }
    }
    pair<int,int> ans = findCompositeSum(evens, odds);
    if(ans.first ==-1){
        cout << -1<<endl;
        return;
    }
    for(int x: evens){
        if(x != ans.first) cout <<x << " ";
    }
    cout << ans.first<<" " << ans.second<<" ";
    for(int x : odds){
        if(x != ans.second){
            cout << x << " ";
        }
    }
    cout<<endl;
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