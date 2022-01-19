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


int lengthOfLongestSubstring(string s) {
    int hash[256] = {-1};
    int n = s.length();
    int ans = 1;
    if(n == 0)
        return 0;

    for(int i =0;i<n;i++){
        memset(hash, -1, sizeof(hash));
        hash[int(s[i])] = 1;
        for(int j= i+1; j<n;j++){
            if(hash[int(s[j])] == 1){
                ans = ans>j-i?ans:j-i;
                break;
            }
            else{
                hash[int(s[j])] = 1;
                ans = ans>j-i+1?ans:j-i+1;
            }
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