int findCircleNum(vector<vector<int>>& a) {
    vector<int> par;
    int n;
    function<int(int)>  find = [&](int x){
        return par[x] == x?x: par[x] = find(par[x]);
    };
    
    auto unite = [&](int a, int b){
        a = find(a);
        b = find(b);
        if(a != b)
            par[a] = b;
        return;
    };
    
    n = a.size();
    par.resize(n, 0);
    
    for(int i=0;i<n;i++)
        par[i] = i;
    
    for(int i=0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(a[i][j] == 1){
                unite(i, j);
            }
        }
    }
    
    int c = 0;
    for(int i=0;i<n;i++)
        c += par[i] == i?1:0;
    
    
    return c;
}