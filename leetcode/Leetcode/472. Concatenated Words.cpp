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
    
    void print(Trie* root){
        for(int i=0;i<A;i++){
            if(root->c[i]!=NULL){
                cout<<i<<" ";
                print(root->c[i]);
            }
        }
        if(root->isEnd)
            cout<<endl;
    }
    
    Trie* root;
    bool isComposed(string s, Trie* root, int id, int sc){
        
        if(id == s.length()) return sc >1;
        
        Trie* cur = root;
        for(int i=id;i<s.length();i++){
            if(cur->c[s[i] - 'a']){
                cur = cur->c[s[i] - 'a'];
                if(cur->isEnd && isComposed(s, root, i+1, sc+1))
                    return true;
            }
            else
                return false;
        }
        return false;
    }
    
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& w) {
        
        root = new Trie();
        
        for(auto i:w){
            root->addWord(i, root);
        }
      
        vector<string> ans;
        
        for(auto i:w){
            if(isComposed(i, root, 0, 0))
                ans.push_back(i);
        }
        
        
        return ans;;
    }