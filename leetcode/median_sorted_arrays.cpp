#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& small_arr, vector<int>& big_arr) {
    
    
    vector<int>& temp = small_arr;
    
    if(small_arr.size() > big_arr.size()){
        small_arr.swap(big_arr);
    }
    
    int start = 0, end = small_arr.size();
    int partx, party, l1, l2, r1, r2;
    
    double ans;

    while(true){
        
        partx = (start+end)/2;
        party = (small_arr.size() + big_arr.size() + 1)/2 - partx;

        cout<<start<<" "<<end<<" "<<partx<<" "<<party <<" "<<big_arr.size()<<endl;

        // <<" "<<small_arr[partx]<<" "<<big_arr[party] 
        l1 = partx > 0?small_arr[partx - 1]:INT_MIN;
        l2 = party > 0?big_arr[party - 1]:INT_MIN;

        r1 = partx < small_arr.size()?small_arr[partx ]:INT_MAX;
        r2 = party < big_arr.size()?big_arr[party ]:INT_MAX;

        if(l1 <= r2 && l2 <= r1 ){
            if((small_arr.size() + big_arr.size())%2 ==0  ){
                ans = double(max(l1, l2) + min(r1, r2))/2;
            }
            else{
                ans = double(max(l1, l2));
            }
            break;
        }
        else if( l1 > r2 ){
            
            end = partx - 1;
            
        }
        else{
            start = partx + 1;
        }
        
    }
    return ans;
}


signed  main(){

  

    int n,m;
    cin>>n>>m;
    vector<int>a(n), b(m);

    for(int i =0 ;i<n;i++){
        cin>>a[i];
    }
    for(int i =0 ;i<m;i++){
        cin>>b[i];
    }
    cout<<findMedianSortedArrays(a, b);

}