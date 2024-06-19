#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;
vector<int> pr;
int ar[MAXN];
int pre[MAXN];
int dp[MAXN];


static vector<int> sieve(int n)
{
   vector<bool> is(n + 1, true);
   vector<int> primes;
   for (int i = 2; i * i <= n; i++) {
      if (is[i]) {
         for (int p = i * i; p <= n; p += i)is[p] = false;
      }
   }
   for (int i = 2; i <= n; i++)
      if (is[i])primes.push_back(i);
   return primes;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        pre[i] = pre[i - 1] + ar[i];
    }

    pr = sieve(n);  
    dp[0] = 0; dp[1] = 0;
    for(int i = 2; i <=n; i++)
    {
        dp[i] = dp[i-1];
        for(int j = 0; j <pr.size() && pr[j]<=i; j++){
            int st = i - pr[j]-1;
            if(st == -1){
                dp[i] = max(dp[i], pre[i]);
            }else{
                dp[i] = max(dp[i], dp[st]+(pre[i]-pre[st+1]));
            }
        }
    }
    for(int i =1; i <= n; i++){
        cout <<dp[i] << " ";
    };
    cout << endl;
    cout << dp[n] << endl;

    return 0;
}
