 int findLeastNumOfUniqueInts(vector<int>& a, int k) {
        
        int n = a.size();
        map<int, int> m;
        
        for(auto i:a){
            if(m.find(i) == m.end()){
                m[i] = 0;
            }
            m[i] +=1;
        }
        
        vector<pair<int, int> > v;
        for(auto i:m){
            v.push_back({i.second, i.first});
        }
        
        sort(v.begin(), v.end());
        
        int s = 0;
        for(int i=0;i<v.size();i++){
            
            s += v[i].first;
            if(s > k){
                return v.size() - i;
            }
        }
        return 0;
        
        
    }