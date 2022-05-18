vector<vector<int>> kClosest(vector<vector<int>>& c, int k) {
    
    auto compare = [](vector<int> a, vector<int> b){
        return a[0] * a[0] + a[1]*a[1] < b[0] * b[0] + b[1]*b[1];
    };
    
    nth_element(c.begin(), c.begin() + k, c.end(), compare);
    
    vector<vector<int> > ans;
    
    for(int i=0;i<k;i++)
        ans.push_back({c[i][0], c[i][1]});
    return ans;
    
}