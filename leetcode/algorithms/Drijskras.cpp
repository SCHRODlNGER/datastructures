

vector<int> drijkstras(vector<vector<pair<int, int> >> adj, int src, int noOfNodes){

    vector<int> dist(n);
    vector<bool> spt(n);

    auto minIndex = [&](){

        int min = INT_MAX, minIndex;
        for(int i=0;i<n;i++){
            if(!spt[i] && dist[i] < min)
                min = dist[i], minIndex = i;
        }
        return minIndex;
    };

    for(int i=0;i<n;i++){
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    for(int i=0;i<n-1;i++){

        int idx = minIndex();

        spt[idx] = true;

        for(auto x: adj[idx]){
            if(!spt[x.first] && dist[x.first] > dist[idx] + x.second)
                dist[x.first] = dist[idx] + x.second;
        }

    }
    return dist;
}
