vector<int> par;
    
    int find(int x){
        return par[x] == x ? x : par[x] = find(par[x]);
    }
    
    void unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b)
            return;
        par[b] = a;
    }
    
    int maxEvents(vector<vector<int>>& a) {
        
        
        int n;
        for(auto i:a){
            n = max(n, i[1]);
        }
        par.resize(n+1);
        for(int i=0;i<n+1;i++){
            par[i] = i;
        }
        
        auto comp = [](vector<int> a, vector<int> b){
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0]>b[0];
        };
        
        sort(a.begin(), a.end(), comp );
        
        int ans = 0;
        for(auto i:a){
            int x = find(i[1]);;
            if(x!=0 && x >= i[0]){
                
                unite(x-1, x);
                ans ++;
                
            }
     
        }
        
        return ans;
        
    }