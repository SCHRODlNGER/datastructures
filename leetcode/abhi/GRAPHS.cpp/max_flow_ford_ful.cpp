//Time :: O(max_flow * E)

#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 10;

vector<int> adj[N];
int cap[N][100];
vector<int> vis(N, 0);

int vis_cnt;
int dfs(int src ,int flow , const int &sink){
    if(src == sink)
        return flow;
    // cout << "src" << " " << src << "\n";
    vis[src] = vis_cnt;
    for(auto i : adj[src]){
        if(vis[i] == vis_cnt || cap[src][i] <= 0)
            continue;
        int z = dfs(i, min(cap[src][i], flow) , sink);
        if(z > 0){
            cap[i][src] += z;
            cap[src][i] -= z;
            return z;
        }
    }
    return 0;
}

int max_flow(int src , int sink){
    int z = 1; 
    vis_cnt = 0;
    int flow = 0;
    int oo = INT_MAX;
    
    while(z){
        vis_cnt++;
        z = dfs(src, oo , sink);
        flow += z;
    }
    return flow;
}

void add(int src , int des , int c){
    adj[src].push_back(des);
    adj[des].push_back(src);
    cap[src][des] = c;
    cap[des][src] = 0;
}

int main(int argc, char const *argv[])
{
    memset(cap, 0, sizeof(cap));

    add(0, 1, 10);
    add(0, 2, 8);
    add(1, 2, 2);
    add(1, 3, 5);
    add(4, 3, 8);
    add(2, 4, 10);
    add(4, 5, 10);
    add(3, 5, 7);

    cout << max_flow(0 , 5);

    return 0;
}
