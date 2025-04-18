#include <bits/stdc++.h>
#include <vector>
using namespace std;


void solve()
{
  int n;cin >>n;
  string s; cin >> s;
  int q; cin >> q;
  vector<int> res;
  for(int i = 0; i < q ;i++)
  {
    int m ; cin >> m;
    
    char c; cin >> c;
    if(m >= n) {
      res.push_back(n);
      continue;
    }
    int currentDistinct = 0;
    int right  =0 , left = 0;
    int ans = 0;
    for(right = 0 ; right < n ; ++right)
    {
      if(s[right] != c) currentDistinct++;
      while (left <= right && currentDistinct > m) {
        if(s[left++] != c){
          currentDistinct--;
        } 
      }
      ans = max(ans , right - left + 1);
    };
    res.push_back(ans);
  }
  for(int i = 0 ; i < q ;i++) 
  {
    cout << res[i] << endl;
  }
}



int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  //cin >> t ;
  while(t--)
  {
    solve();
  }
  return 0;
}
