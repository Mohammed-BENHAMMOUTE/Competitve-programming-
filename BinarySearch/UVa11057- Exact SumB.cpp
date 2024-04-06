#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(cin >> n){
        vector<int> v(n);
        int k;
        for(int i = 0; i < n; i++){
            cin >> k;
            v[i] = k;
        }
        int m;
        cin >> m;
        int max = 1000000;
        int book1,book2;
        sort(v.begin(),v.end());
        for(int i = 0; i < n; i++){
            if(v[i] < m){
                if(binary_search(v.begin()+i+1,v.end(),m-v[i])){
                    if(abs(v[i]-(m-v[i])) < max){
                        max = abs(v[i]-(m-v[i]));
                        book1 = v[i];
                        book2 = m-v[i];
                    }
                }
            }
        }
        cout << "Peter should buy books whose prices are " << book1 << " and " << book2 << ".\n\n";
    }
    return 0;
}