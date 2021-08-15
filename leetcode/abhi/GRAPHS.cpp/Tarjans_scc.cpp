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
vector<int> val(N,0) , adj[N] , on_stack(N,0) , id(N,-1) , low(N,-1);

int cnt = 0;

void dfs(int src,stack<int> &st){
    low[src] = id[src] = cnt++;
    on_stack[src] = 1;
    st.push(src);
    
    for(int i : adj[src]){
        if(id[i] == -1)
            dfs(i,st);  
        if(on_stack[i] == 1)
            low[src] = min(low[src],low[i]);
    }
    
    if(low[src]==id[src]){      
        cout << "COMP ";
        while(true){
            auto p = st.top();
            st.pop();
            on_stack[p] = 0;
            cout << p+1 << " ";
            if(p==src) break; 
        }
        cout << "\n";
    }
}

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u ,v;
        cin >> u >> v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    stack<int> st;
    for(int i  = 0;i<n;i++){
        if(id[i]==-1)
            dfs(i,st);
    }

    return 0;
}
