#include<bits/stdc++.h>
#define pb push_back

using namespace std;

vector<int> dis, low, parent;

vector<bool> isArticulation;

int discoveryTime = 0;


void dfs(vector<vector<int>>& adj, int i) {
    int c = 0;
    dis[i] = discoveryTime;
    low[i] = discoveryTime;
    discoveryTime++;

    for(auto child: adj[i]) {
        parent[child] = i;
        if (dis[child] == -1) {
            dfs(adj, child);
            c++;
            low[i] = min(low[i], low[child]);
        }
        else if (child != parent[i]){
            low[i] = min(low[i], dis[child]);
        }
        if (low[child] >= dis[i]) {
            isArticulation[i] = true;
        }
    }
    if (c > 1 && parent[i] == -1) {
        isArticulation[i] = true;
    }
}


int findArticulationPoints(vector<vector<int>>& adj) {
    int n = adj.size();
    dis.resize(n, -1);
    low.resize(n, -1);
    parent.resize(n, -1);
    isArticulation.resize(n, false);
    discoveryTime = 0;

    for(int i=0;i<n;i++) {
        if (dis[i] == -1) {
            dfs(adj, i);
        }
    }

    for(int i = 0;i < n;i++) {
        if (isArticulation[i]) 
            cout<<i<<" ";
    }
    cout<<endl;
}


int main() {

    // Adjacency matrix
    int n = 5;
    vector<vector<int>> adj(n);
    adj[0].pb(2);
	adj[2].pb(0);
	adj[0].pb(3);
	adj[3].pb(0);
	adj[1].pb(0);
	adj[0].pb(1);
	adj[2].pb(1);
	//adj[2].pb(4);
	//adj[4].pb(2);
	adj[1].pb(2);
	adj[3].pb(4);
	adj[4].pb(3);

    findArticulationPoints(adj);

}