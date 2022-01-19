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


int bin_search(vector<int> &t, vector<int> &v, int l, int r, int k){

    while(r - l > 1)
    {
        int m = l + (r - l)/2;
        if(v[t[m]] >= k)
            r = m;
        else
            l = m;
    }

    return r;

}

int lis(vector<int> v){
    int n = v.size();

    vector<int> t(n , 0);

    int l = 1;
    t[0] = 0;
    for(int i=1;i<n;i++){
        if(v[i] < v[t[0]]){
            t[0] = i;

            }
        else if(v[i] > v[t[l-1]]){
            t[l++] = i;
}
        else{

            int x = bin_search(t, v, -1, l-1, v[i]);
            t[x] = i;
        }
    }
    return l;

}