#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,c,d;
        cin>>n>>c>>d;
        vector<int> a(n*n);
        for(int i=0;i<n*n;i++){
            cin>>a[i];
        };
        int min = *min_element(a.begin(),a.end());
        vector<int> K(n*n);
        K[0] = min;
        for(int i = 1; i< n*n; i++){
            if(i % n == 0){
                K[i] = K[i-n] + c;
            }else{
                K[i] = K[i-1] + d;
            }
        };
        // for(int i = 0; i < n*n; i++){
        //     cout << K[i] << " ";
        // }
        std::sort(a.begin(), a.end());
        std::sort(K.begin(), K.end());

        if(std::equal(a.begin(), a.end(), K.begin())){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}