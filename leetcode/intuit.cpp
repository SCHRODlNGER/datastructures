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


class SegementTree{

    // 0 based indexing

    public:
    int len;
    int n;
    vector<int> seg;
    SegementTree(vector<int> &a, int n){
        this->len = 2 * ( (int)pow( 2, (int)ceil( log2(n) )) ) - 1;
        
        this->seg.resize(this->len, INT_MIN);
        // this->seg.resize(this->len, INT_MAX);
        this->n = n;

        create_segment(a, n, 0, n-1, 0);
    }

    void create_segment(vector<int> &a, int n, int low, int high, int pos){

        if(low == high){
            this->seg[pos] = a[low];
            return;}

        int mid = (low + high)/2;
        create_segment(a, n, low, mid, 2*pos + 1);
        create_segment(a, n, mid+1, high, 2*pos + 2);

        this->seg[pos] = max(this->seg[2*pos + 1], this->seg[2*pos + 2]);
        // this->seg[pos] = min(this->seg[2*pos + 1], this->seg[2*pos + 2]);

    }

    int rec_range(int qlow, int qhigh, int low, int high, int pos){

        if(qlow <= low && qhigh >= high)
            return this->seg[pos];
        
        if(qlow > high || qhigh < low){
            // return INT_MAX;
            return INT_MIN;
        }

        int mid = (low + high)/2;
        // return min( rec_range(qlow, qhigh, low, mid, 2*pos + 1), rec_range(qlow, qhigh, mid + 1, high, 2*pos +2));
        return max( rec_range(qlow, qhigh, low, mid, 2*pos + 1), rec_range(qlow, qhigh, mid + 1, high, 2*pos +2));

    }

    int range(int ql, int qh){

        
        if(qh >= this->n || ql < 0)    {
            // cout<<"Invalid Range";
            return -1;}

        return rec_range(ql, qh, 0, this->n - 1, 0);
    }
    void rec_update(int val, int index, int low, int high, int pos){

        if(index < low || index > high)
            return;
        if(index == low && high == low)
        {
            this->seg[pos] = val;
            return;
        }

        int mid = (low + high)/2;

        if(low <= index &&  mid >=index)
            rec_update(val, index, low, mid, 2*pos + 1);
        else
            rec_update(val, index, mid +1, high, 2*pos + 2);

        // this->seg[pos] = min( this->seg[2*pos + 1] , this->seg[2*pos + 2] );
        this->seg[pos] = max( this->seg[2*pos + 1] , this->seg[2*pos + 2] );


        return;
    }


    void update(int val, int index){

        if(index >= this->n)    {
            // cout<<"Invalid Update";
            return;}

        rec_update(val, index, 0, this->n-1, 0);

    }

};


vector<int> longestObstacleCourseAtEachPosition(vector<int> & o){

    int n = o.size();
    vector<int> ans(n);

    set<int> ss;
    for(auto i:o)
        ss.insert(i);
    map<int, int> m;
    int c =0;
    for(auto i:ss){
        m[i] = c++;
    }
    
    vector<int> a(c, 0);

    SegementTree s(a, c);

    for(int i=0;i<n;i++){

        int aa = s.range( 0, m[o[i]] );

        ans[i] = aa + 1;

        s.update( ans[i], m[o[i]] ) ;
        
    }

    return ans;

}


// Driver Code
int main()
{

    #ifndef

    #
    int n = int(pow(10, 5));
    // cin>>n;
    vector<int> o(n);
    ifr(i,0,n){
        // cin>>o[i];
        o[i] = i;
    }
    vector<int> ans = func(o);
    for(auto itr:ans)
        cout<<itr<<" ";
}