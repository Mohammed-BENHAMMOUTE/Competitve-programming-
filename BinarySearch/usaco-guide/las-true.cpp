#include <bits/stdc++.h>
#include <functional>
using namespace std;

int last_true(int lo , int hi , function<bool(int)> f)
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
      hi = mid -1;
    }
  };
  return lo;
}



// a second implementation requires using p=binary jumping, which is easier in implementation than the usual binary search:


int last_True_2(int l , int r , function<bool(int)> f)
{
  l--;

  for(int diff = r -l; l + diff <= r ; diff/=2)
  {
    while(diff+ l <= r && f(diff + r)){r+=diff;}
  }
  return l;
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


