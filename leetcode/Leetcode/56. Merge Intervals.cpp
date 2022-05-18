vector<vector<int>> merge(vector<vector<int>>& a) {
    sort(a.begin(), a.end());
    
    vector<vector<int> > ans;
    int m1 = a[0][0], m2 = a[0][1];
    int n = a.size();
    for(int i=1;i<n;i++){
        if(a[i][0] > m2){
            ans.push_back({m1, m2});
            m1 = a[i][0];
            m2 = a[i][1];
        }
        else{
            m2 = max(m2, a[i][1]);
        }
    }
    
    ans.push_back({m1, m2});
    
    return ans;
    
    
}