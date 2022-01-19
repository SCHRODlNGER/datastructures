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

unordered_map<int, vector<int> > m;

RangeFreqQuery(vector<int>& arr) {
        
    for(auto i:arr)
        m[i].push_back(int(i-arr.begin()));

    for(auto i:m){
        i.second.insert(0, -1);
        i.second.push_back(arr.size());
    }

}
    
int query(int left, int right, int value) {
    
    if(m.find(value) == m.end())
        return 0;
    
    int i = lower_bound(m[value].begin(), m[value].end(), left) - m[value].begin();
    int j = lower_bound(m[value].begin(), m[value].end(), right) - m[value].begin();

    return j - i;
}


int main()
{
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    #endif
    


}