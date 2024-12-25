#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
using namespace std;

const double EPS = (1e-7);
int dcmp(double x, double y) {
    return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;
}

const int MAX = 100;
bool valid(int i, int j) { return 1; }
char maze[MAX][MAX];
bool vis[MAX][MAX];

int n, e;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> topsort;
vector<int> start, finish;
bool anyCycle = 0;
int timer = 0;







void dfs(int node) {
    visited[node] = true;

    for(int i = 0; i < adj[node].size(); ++i) {
        int child = adj[node][i];
        if (!visited[child])
            dfs(child);
    }

    topsort.push_back(node);
}
















int ConnectedComponenetsCnt() {
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(!visited[i]) {
            dfs(i);
            cnt++;
        }
    }
    return cnt;
}

void dfs_EdgeClassification(int node) {
    start[node] = timer++;

    for(int i = 0; i < adj[node].size(); ++i) {
        int child = adj[node][i];
        if (start[child] == -1)
            dfs_EdgeClassification(child);
        else {
            if(finish[child] == -1)
                anyCycle = 1;
            else if(start[node] < start[child])
                ;   // Forward Edge
            else
                ;   // Cross Edge
        }
    }

    finish[node] = timer++;
}

int cnt = 0;
void cntReachalbleCells(int r, int c) {
    if(!valid(r, c) || maze[r][c] == 'X' || vis[r][c] == 1)
        return;

    vis[r][c] = 1;
    cnt++;

    cntReachalbleCells(r, c-1);
    cntReachalbleCells(r, c+1);
    cntReachalbleCells(r-1, c);
    cntReachalbleCells(r+1, c);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("c.in", "rt", stdin);
#endif

    cin >> n >> e;

    adj = vector<vector<int>>(n);
    visited = vector<bool>(n);
    start = vector<int>(n, -1);
    finish = vector<int>(n, -1);

    for(int i = 0; i < e; ++i) {
        int from, to;
        cin >> from >> to;
        adj[from-1].push_back(to-1);
    }

    for(int i = 0; i < n; ++i) {
        if(start[i] == -1)
            dfs_EdgeClassification(i);
    }

    cout << anyCycle;

    return 0;
}
