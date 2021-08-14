class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int len = obstacles.size();
        vector<int> ans(len);
        vector<int> minVal(len+2);
        int maxAns = 0;
        for (int i = 0 ; i != len ; i++) {
           if (maxAns == 0 || minVal[maxAns-1] <= obstacles[i])  {
               // append at the end
               minVal[maxAns++] = obstacles[i];
               ans[i] = maxAns;
           }
            else {
                int lb = -1, ub = maxAns-1;
                // Find the first index that strictly larger than obstacles[i]
                // (lb, ub]
                while (lb+1 < ub) {
                    int mid = (lb+ub)/2;
                    if (minVal[mid] <= obstacles[i]) {
                        lb = mid;
                    }
                    else {
                        ub = mid;
                    }
                }
                minVal[ub] = obstacles[i];
                ans[i] = ub+1;
            }
        }
        return ans;
    }
};