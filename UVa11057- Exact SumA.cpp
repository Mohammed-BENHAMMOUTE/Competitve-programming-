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
        sort(v.begin(),v.end());
        int a= 0;
        int b = n-1;
        int book1,book2;
        while(a < b){
            if(v[a] + v[b] < m){
                a++;
            }else if(v[a] + v[b] > m){
                b--;
            }else{
                book1 = v[a];
                book2 = v[b];
                a++;
                b--;
            }
        }
        cout << "Peter should buy books whose prices are " << book1 << " and " << book2 << ".\n\n";
    }
    return 0;
}