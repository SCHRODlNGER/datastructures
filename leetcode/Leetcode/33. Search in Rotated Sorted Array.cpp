int search(vector<int>& a, int b) {
    int l = 0;
    int r = a.size() - 1;
    
    while(l<=r){
        int mid = (l+r)/2;
        
        if(a[l] == b)return l;
        if(a[r] == b) return r;
        if(a[mid] == b) return mid;
        
        if(a[l] > a[mid]){
            if(a[mid] < b && a[r] > b ){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        else{
            if(a[mid] > b && a[l] < b)
                r = mid - 1;
            else
                l = mid + 1;
        }
        
    }
    
    return -1;
}