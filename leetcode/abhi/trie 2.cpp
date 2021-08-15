#include<bits/stdc++.h>
using namespace std;
namespace auto_complete_feature_using_trie{
    struct node{
        unordered_map<char , node *> hm;
        int cnt = 0;
        bool is_end = 0;
        node(){cnt = 0 , is_end = 0;}
    };

    void add(node * root , string str){
        node * tmp = root;
        for(auto i : str){
            if(tmp -> hm.count(i)){
                tmp = tmp -> hm[i];
                continue;
            }
            tmp -> hm[i] = new node();
            tmp = tmp -> hm[i];
        }
        tmp -> cnt++;
    }

    void dfs(node * root , string str , vector<string> & ans){
        for(int i = 0 ; i < (root -> cnt) ; i++)
            ans.push_back(str);
        for(auto [CHAR , NODE] : root -> hm)
            dfs(NODE , str + "" + CHAR , ans);
    }

    vector<string> auto_complete(node * root , string str , int idx = 0){
        node * tmp = root;
        vector<string> ans ;
        for(auto i : str){
            if(tmp -> hm.count(i))
                tmp = tmp -> hm[i];
            else
                return ans; //word not present
        }
        dfs(tmp , str , ans);
        return ans;
    }

}

struct Trie{
    struct node{
        map<char , node *> hm;
        int cnt = 0; // number of words ending at this node.
    };

    node * head;
      
    Trie(){head = new node();}

    void push(string str){
        node * tmp = head;
        for(auto i : str){
            if(!tmp -> hm.count(i))
                tmp -> hm[i] = new node();
            tmp = tmp -> hm[i];
        }
        tmp -> cnt++;
    }

    bool contains(string str){
        node * tmp = head;
        for(auto i : str){
            if(!tmp -> hm.count(i))
                return false;
            tmp = tmp -> hm[i];
        }
        return tmp -> cnt ? true : false;
    }
    
    void dfs(node * tmp , string str , vector<string> & res){
        for(int i = 0 ; i < tmp -> cnt ; i++)
            res.push_back(str);
        for(auto [CHAR , NODE] : tmp -> hm)
            dfs(NODE , str + "" + CHAR , res);
    }

    vector<string> get_words_with_prefix(string str){
        node * tmp = head;
        vector<string> res ;
        for(auto i : str){
            if(tmp -> hm.count(i))
                tmp = tmp -> hm[i];
            else{
                //str not found
                return res;
            }

        }
        dfs(tmp , str , res);
        return res;
    }
    
    //function to print all the strings in the trie in sorted order.
    void dfs(node * tmp , string str = ""){
        for(int i = 0 ; i < tmp->cnt ; i++){
            cout << str << ' ';
            //incase we dont want duplicates we will break at first iteration
        }
        
        for(auto [CHAR , NODE] : tmp -> hm)
            dfs(NODE , str + "" + CHAR);
    }

    void print(){
        node * tmp = head;
        dfs(tmp , "");
    }

};

namespace string_matching_suffix{
    
    void solve(const vector<string> & ar , string p){
        Trie tree;
        for(auto i : ar){
            reverse(i.begin() , i.end());
            tree.push(i); 
        }
        reverse(p.begin() , p.end());
        for(auto i : tree.get_words_with_prefix(p)){
            reverse(i.begin() , i.end());
            cout << i << " ";
        }
        cout << '\n';
    }

    void solve(){
        vector<string> s = {"wideworld", "webworld", "classicword", "world", "worldclass"};
        string p = "world";
        solve(s , p);
    }

}

namespace sorting_array_of_strings{
    void solve(){
        vector<string> ar = {"abc" , "xyz" , "abcd" , "bcd" , "abc"};
        Trie tr;
        for(auto i : ar) tr.push(i);
        tr.print();  
    }
}

namespace count_different_substrings{
    struct SuffixTrie{
        struct node {
            map<char , node *> hm;
            int cnt = 0;
            node(){}
        };

        node * head;

        SuffixTrie(string str=""){      //O(n*n) build
            head = new node();
            for(int i = 0 ; i < str.size() ; i++){
                auto x = str.substr(i);
                push(x);
            }
        }

        void push(const string & s){
            node * tmp = head;
            for(const auto & i : s){
                if(!tmp -> hm.count(i))
                    tmp -> hm[i] = new node();
                tmp = tmp -> hm[i];
            }
            tmp -> cnt++;
        }

        void dfs(node * root , int & tt){
            tt++;
            for(auto [CHAR , NODE] : root -> hm)
                dfs(NODE , tt);
        }

        bool search_pattern(const string & pat){ // O(m) 
            node * tmp = head;
            for(auto i : pat){
                if(tmp -> hm.count(i))
                    tmp = tmp -> hm[i];
                else 
                    return false;
            }
            return true;
        }

        int count_distinct(){
            node * tmp = head;
            int tt = 0;
            dfs(tmp , tt);
            return tt;
        }
    };

    void solve(){
        string str = "ababa";
        SuffixTrie t(str);
        cout << t.count_distinct() << '\n';
        return;
    }
    
}

main(){
   // using namespace auto_complete_feature_using_trie;
   // node * head = new node();
   // vector<string> str = {"hello" , "dog" , "hel" , "hell" , "cat" , "a" , "hel" , "help" , "helps" , "helping"}; 
   // for(auto o : str) add(head , o);
   // auto ans = auto_complete(head , "hel");
   // for(auto x : ans) cout << x << " " ;
   // cout << '\n';
   using namespace count_different_substrings;
   solve();
}
