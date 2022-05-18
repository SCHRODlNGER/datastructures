    int maxSubArray(vector<int>& a) {
        
        int m1 = INT_MIN;
        int m2 = 0;
        
        for(auto i:a){
            m2 += i;
            m1 = max(m1, m2);
            m2 = max(0, m2);
        }
        return m1;
        
    }