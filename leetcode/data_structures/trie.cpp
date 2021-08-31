#include<bits/stdc++.h>
using namespace std;
#define CHAR_SIZE  128

class Trie{


    public:
    
    bool isLeaf;
    Trie* characters[CHAR_SIZE];



    Trie(){
        this->isLeaf = false;
        for(int i = 0;i<CHAR_SIZE;i++)
            characters[i] = nullptr;
    }

    void insert(string s){
        Trie* cur = this;

        for(int i =0;i<s.length();i++){
            if(cur->characters[s[i]] == nullptr)
                cur->characters[s[i]] = new Trie();
            cur = cur->characters[s[i]];
        }
        cur->isLeaf = true;
    }

    bool search(string s){

        Trie* cur = this;
        for(int i =0;i<s.length(); i++){
            if(cur->characters[s[i]] == nullptr)
                return false;
            cur = cur->characters[s[i]];
        }
        return cur->isLeaf;
    }

    

};