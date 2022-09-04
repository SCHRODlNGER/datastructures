vector<int> kruskals(vector<vector<int>> edges, int n){

    vector<int> parents(n);
    vector<int> par(n);

    for(int i=0;i<n;i++){
        par[i] = i;
    }

    function<int(int)> find = [&](int x){
        return par[x] == x? x : par[x] = find(par[x]);
    };

    auto union = [&](int a, int b){
        a = find(a);
        b = find(b);
        par[b] = a;
    };

    auto comp = [](const vector<int> &a, const vector<int> &b){

        return a[2] < b[2];
    };
    sort(edges.begin(), edges.end(), comp);

    int n1 = n-1;

    for(auto edge: edges){

        if(!n1)
            break;
        if(find(edge[0]) == find(edge[1])){
            continue;
        }
        union(edge[0], edge[1]);
        parents[edge[1]] = edge[0];
        n1--;
    }

    return parents;
}