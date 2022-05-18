double findMedianSortedArrays(vector<int>& nn, vector<int>& mm) {
    
    vector<int> *n = &nn;
    vector<int> *m = &mm;
    
    if(nn.size() > mm.size())
    {
        swap(n, m);
    }    
    
    int s = 0;
    int e = n->size();
    int n1 = n->size(), n2 = m->size();
    
    
    while(true){
        int px = (s + e)/2;
        int py = (n1 + n2 + 1)/2 - px;
        
        int l1 = px > 0? n->at(px-1): INT_MIN;
        int l2 = py > 0? m->at(py-1): INT_MIN;
        
        int r1 = px <n1? n->at(px):INT_MAX;
        int r2 = py<n2? m->at(py) : INT_MAX;
        
        if(l1 <= r2 && l2 <=r1){
            if((n1 + n2)%2 == 0){
                return (double)((max(l1, l2) + min(r1, r2)))/2;
            }
            else
                return (double)(max(l1, l2));
        }
        else if(l1 > r2)
            e = px - 1;
        else 
            s = px + 1;
    }
    
    return 0;
}