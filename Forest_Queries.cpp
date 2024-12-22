#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"


const int MAXN = 1001;
int pre[MAXN][MAXN] ={0};


using namespace std;

int main()
{
    fastio;
    int n,q; cin >> n >>q;
    char x;
    for(int i =1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> x;
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] +(x == '*' ? 1 : 0); 
        }
    };
    for(int i = 0 ; i < q; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
    };


    return 0;
}