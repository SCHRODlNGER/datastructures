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
    
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){

        ListNode* p1 = l1, *p2 = l2;
        ListNode* ans = NULL;
        ListNode* cur = ans;

        int carry = 0;
        while(p1!= NULL || p2 != NULL || carry!=0){
            int sum = carry;
            if(p1!=NULL){
                sum+=p1->val;
                p1 = p1->next;
            }
            if(p2!=NULL){
                sum+=p2->val;
                p2 = p2->next;
            }

            carry = sum/10;
            sum = sum%10;
            if(ans == NULL){
                ans = new ListNode();
                ans->val = sum;
                cur = ans;
            }
            
            else{
                ans->next = new ListNode();
                ans= ans->next;
                ans->val = sum;
                
            }

        }
        return cur;
    }

    
    int main()
    {
        ios::sync_with_stdio(false);
        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
        #endif
        
    
    
    }