    long long int mod_mul(long long a, long long b, long long mod){
        
        long long int res = 0;
        a = a%mod;
        
        while(b){
            if(b&1)
                res = (res + a)%mod;
            
            a = (2*a)%mod;
            
            b = b>>1;
        }
        
        return res;
        
    }
    
    int maxArea(int h, int w, vector<int>& a, vector<int>& b) {
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int w_max = 0;
        int prev = 0;
        a.push_back(h);
        b.push_back(w);
        
        for(auto i:a){
            w_max =  max(w_max,i - prev);
            prev = i;
        }
        
        int h_max = 0;
        prev = 0;
        for(auto i:b){
            h_max = max(h_max, i - prev);
            prev = i;
        }
        int mod = (int)(pow(10,9) + 7);
        return (int)mod_mul(h_max, w_max, mod);
        
        
    }