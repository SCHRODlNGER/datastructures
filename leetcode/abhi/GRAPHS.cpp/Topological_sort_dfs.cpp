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

stack<int> st;
vector<int> state(N,0);
vector<int> adj[N];

bool dfs(int src){
    //cross Edge
    if(state[src]==2)
        return false;

    //back Edge
    if(state[src]==1)
        return true;
    
    state[src] = 1;

    for(int i : adj[src])  dfs(i);
    
    st.push(src);
    state[src] = 2;
    return false;
}



int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        u--;v--;
        adj[u].push_back(v);
    }    

    bool has_cycle = false;
    for(int i = 0;i<n;i++)
        if(state[i] == 0) has_cycle|=dfs(i);

    if(has_cycle) {
        cout << "CYCLE DETECTED !";
        return 0;
    }
    
    while(!st.empty()){
        cout << st.top()+1 << " ";
        st.pop();
    }

    return 0;
}