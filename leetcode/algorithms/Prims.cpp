vector<int> prims(vector<vector<int>> adj){

    vector<bool> mst(n, false);
    int n = adj.size();
    vector<int> keys(n, INT_MAX);
    keys[0] = 0;

    auto minIndex = [&](){
        int min = INT_MAX, minIndex;
        for(int i=0;i<n;i++){
            if(mst[i] == false && keys[i] < min){
                min = keys[i], minIndex = i;
            }
        }
        return minIndex;
    };

    vector<int> parents;
    parents[0] = -1; 

    for(int i=0;i<n-1;i++){

        int idx = minIndex();
        mst[idx] = true;

        for(auto x: adj[idx]){
            if(x.second < keys[x.first])
                parent[x.first] = idx, keys[x.first] = x.second;
        }

    }

    return parents;

}