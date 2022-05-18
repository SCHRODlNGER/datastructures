int lengthOfLongestSubstring(string s) {
        int n = s.length();
        
        map<char, int> m;
        
        int i=0;
        int ans = 0;
        for(int j= 0;j<n;j++){
            if(m.find(s[j]) != m.end())
                i = max(i, m[s[j]] +1);
            ans = max(ans , j - i + 1);
            
            m[s[j]] = j;
        }
        return ans;
        
        
        
    }