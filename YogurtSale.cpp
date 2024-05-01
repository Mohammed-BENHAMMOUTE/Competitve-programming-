#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        int price = 0 ;
        if(2 *a > b ){
            price = n%2 ==0 ? n/2*b : (n/2)*b + a;
        }else{
            price = n*a;
        };
        cout<<price<<endl;
    }
    return 0;
}