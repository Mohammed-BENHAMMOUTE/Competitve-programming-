#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        };
        int left = k/2 + k%2;
        int right = k/2;
        int cnt = 0;
        int i = 0;
        while(i < n && left>=a[i]){
            left-=a[i];
            cnt++;
            i++;
        };
        if(i <n) a[i] -= left;
        int j = n-1;
        while( j>=i && right>=a[j]){
            k-=a[j];
            cnt++;
            j--;
        };        
        std ::cout << cnt << endl;
    }
    return 0;
}