    #include <iostream>  
    #include <functional>  
    #include <algorithm>  
    #include <cstring>  
    #include <vector>  
    #include <string>  
    #include <cstdio>  
    #include <cmath>  
    #include <queue>  
    #include <stack>  
    #include <deque>  
    #include <set>  
    #include <map>  
    using namespace std;  
    typedef long long ll;  
      
    #define INF 0x3fffffffffffffff  
      
    const ll mod = 1e9 + 7;  
    const int maxn = 5e5 + 5;  
      
    ll n, a, b, t;  
    ll pri[maxn];  
    char x[maxn];  
      
    bool check(int mid)  
    {  
        ll i, j, k;  
        ll sum1, sum2;  
        for (i = 1; i <= mid; i++)  
        {  
            sum1 = pri[i] + (pri[n] - pri[n - (mid - i)]);  
            sum2 = min((i - 1)*a * 2 + (mid - i)*a, (i - 1)*a + (mid - i)*a * 2);  
            if (sum1 + sum2 <= t)  
            {  
                return true;  
            }  
        }  
        return false;  
    }  
      
    void solve()  
    {  
        int i, j, k;  
        scanf("%I64d%I64d%I64d%I64d", &n, &a, &b, &t);  
        scanf("%s", x + 1);  
      
        for (i = 1; i <= n; i++)  
        {  
            pri[i] = pri[i - 1] + 1 + (x[i] == 'w' ? b : 0);  
        }  
        int le = 0, ri = n, mid;  
        while (le < ri)  
        {  
            mid = (le + ri + 1) / 2;  
            if (check(mid))  
            {  
                le = mid;  
            }  
            else  
            {  
                ri = mid - 1;  
            }  
        }  
        printf("%d", le);  
    }  
      
    int main()  
    {  
      
        solve();  
      
        return 0;  
    }  