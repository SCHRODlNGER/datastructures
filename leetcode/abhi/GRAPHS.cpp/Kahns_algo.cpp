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
vector<int> adj[N];
vector<int> in(N,0);

int n,m;
bool cycle = false;
vector<int> fun(){
    queue<int> q;

    //to print in lexicographical order just use priority queue
    
    for(int i=0;i<n;i++){
        if(in[i]==0) q.push(i);
    }

    vector<int> ord;

    while(q.size()>0){
        if(q.empty()){
            cycle = true;//cycle is present;
            break;
        }

        auto p = q.front();
        ord.push_back(p);

        q.pop();
        
        for(int i : adj[p]){
            in[i]--;
            if(in[i]==0)
                q.push(i);
        }
        
    }
    return ord;
}



int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n >> m;
    queue<int> q;

    while(m--){
        int u,v;
        cin >> u >> v;
        u--;v--;
        adj[u].push_back(v);
        in[v]++;
    }

    for(int i : fun()){
        cout << i+1 << " ";
    }

    cout << "\n";

    return 0;
}