        int A = 26;
    class Trie{
        public:
            vector<Trie*> c;
        
            Trie(): c(26, NULL){}
            bool isEnd = false;

            void addWord(string s, Trie* cur){
                
                for(int i=0;i<s.length();i++){
                    if(!cur->c[s[i] - 'a'])
                        cur->c[s[i] - 'a'] = new Trie();
                    
                    cur = cur->c[s[i] - 'a'];
                }

                cur->isEnd = true;
                return; 
                    
            }
        
    };

    
    Trie* root;
    
    vector<string> ans;
    bool isComposed(string s, Trie* root, int id, int sc, string s2){
        
        if(id == s.length()){ 
            
            ans.push_back(s2);
            return sc > 1;
        
        }
        
        Trie* cur = root;
        for(int i=id;i<s.length();i++){
            if(cur->c[s[i] - 'a']){
                cur = cur->c[s[i] - 'a'];
                if(cur->isEnd && isComposed(s, root, i+1, sc+1, s2 + " " + s.substr(id, i - id  + 1)))
                    continue;
            }
            else
                return false;
        }
        return false;
    }
    
    vector<string> wordBreak(string s, vector<string>& w) {
        root = new Trie();
        
        for(auto i:w){
            root->addWord(i, root);
        }
      
       
        isComposed(s, root, 0, 0, "");
        
        for(int i=0;i<ans.size();i++){
            ans[i] = ans[i].substr(1, ans[i].size()-1);
        }
        
        return ans;;
    }