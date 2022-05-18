 vector<vector<string>> suggestedProducts(vector<string>&a, string b) {
        
        sort(a.begin(), a.end());
    
        int n = b.length();
        
        string s2 = "";
        string s1 = "";
        for(int i=0;i<3000;i++)
            s1+='z';
        
        int l = 0;
        int r = a.size();
        
        auto t1 = a.begin(), t2 = a.begin(), t3 = a.begin(), t4 = a.begin();
        advance(t1 , l);
        advance(t2, r);
        vector<vector<string> > ans;
        
        for(int i = 0;i<n;i++ ){
            
            s2 += b[i];
            s1[i] = b[i];
            
            l = lower_bound(t1, t2, s2) - a.begin();
            r = upper_bound(t1, t2, s1) - a.begin();
            int c = 3;
            vector<string> temp;
            for(int i = l;i<r && c > 0;i++){
                
                temp.push_back(a[i]);
                c--;
                
            }
            
            ans.push_back(temp);
            
            
        }
        
        return ans;
        
        
    }