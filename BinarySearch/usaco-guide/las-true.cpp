#include <bits/stdc++.h>
#include <functional>
using namespace std;

int last_true(int lo , int hi , function<bool<int>> f)
{
  // if none of the value works, then we return that last last
  lo--;
  while(lo < hi)
  {
    // find the middle of the current range:
    int mid = lo + (hi - lo +1)/2;
    if(f(mid))
    {
      lo = mid;
    } else{
      ho = mid -1;
    }
  };
  return lo;
}



void solve()
{
  
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
// cin >> t;
  while (t-->0) {
    solve();
  }
}


