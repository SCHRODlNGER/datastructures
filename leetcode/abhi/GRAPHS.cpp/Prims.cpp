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

const int N = 0;

vector<pair_int> adj[N];


int* prims(){
    auto cmp = [](const pair_int &p1 , const pair_int &p2){ return p1.second > p2.second;};
    priority_queue<pair_int,vector<pair_int>,decltype(cmp)> pq(cmp);
    
    pq.push({0,0});
    
    int dis[N];bool vis[N];
    
    fill(dis,dis + N , oo);
    fill(vis,vis + N, false);

    dis[0] = 0;
    vis[0] = true;
    
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        vis[x.f] = true;
        for(auto i : adj[x.f]){
            if(vis[i.f]) continue;
            if(dis[i.f] >= i.s){
                dis[i.f] = i.s;
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