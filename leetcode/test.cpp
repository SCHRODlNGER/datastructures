#include<bits/stdc++.h>
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

int func(int n, vector<int> h, int s){
    multiset<int> ss;
    for(int i=0;i<s;i++)
        ss.insert(h[i]);
    
    int ans = *ss.begin();
    int c = 0;
    for(int i = s;i<n;i++){
        ss.erase(ss.find(h[c++]));
        ss.insert(h[i]);


        ans = max(ans, *ss.begin());
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif


    int n,s, i,j;
    cin>>n>>s;
    vector<int> v(n);
    ifr(i,0,n)
        cin>>v[i];
    cout<<func(n,v,s)<<endl;

    

}