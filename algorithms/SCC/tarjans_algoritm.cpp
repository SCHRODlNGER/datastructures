
#include<bits/stdc++.h>

void dfs(stack<int>& a, vector<vector<int>>& adj, vector<int>& d_num, vector<int>& d_min, int i, int& c) {
    d_num[i] = c;
    d_min[i] = c;
    a.push(i);
    c++;
    for(auto child: adj[i]) {
        if (d_num[child] == -1) {
            dfs(adj, d_num, d_min, child, c);
            d_min[i] = min(d_min[i], d_min[child]);
        }
        if (onStack[child] == 1) {
            d_min[i] = min(d_min[i], d_num[child]);
        }
    }

    if (d_num[i] == d_min[i]) {
        cout<<"SCC: ";
        while(true) {
            int p = a.top();
            a.pop();
            cout<<p<<" ";
            onStack[p] = 0;
            if (p == i) {
                break;
            }
        }
        cout<<endl;
    }
}

void printSCC(vector<vector<int>> adj, vector<vector<int>> SCC) {
    int n = adj.size();
    stack<int> a;
    vector<int> d_num(n, -1);
    vector<int> d_min(n, -1);

    int c = 0;
    for(int i = 0;i < n;i++) {
        if (d_num[i] == -1) {
            dfs(a, adj, d_num, d_min, i, c);
        }
    }
}

int main() {
    // Take input as adjacency list
    vector<vector<int>> adj;

    // SCC will added to list

    vector<vector<int>> SCC;

    printSCC(adj, SCC)

}