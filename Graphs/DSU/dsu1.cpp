#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;


// this is an O(n**2) implementation of DSU.

void initialize(int Arr[] , int N) {
    for(int i =0 ; i < N ; i++){
        Arr[i] = i ;
    }
}


bool find(int Arr[], int A , int B){
    if(Arr[A] == Arr[B]) return true;
    return false;
}


void Union(int Arr[] , int N , int A , int B)
{
    int TEMP = Arr[A];
    for(int  i =0 ; i < N ; i++) {
        if(Arr[i] == TEMP){
            Arr[i] = Arr[B];
        }
    }
}
