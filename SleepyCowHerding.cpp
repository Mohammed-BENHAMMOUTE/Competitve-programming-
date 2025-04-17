#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstdint>
#include <vector>
using namespace std;

typedef long long ll;
void solve()
{
  int n; cin >> n;
  vector<ll> a(n);
  for(int i =0 ; i < n ; i++) {
    cin >> a[i];
  };
  sort(a.begin() , a.end());
  int ans = INT32_MAX;
  if(a[n-2] - a[0] == n-2 && a[n-1] - a[n-2] > 2)
  {
    ans = 2;
  }else if(a[n-1] - a[1] == n-2 && a[1] - a[0] > 2){
    ans = 2;
  }else{
    int r = 0, l = 0;
    ll minMoves = LLONG_MAX;
    for(r = 0 ; r < n ; r++){
      while(l <= r && a[r] - a[l] >= n){
        l++;
      }
      minMoves = min(minMoves, (ll)n - (r - l + 1));
    }
    int gap_num = 0;
    for(int i = 1; i < n ; i++) 
    {
      gap_num += a[i] - a[i-1] - 1;
    }
    ll maxmoves = max((gap_num - (a[n-1] - a[n-2] - 1)), (gap_num - (a[1] - a[0] - 1)));
    if ((a[n-2] - a[0] == n-2 && a[n-1] - a[n-2] > 2) ||
        (a[n-1] - a[1] == n-2 && a[1] - a[0] > 2)) {
      minMoves = 2;
    }
    cout << minMoves << endl << maxmoves << endl;
  }
}



int main()
{
  ios::sync_with_stdio();
  cin.tie(0);
  int t = 1;
  // cin >> t;
  while(t--)
  {
    solve();
  }
}; 
