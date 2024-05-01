#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    while(cin>>m >>n && (n != 0 || m != 0)){
        vector<vector<int>> v(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> v[i][j];
            }
        }
        int q;
        cin >> q;
        for (int c = 0 ; c< q ; c++){
            int lo , hi;
            cin >> lo >> hi;
            int max =  0;
            for(int i = 0; i < m; i++){
                auto k = lower_bound(v[i].begin(),v[i].end(),lo);
                if(k == v[i].end() || *k > hi) continue;
                int first = distance(v[i].begin(),k);
                for(int j = max; i + j < m && (first + j) < n && j < min(n, m); j++){
                    if (v[i+j][first+j] <= hi) max = max > j + 1 ? max : j + 1;
                }
            }
            printf("%d\n",max);
        }
        printf("-\n");
    }
    return 0;
}