int MinimumCost(vector<int> &a) {
        // write your code here
        priority_queue<int> q;

        for(auto i:a)
            q.push(-i);
        
        int ans = 0;
        while(q.size()>1){
            int x1 = q.top();
            q.pop();
            // cout<<x1<<" "<<q.top()<<endl;;
            x1 += q.top();
            q.pop();
            ans -= x1;
            q.push(x1);
        }
        return ans;


    }