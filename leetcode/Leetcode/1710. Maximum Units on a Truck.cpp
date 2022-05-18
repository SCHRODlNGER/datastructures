int maximumUnits(vector<vector<int>>& a, int b) {
    
    auto compare = [](vector<int> d, vector<int> e){
        if(d[1] != e[1])
        return d[1] > e[1];
        
        return d[0] > e[0];
    };
    
    
    sort(a.begin(), a.end(), compare);
    
    int ans = 0;
    for(auto i: a){
        // cout<<i[0]<<" "<<i[1]<<endl;
        if(b == 0)
            break;
        ans += i[1] *( b < i[0] ? b : i[0]);
        // cout<<ans<<endl;
        b -= (b < i[0] ? b : i[0]);
    }
    
    return ans;
        
}