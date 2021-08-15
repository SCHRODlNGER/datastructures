
#include<bits/stdc++.h>

using namespace std;
using ll  = long long;

#define int ll
int n , two;
vector<int> par , cost , skill;
vector<pair<int,int>> ar; //(skill , cost)

int find(int x){
	return x == par[x] ? x : par[x] = find(par[x]);
}

bool unite(int a , int b){
	a = find(a);
	b = find(b);
	if(a == b)
		return false;
	par[b] = a;
	cost[a] += cost[b];
	skill[a] += skill[b];
	return true;
}


vector<vector<int>> dp;
int fun(int pos , int b){
	if(pos == ar.size())
		return 0;
	
	auto & res = dp[pos][b];
	if(res != -1)
		return res;
	
	int ans = 0;
	if(ar[pos].second <= b)
		ans = fun(pos + 1 , b - ar[pos].second) + ar[pos].first; 
	
	ans = max(ans , fun(pos + 1 , b));
	return res = ans;
}

signed main(){

	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> two;
	
	par.resize(n , 0);
	cost.resize(n , 0);
	skill.resize(n , 0);
	for(int i = 0 ; i < n ; i++) par[i] = i;
	
	for(int i = 0 ; i < n ; i++)
		cin >> skill[i] >> cost[i];

	int q ;
	cin >> q >> two;
	for(int i = 0 ; i < q ; ++i){
		int u , v;
		cin >> u >> v;
		u--;v--;
		unite(u , v);
	}

	for(int i = 0 ; i < n ; i++){
		int x = find(i);
		if(x == i) // root
			ar.emplace_back(skill[i] , cost[i]);
	}

	int budget;
	cin >> budget;
	dp.resize(ar.size() , vector<int>(budget + 2 , -1));
	cout << fun(0 , budget) << '\n';


    return 0;
}




