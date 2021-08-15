#pragma GCC target("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>


#define MOD			1000000007
#define oo			INT_MAX/2
#define f			first
#define s			second
#define all(v)		v.begin(),v.end()
#define pair_int 	pair<int,int>
#define pair_ll 	pair<int,long long>
#define eb			emplace_back
#define pb			push_back

using namespace std;
using ll  = long long;
using lld = long double;
using vll = int64_t;

const int N = 1e5+1;
vector<pair_int> adj[N];

vector<int> dijkstra(int src){
    vector<int> dis(N);
    bool vis[N];

    fill(dis.begin(),dis.begin()+N,oo);
    fill(vis,vis+N,false);

    vis[src] = true;
    dis[src] = 0;

    auto cmp = [](const pair_int &p1,const pair_int &p2){return p1.s > p2.s;};

    priority_queue< pair_ll , vector<pair_int> , decltype(cmp) > pq(cmp);
    pq.push({src,0});
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
	if(vis[x.f]) continue;
        vis[x.f] = true;
        for(auto i : adj[x.f]){
            if(dis[i.f] >= dis[x.f]+i.s){
                dis[i.f] = dis[x.f]+i.s;
		pq.push({i.f,dis[i.f]});
            }
        }
    }

    return dis;
}

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);


    return 0;

}
