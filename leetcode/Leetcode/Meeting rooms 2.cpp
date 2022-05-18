#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef map<ll,ll> mll;
#define endl '\n'
#define MOD 1000000007
// template<typename T> void prllList(std::initializer_list<T> li) 
#define ifr(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ifrd(i,s,n,d) for(ll i=s;i<n;i+=d)
#define dfrd(i,n,d) for(ll i=n-1;i>=0;i-=d)
#define mt make_tuple
#define eb emplace_back
#define swap(a,b) tie(a,b)=mt(b,a)
#define watch(x) cout<<#x<<" " << (x)<<endl;
const double pi = 2 * acos(0.0);
const int INF = int(1e9);

int noOfRooms(vector<vector<int> > a){
    vector<int> start ,end;

    

    for(auto i:a){
        start.push_back(i[0]);
        end.push_back(i[1]);
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int ans = 0;
    int rooms = 0;
    int end_itr = 0;

    for(int i=0;i<a.size();i++){
        if(start[i] < end[end_itr]){
            rooms++;
            }
        else{
            end_itr++;
        }
        ans = max(ans, rooms);
    }

    return ans;

}


int main(){

    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    int n;
    cin>>n;
    vector<vector<int> > a;
    for(int i=0;i<n;i++){
        int x, y;
        cin>>x>>y;
        a.push_back({x, y});
    }

    cout<<noOfRooms(a)<<endl;;

}
