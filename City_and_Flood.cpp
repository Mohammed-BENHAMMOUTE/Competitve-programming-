#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
using namespace std;

const int MAXN = 1e5 +1;
int arr[MAXN] = {0};
int Size[MAXN] = {0};

void initialize(int n) {
    for(int i = 1; i <= n ; i++){
        arr[i] = i;
        Size[i] =1;
    }
}

int root(int a) {
    while(arr[a] != a){
        arr[a] = arr[arr[a]];
        a = arr[a];
    }
    return a;
}

void Union(int A , int B) {
    int root_a = root(A);
    int root_b = root(B);

    if(root_a == root_b) return;


    if(Size[root_a] < Size[root_b]){
        Size[root_b] += Size[root_b];
        arr[root_a] = root_b;
    }else{
        Size[root_a] += Size[root_b];
        arr[root_b] = root_a;
    }
}
long long countConnected(int n) {
    set<int> components;
    for(int i =1 ; i <=n ; i++)
    {
        components.insert(root(i));
    }
    return components.size();
}
int main () {
    int n; cin >> n;
    int k; cin >> k;
    initialize(n);
    for(int i = 0 ; i < k ; i++) {
        int x, y ; cin >> x >> y;
        Union(x , y);
    }
    cout << countConnected(n) << endl;
}
