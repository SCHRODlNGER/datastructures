int minNumberofColors(vector<vector<int> > &adj){

    int n = adj.size();
    vector<int> count(n, 0), color(n, 1);

    queue<int> q;

    for(int i=0;i<n;i++){
        for(auto destNode: adj[i]){
            count[destNode]++;
        }
    }

    for(int i=0;i<n;i++){
        if(count[i] == 0){
            q.push(i);
        }
    }

    while(q.size()){
        int idx = q.top();
        q.pop();

        for(auto x: adj[idx]){

            count[x]--;
            if(count[x] == 0){
                q.push(x);
            }
            if(colors[x] <= colors[idx]){
                colors[x] = colors[idx] + 1;
            }

        }

    }

    int minColors = -1;
    for(auto x: colors)
        minColors = max(minColors, x);

    return minColors;
}