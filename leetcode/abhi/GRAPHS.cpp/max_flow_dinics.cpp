// O(EV*V) dinics algorithm

#include<bits/stdc++.h>

using namespace std; 

//directed edge u -> v
struct FlowEdge{
    int u, v;
    long long cap, flow = 0;
    /*
    * flow  -> current flow 
    * v     -> destination 
    * u     -> from edge
    * cap   -> capacity of edge
    */
    FlowEdge(){}
    FlowEdge(int uu, int vv, long long c) : u(uu), v(vv), cap(c){}
    long long rem_cap(){
        return cap - flow;
    }
};

struct Dinic{
    /*
    * n -> vertices count 
    * m -> edge counter 
    * s -> source 
    * t -> sink
    * adj[i][j] = id , id -> edge number , i -> src , j -> the index of edge
    */
    int n, m = 0 , s , t;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    vector<int> lvl, nxt;
    Dinic(int nn) : n(nn) , m(0){}
    Dinic(int nn , int ss , int tt) : n(nn) ,m(0) , s(ss) , t(tt){
        adj.resize(n);
        lvl.resize(n);
        nxt.resize(n);
        //nxt array is for shimon even and itai optimization for pruning dead ends during dfs .
    }

    void augment_flow(int id ,const long long val){
        edges[id].flow += val;
        edges[id ^ 1].flow -= val; 
    }

    void add_edge(int u , int v , long long cap){
        edges.emplace_back(u, v, cap);
        edges.emplace_back(v, u, 0);
        adj[u].push_back(m);
        adj[v].push_back(m+1);
        m += 2;
    }

    long long dfs(int u , long long flow){
        if(u == t)
            return flow;
        if(flow == 0)
            return 0;
        for (; nxt[u] < adj[u].size() ; nxt[u]++){
            int id = adj[u][nxt[u]];
            auto &e = edges[id];
            if(lvl[e.v] != lvl[u] + 1 || e.rem_cap() < 1)
                continue;
            if(long long z = dfs(e.v, min(flow, e.rem_cap()))){
                augment_flow(id,z);
                return z;
            }
        }
        return 0;
    }

    queue<int> q;
    bool bfs(){
        fill(lvl.begin(), lvl.end(), -1);
        lvl[s] = 0;
        q.push(s);
        
        while(!q.empty()){
            int par = q.front();
            q.pop();
            for(int id : adj[par]){
                if(lvl[edges[id].v] != -1 || edges[id].rem_cap() < 1)
                    continue;
                lvl[edges[id].v] = 1 + lvl[par];
                q.push(edges[id].v);
            }
        }
        return lvl[t] != -1;
    }

    const long long oo = 1e18;

    long long flow(){
        long long ans = 0;
        while(bfs()){
            fill(nxt.begin(), nxt.end(), 0);
            while(long long f = dfs(s , oo))
                ans += f;
        }
        return ans;
    }
      
};

//tester code

int32_t main(){
    freopen("in.txt","r", stdin);
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    Dinic d(n, 0, n - 1);
    while(m--){
        int u , v , c;
        cin >> u >> v >> c;
        u--;
        v--;
        d.add_edge(u, v, c);
        d.add_edge(v, u, c);
    }

    cout << d.flow() <<"\n";
    // cout << "DEB";
    return 0;

}