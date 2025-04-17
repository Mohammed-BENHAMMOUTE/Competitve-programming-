#include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef long long ll ;

void solve()
{
  int n; cin >> n;
  ll k; cin >> k;
  vector<ll> a(n);
  for(ll& x : a)
  {
    cin >> x;
  }
  sort(a.begin() , a.end());
  vector<int> bestLeft(n) , bestRight(n);
  int  l =0;
  for(int r = 0; r < n; ++r)
  {
    while(a[r] - a[l] > k) ++l;
    bestLeft[r] = r-l+1;
    if(r > 0) bestLeft[r] = max(bestLeft[r] , bestLeft[r-1]);
  }
  int r = n-1;
  for(int  l = n-1 ; l >= 0 ; --l)
  {
    while(r >= l && a[r] - a[l] > k) --r;
    bestRight[l] = r-l+1;
    if(l < n-1) bestRight[l] = max(bestRight[l] , bestLeft[l+1]);
  }

  int ans = 0;
  for(int i = 0; i < n-1 ; ++i)
  {
    ans = max(ans , bestLeft[i] + bestRight[i+1]);
  }
  cout << ans << endl;
}

int main() 
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int t = 1;
   // cin >> t;
  while(t--)
  {
    solve();
  }
}
