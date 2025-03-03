#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
using namespace std;
const int MAXN = 1e5;
int Arr[MAXN] = {0};
int Size[MAXN] = {1};


void initialize(int Arr[] , int N) 
{
    for(int i =0 ; i < N ; i++) {
        Arr[i] = i;
    }
}


int root(int Arr[] , int i){
    while(Arr[i] != i) {
        i = Arr[i];
    }
    return i;
}

// we can further optimize this root function using path Compression
int root_compress (int Arr[] , int i) {
    while(Arr[i] != i )
    {
        Arr[i] == Arr[Arr[i]];
        i = Arr[i];
    }
    return i;
}


void  Union(int Arr[] , int A , int B) {
    int root_a = root(Arr , A);
    int root_b = root(Arr , B);
    Arr[A] = root_b;
}

// weighted union operation 
void weighted_Union(int Arr[] , int size[], int A ,int B)
{
    int root_a = root_compress(Arr, A);
    int root_b = root_compress(Arr, B);
    if(size[root_a]  < size[root_b]){
        Arr[root_a]  = Arr[root_b];
        Size[root_b] += Size[root_a]; 
    }else{
        Arr[root_b] = Arr[root_a];
        Size[root_a] += Size[root_b];
    }
}

bool find(int Arr[] , int A , int B) {
    if(root(Arr, A) == root(Arr ,B)) return true;
    return false;
}