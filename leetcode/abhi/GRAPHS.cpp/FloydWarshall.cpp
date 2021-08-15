int dp[n][n];
int nxt[n][n]; // stores the shortest path

void fw(){

    for(int k = 0 ;k < n ;k++)
        for(int i = 0 ;i < n ;i++)
            for(int j =0 ;j < n ;j++)
                if(dp[i][j] > dp[i][k] + dp[k][j])
                    dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j]),
                    nxt[i][j] = nxt[i][k];
    
    check_for_neg_cycle();
    return ;
}

void check_for_neg_cycle(){
    // execute fw apsp algorithm a second time but
    // this time if the distance anbe improved 
    // set the optimal distance to be -oo.
    // Every edge(i , j) marked with -oo is either 
    // part of or reaches into a negative cycle.
    
    for(int k = 0 ; k < n ; k++)
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                if(dp[i][j] > dp[i][k] + dp[k][j])
                    dp[i][j] = -oo , nxt[i][j] = -1;

    return ;
}



