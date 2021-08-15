#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the runningMedian function below.
 */
vector<double> fun(vector<int> a) {
    multiset<double> min_heap; // for storing the right half
    multiset<double , greater<double>> max_heap; // for storing the left half
    
    //if no if elements processed is odd then max_heap or the left heap will store 1 more element than the right heap and thats the median
    //if no of elements processed is even then max_heap stores equal elements to min_heap
    //in that case median is half of the 2 top elements of both heaps

    auto balance_out = [&](){
        if(min_heap.empty() || max_heap.empty())
            return;
            int r = *min_heap.begin();
            int l = *max_heap.begin();
        if(l > r){
            min_heap.erase(min_heap.find(r));
            max_heap.erase(max_heap.find(l));
            max_heap.insert(l);
            min_heap.insert(r);
        }
        return;
    };

    auto get_median = [&]()->double{
        if(min_heap.size() == max_heap.size())
            return (*min_heap.begin() + *max_heap.begin()) / 2;
        if(min_heap.size() > max_heap.size())
            return *min_heap.begin();
        return *max_heap.begin();
    };

    vector<double> ans;
    for(int i : a){
        min_heap.insert(i);
        balance_out();
        ans.emplace_back(get_median());
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> ar(n);
    for(int i = 0 ;i < n ; i++) cin >> ar[i];
    for(auto i : fun(ar)){
        cout << fixed << setprecision(1) << i << "\n";
    }

    return 0;
}
