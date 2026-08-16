#include<bits/stdc++.h>
using namespace std;

vector<int> dis;
vector<int> low;
vector<int> par;

vector<vector<int>> bridges;


void dfs(vector<vector<int>>& adj, int par) {
    static int time = 0;
    dis[par] = time;
    low[par] = time;
    time ++;

    for(auto child: adj) {
        if (dis[child] == -1) {
            parent[child] = par;
            dfs(adj, child);
            low[par] = min(low[par], low[child]);
        }
        else if (child != parent[par]) {
            low[par] = min(low[par], dis[child]);
        }
        if (low[child] > dis[par]) {
            bridges.push_back({par, child});
        }
    }
}

void findBridges(vector<vector<int>>& adj) {
    int n = adj.resize();
    dis.resize(n, -1);
    low.resize(n, -1);
    par.resize(n, -1);

    for(int i=0;i<n;i++) {
        if (dis[i] == -1) {
            dfs(adj, i);
        }
    }
}

int main() {
    int n = 5;
    vector<vector<int>> adj;

    findBridges(adj);

}