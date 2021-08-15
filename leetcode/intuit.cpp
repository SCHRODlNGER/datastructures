#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef map<ll,ll> mll;
#define endl '\n'
#define MOD 1000000007
template<typename T> void prllList(std::initializer_list<T> li) { 
    for (const auto & value: li) 
        std::cout << value << " "; } 
#define ifr(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ifrd(i,s,n,d) for(ll i=s;i<n;i+=d)
#define dfrd(i,n,d) for(ll i=n-1;i>=0;i-=d)
#define mt make_tuple
#define eb emplace_back
#define swap(a,b) tie(a,b)=mt(b,a)
#define watch(x) cout<<#x<<" " << (x)<<endl;
const double pi = 2 * acos(0.0);
const int INF = int(1e9);

    int minDifficulty(vector<int>& jj, int d) {
        
        int ans = 0;
        int n =jj.size();
        
        vector<vector<int> > dp(n, vector<int>(d+1));
        

        for(int i=0;i<n;i++){
            if(i==0) dp[i][0] = jj[i];
            else    dp[i][0] = max(dp[i-1][0], jj[i]);
        }
        for(int i=0;i<n;i++){
            
            for(int j = 1;j<d;j++){
                if(i<j){
                    dp[i][j] = -1;
                    continue;
                }
                dp[i][j] = INT_MAX;
                int maxi = jj[i];
                for(int k = i-1;k>=0;k--){
                    if(k<(j-1))
                        break;
                    maxi = max(maxi, jj[k+1]);
                    dp[i][j] = min(dp[i][j], dp[k][j-1] + maxi);
                }
                
            }
        }

        
        return dp[n-1][d-1];
        
    }

// Driver Code
int main()
{

    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
    int n,i,d;
    cin>>n;
    vector<int> a(n);
    ifr(i,0,n)   cin>>a[i];

    cin>>d;

    cout<<minDifficulty(a, d);
}