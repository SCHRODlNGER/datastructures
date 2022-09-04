vector<int> BellManFord(vector<vector<int>> edges, int src, int n){
    vector<int> dist(n, INT_MAX), oldDist;
    dist[src] = 0;
    int t = n-1;
    while(t--){

        oldDist = dist;

        for(auto edge: edges){

            int s = edge[0], d = edge[1], t = edge[2];

            if( oldDist[s] != INT_MAX && oldDist[s] + t < oldDist[d]){
                dist[d] = oldDist[s] + t;
            }
            

        }


    }
    return dist;
}