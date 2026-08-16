#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<string> dict = {"deer", "door", "cake", "card"};

    set<string> s;
    for(auto x: dict) {
        s.insert(x);
    }

    vector<vector<set<int>>> m(26, vector<set<int>>(27));

    for(auto x: s) {
        int first = x[0] - 'a';
        if (x.size() == 1) {
            m[first][26].insert(1);
            continue;
        }
        int last = x[x.size() - 1] - 'a';
        m[first][last].insert(x.size() - 2);
    }

    vector<string> words = {"dear", "cart", "cane", "make"};

    for(auto word: words) {
        int first = word[0] - 'a';
        if (word.size() == 1) {
            cout<<(!m[first][26].size() ? "true" : "false")<<endl;
            break;
        }
        int last = word[word.size() - 1] - 'a';
        cout<<((m[first][last].find(word.size() - 2) == m[first][last].end()) ? "true" : "false")<<endl;
    }

    return 0;
}