#include<bits/stdc++.h> 
using namespace std;

class fenwickTree2d {
    public:
    vector<vector<int>> s;


    fenwickTree2d(vector<vector<int>> a) {
        s.resize(a.size() + 1, vector<int>(a[0].size() + 1));
        for(int i=0;i<a.size();i++) {
            for(int j=0;j<a[0].size();j++) {
                update(i + 1, j + 1, a[i][j]);
            }
        }
    }

    int getSum(int l, int r) {
        int sum = 0;
        while(l > 0) {
            int c = r;
            while(c > 0) {
                sum += s[l][c];
                c = getParent(c);
            }
            l = getParent(l);
        }
        return sum;
    }

    void update(int l, int r, int val) {
        while(l < s.size()) {
            int c = r;
            while(c < s[0].size()) {
                s[l][c] += val;
                c = getNext(c);
            }
            l = getNext(l);
        }
    } 

    int getParent(int index) {
        return index - (index & -index);
    }

    int getNext(int index) {
        return index + (index & -index);
    }
};


int mod = 1e9+7;
    int func(vector<int>& filterCost, vector<int>& startTime, vector<int>& endTime, int discount) {
        int n = filterCost.size();
        map<int, vector<pair<int, int>>> m;
        for(int i=0 ; i < n; i++) {
            m[startTime[i]].push_back({0, filterCost[i]});
            m[endTime[i] + 1].push_back({1, filterCost[i]});
        }

        int processed = 0, curr = 0;
        long long result = 0, sum = 0;
        
        int prevDay = -1;

        for(auto &[day, ops]: m) {

            if (prevDay != -1) {
                int days = day - prevDay;

                if (sum > discount && n - processed == curr) {
                    result += (1LL * days * discount) % mod;
                    result %= mod;
                }
                else {
                    result += (1LL * days * sum) % mod;
                    result %= mod;
                }
            }
            
            for(auto op: ops) {
                if (op.first == 0) {
                    curr++;
                    sum += op.second;
                }
                else {
                    curr--;
                    processed++;
                    sum -= op.second;
                }
            }
            
            prevDay = day;
        }

    }


int main() {
    vector<int> f = {2, 3, 4};
    vector<int> s = {1, 1, 2};
    vector<int> e = {2, 3, 4};
    int d = 6;
    cout<<func(f, s, e, d)<<endl;
}