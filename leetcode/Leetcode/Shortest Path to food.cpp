#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef map<ll,ll> mll;
#define endl '\n'
#define MOD 1000000007
template<typename T> void prllList(std::initializer_list<T> li) { 
#define ifr(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ifrd(i,s,n,d) for(ll i=s;i<n;i+=d)
#define dfrd(i,n,d) for(ll i=n-1;i>=0;i-=d)
#define mt make_tuple
#define eb emplace_back
#define swap(a,b) tie(a,b)=mt(b,a)
#define watch(x) cout<<#x<<" " << (x)<<endl;
const double pi = 2 * acos(0.0);
const int INF = int(1e9);


int shortest(vector<vector<char> > a){

    int n = a.size();
    int m = a[0].size();
    vector<vector<int > > vis(n, vector<int>(m, 0));

    pair<int, int> p;
    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(a[i][j] == '*'){
                p = {i, j};
                break;
            }
        }
        if(p)
            break;
    }

    queue<pair<int, pair<int, int> > > q;
    q.push({0, p});
    vis[p.first][p.second] = 1;
    int ans = INT_MAX;

    while(q.size()){

        pair<int, pair<int, int> > x = q.front();
        q.pop();
        int c = x.first;
        int i = x.second.first;
        int j = x.second.second;

        if(a[i][j] == '#'){
            ans = min(ans, c);
        }
        else{
            if( i-1 >=0 && a[i-1][j] != 'X' && vis[i-1][j] == 0 ){
                vis[i-1][j] = 1;
                q.push({c+1, {i-1, j}});
            }

            if( i+1 < n && a[i+1][j] != 'X' && vis[i+1][j] == 0 ){
                vis[i+1][j] = 1;
                q.push({c+1, {i+1, j}});
            }
            if( j-1 >=0 && a[i][j-1] != 'X' && vis[i][j-1] == 0 ){
                vis[i][j-1] = 1;
                q.push({c+1, {i, j-1}});
            }
            
            if( j+1 <m && a[i][j+1] != 'X' && vis[i][j+1] == 0 ){
                vis[i][j+1] = 1;
                q.push({c+1, {i, j+1}});
            }

        }


    }

    return ans;




}

int main(){

    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("../ignore/input.txt","r",stdin);
        freopen("../ignore/output.txt","w",stdout);
    #endif

    int i, j;
    cin>>i>>j;

    
    vector<vector<char> > v(i, vector<int> (j));

    for(int i2=0;i2<i;i2++){
        for(int j2 = 0; j2 < j;j2++){
            cin>>v[i][j];
        }
    } 

    cout<<shortest(v);

}
