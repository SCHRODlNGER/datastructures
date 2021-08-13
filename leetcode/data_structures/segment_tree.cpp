#include<bits/stdc++.h>
using namespace std;
#define watch(x) cout<<#x<<": " << (x)<<endl;


class SegementTree{

    // 0 based indexing

    public:
    int len;
    int n;
    vector<int> seg;
    SegementTree(vector<int> &a, int n){
        this->len = 2 * ( (int)pow( 2, (int)ceil( log2(n) )) ) - 1;
        
        // this->seg.resize(this->len, INT_MIN);
        this->seg.resize(this->len, INT_MAX);
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

        // this->seg[pos] = max(this->seg[2*pos + 1], this->seg[2*pos + 2]);
        this->seg[pos] = min(this->seg[2*pos + 1], this->seg[2*pos + 2]);

    }

    int rec_range(int qlow, int qhigh, int low, int high, int pos){

        if(qlow <= low && qhigh >= high)
            return this->seg[pos];
        
        if(qlow > high || qhigh < low){
            return INT_MAX;
            // return INT_MIN;
        }

        int mid = (low + high)/2;
        return min( rec_range(qlow, qhigh, low, mid, 2*pos + 1), rec_range(qlow, qhigh, mid + 1, high, 2*pos +2));
        // return max( range(qlow, qhigh, low, mid, 2*pos + 1), range(qlow, qhigh, mid + 1, high, 2*pos +2);

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

        rec_update(val, index, low, mid, 2*pos + 1);
        rec_update(val, index, mid +1, high, 2*pos + 2);
        this->seg[pos] = min( this->seg[2*pos + 1] , this->seg[2*pos + 2] );

        return;
    }


    void update(int val, int index){

        if(index >= this->n)    {
            // cout<<"Invalid Update";
            return;}

        rec_update(val, index, 0, this->n-1, 0);

    }

};
