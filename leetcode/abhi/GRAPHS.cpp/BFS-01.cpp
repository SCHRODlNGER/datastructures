
void bfs_01(int src , int N){
    
    dequeu<int>  dq;
    vector<int>  dis(N);
    vector<bool> vis(N , false);
    
    dq.push_back(src);
    vis[0] = true;

    while(!dq.empty()){
        int o = dq.front():
        dq.pop_front();
        for(auto p : adj[o]){
            if(vis[p.first]) continue;

            vis[p.first] = true;
            
            if(p.second == 0){
                dq.push_front(p.first);
            }
            else{
                dq.push_back(p.second);
            }
        }
    }
    return ;
}
