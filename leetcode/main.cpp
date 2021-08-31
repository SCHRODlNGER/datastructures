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

bool f = false;

    set<string> s;
    int i2 = 0;
    void get_all(string cur, int i, int n, vector<string> &b){

        if(i == n && b[i2++] != cur){
            s.insert(cur);
            f = true;
            return;
        }
        if(i == n)
            return ;
        if(!f)
        {cur[i] = '0';
        get_all(cur, i+1, n ,b);}
        if(!f){
        cur[i] = '1';
        get_all(cur, i+1, n, b);
        }
    }
    
    string findDifferentBinaryString(vector<string> &b) {
        int n = b.size();
        string ss(n, '0');
        sort(b.begin(), b.end());
        get_all(ss, 0, n, b);
        for(auto i:s){
            cout<<i<<" ";
        }
        
        return *s.begin();
    }

int main()
{
    ios::sync_with_stdio(false);
    // #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif
    int i,j,n = 2;
    vector<string> v(n);
    ifr(i,0,n)
        cin>>v[i];
    cout<<findDifferentBinaryString(v);
}