#pragma GCC target("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>


#define MOD			1000000007
#define f			first
#define s			second
#define all(v)		v.begin(),v.end()
#define pair_int 	pair<int,int>
#define pair_ll 	pair<int,long long>

using namespace std;
using ll  = long long;
using lld = long double;
using vll = int64_t;

const int N = 1e5+1;
vector<int> g[N],gr[N];

int n,m;
stack<int> st;
vector<bool> vis(N,false);

void dfs1(int src){
    vis[src] = true;
    for(int i : g[src]){
        if(vis[i]) continue;
        dfs1(i);
    }
    st.push(src);
}

vector<int> comp(N,0);
vector<int> tmp;
int cnt = 0;

void dfs2(int src){
    tmp.push_back(src);
    comp[src] = cnt;
    vis[src] = true;
    for(int i : gr[src]){
        if(vis[i]) continue;
        dfs2(i);
    }
}


int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n >> m;
    while(m--)
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    for(int i =0;i<n;i++){
        if(!vis[i]) dfs1(i);
    }

    fill(vis.begin(),vis.begin()+n,false);
 

    while(!st.empty()){
        auto top = st.top();
        st.pop(); 

        if(vis[top]) continue;
        
        tmp.clear();
        dfs2(top);
        cout << tmp.size() << "\n";
        cnt++;
    }

    for(int i =0;i<n;i++){
        cout << comp[i] << " ";
    }

    cout << cnt << '\n';


    return 0;

}