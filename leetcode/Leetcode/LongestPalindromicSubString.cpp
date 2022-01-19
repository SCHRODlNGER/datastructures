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

pair<int, int> even(string s, int n, int n2){
        
        int p1 = n;
        int p2 = n+1;
        
        while( p1>=0 and p2<n and s[p1] == s[p2] ){
            p1--;
            p2++;
        }
        return {p1, p2};
        
    }
    
pair<int, int> odd(string s, int n, int n2){
    int p1 = n-1;
    int p2 = n+1;
    
    while(p1>=0 and p2<n2 and s[p1] == s[p2]){
        p1--;
        p2++;
    }
    return {p1, p2};
}
    
string longestPalindrome(string s) {
    
    string ans = s.substr(0, 1);
    int maxLen = 1;
    
    int n = s.length();
    if(n == 0)
        return "";
    
    for(int i=0;i<n-1;i++){
        pair<int, int> e = even(s, i, n);
        pair<int, int> o = odd(s, i, n);

        if(e.first+1 < e.second-1 && maxLen < e.second - e.first - 1 ){
        ans = s.substr( e.first+1 , e.second - e.first - 1 );    
        maxLen =  e.second - e.first - 1;
        }
        
        if(o.first+1 < o.second-1 && maxLen < o.second - o.first - 1 ){

        ans = s.substr( o.first+1 , o.second - o.first - 1 );     
        maxLen =  e.second - e.first - 1;         
        }
            
    }
    return ans;
}


int main()
{
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    #endif
    


}