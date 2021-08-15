/*

Pick an arbitrary vertex of the graph root and run depth first search from it. Note the following fact (which is easy to prove):

Let's say we are in the DFS, looking through the edges starting from vertex v≠root. If the current edge (v,to) is such that none of the vertices to or its descendants in the DFS traversal tree has a back-edge to any of ancestors of v, then v is an articulation point. Otherwise, v is not an articulation point.

Let's consider the remaining case of v=root. This vertex will be the point of articulation if and only if this vertex has more than one child in the DFS tree.

*/

vector<vector<int>> adj;
vector<int> is_ap;

void dfs(int src , int par = -1){
    t++;
    in[src] = low[src] = t;
    vis[src] = 1;
    for(int i : adj[src]){
        if(i == par) continue;
        if(vis[i]){
            low[src] = min(low[src] , in[i]);
            continue;
        }
        dfs(i , src);
        low[src] = min(low[src] , low[i]);
        if(low[i] >= in[src] && par != -1)
            is_ap[src] = 1;
        //for bridges :: 
        //if(low[i] > in[src]) bridges.emplace_back(src , i);
        ++child;
    }

    if(par == -1 && child > 1)
        is_ap[src] = 1;
}

void find_cutpoints(){
    t = -1;
    is_ap.assign(n , 0);
    vis.assign(n , 0);
    in.assign(n , -1);
    low.assign(n , -1);
    for(int i = 0 ; i < n ; i++) if(!vis[i]) dfs(i);
    return;
}

