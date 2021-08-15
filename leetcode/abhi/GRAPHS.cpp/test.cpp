
#include<bits/stdc++.h>
#define int ll
#define f			first
#define sz(a)       ((int)(a).size())
#define s			second
#define all(v)		v.begin(),v.end()
#define pii 		pair<int,int>
#define vpii 		vector<pii>
#define eb			emplace_back
#define pb			push_back
#define fo(i,n)		for(int i=0;i<n;i++)
#define Fo(i,k,n)	for(int i=k;i<n;i++)
#define vi			vector<int>

using namespace std;
using ll  = long long;
using lld = long double;

const int oo = 0x3f3f3f3f;
const ll MOD = 1000000007;

//int fun( vector<vector<int>> & dp , vector<int> & ar , int i , int p ){
//    if(i == ar.size())
//        return 0;
//
//    auto & res = dp[i][p];
//    if(res != (-1e9))
//        return res;
//
//    if(p == 1) 
//        return res = max(fun(dp , ar , i + 1 , 0) , ar[i] + fun(dp , ar , i + 1 , 1));
//    return res = fun(dp , ar , i + 1 , 1) + ar[i]; 
//}
//
//int solve(vector<int> & ar){
//    int n = ar.size();
//    vector<vector<int>> dp(n , vector<int>(3 , -1e9));
//    return fun(dp , ar , 0 , 1);    
//}
//
signed main(){

#ifndef ONLINE_JUDGE
	freopen("in.txt" , "r" , stdin);
#endif
	ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> ar(n + 1 , 0);
    fo(i , n) cin >> ar[i];
    vi dp[2];
    
    dp[0].resize(n + 2 , 0);
    dp[1].resize(n + 2 , 0);
    
    dp[1][0] = ar[0];
    dp[0][0] = 0;

    Fo(i , 1 , n){
        cout << ar[i] << " ";
        dp[0][i] = ar[i] + dp[1][i - 1];
        dp[1][i] = max(dp[0][i - 1] , dp[1][i - 1]); 
        cout << dp[0][i] << " " << dp[1][i] << '\n';
    }
    
    cout << max(dp[0][n - 1] , dp[1][n - 1]);

    return 0;
}

