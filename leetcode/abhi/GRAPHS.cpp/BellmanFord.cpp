vector<int> bf(vector<edge> &e , int src , int n) {
    vector<int> dp(n , oo) ;
    dp[src] = 0;
    for(int i= 0 ;i < v - 1;i++){
        for(auto ee : e)
            dp[ee.v] = min(dp[ee.u] + ee.wt , dp[ee.v]); 
    }
    // repeat to detect negative edges::
    for(int i = 0 ;i < v - 1; i++){
        for(auto ee : e)
            if(dp[ee.v] < dp[ee.u] + ee.wt)
            dp[ee.v] = -oo;
    }
    return dp;
}
