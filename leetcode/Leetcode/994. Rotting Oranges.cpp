int orangesRotting(vector<vector<int>>& a) {
    
    queue<pair<pair<int, int> , int> > q;
    
    int m = a.size();
    int n = a[0].size();
    for(int i=0;i<m;i++){
        for(int j = 0; j < n;j++){
            if(a[i][j] == 2){
                q.push({{i, j}, 0});
            }
        }
    }
    
    int ans = 0;
    
    while(q.size()){
        
        int c = q.front().second;
        int x = q.front().first.first;
        int y = q.front().first.second;
        
        q.pop();
        a[x][y] = 2;
        
        ans = max(ans, c);
        
        if(x +1 < m && a[x+1][y] == 1){
            a[x+1][y] = 2;
            q.push({{x+1, y}, c+1});
        }
        
        
        if(x -1 >= 0 && a[x-1][y] == 1){
            a[x-1][y] = 2;
            q.push({{x-1, y}, c+1});
        }
        if(y + 1 < n && a[x][y+1] == 1){
            a[x][y+1] = 2;
            q.push({{x, y+1}, c+1});
        }
        if(y -1 >= 0 && a[x][y-1] == 1){
            a[x][y-1] = 2;
            q.push({{x, y-1}, c+1});
        }
        
    }
    
    for(auto i:a){
        for(auto j:i)
            if(j == 1)
                return -1;
    }
    return ans;
    
    
    
    
    
}