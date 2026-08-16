#include<bits/stdc++.h>
using namespace std;

class BIT {
    public: 
    vector<int> bitArr;

    BIT(int n) {
        bitArr.resize(n + 1, 0);
    }

    int getNext(int index) {
        int andd = -index & index;
        return andd + index;
    }


    void update(int updatedValue, int index) {
        while(index < bitArr.size()) {
            bitArr[index] += updatedValue;
            index = getNext(index);
        }
    }

    int getParent(int index) {
        int andd = -index & index;
        return index - andd;
    }

    int getValue(int index) {
        if (index == 0) return 0;
        return bitArr[index] + getValue(getParent(index));
    }
};


int main() {
    vector<int> bulbs = { 1, 3, 2 };
    int k = 1;
    BIT b = BIT((int)bulbs.size());
    unordered_set<int> turnedOnBulbs;
    int ans = INT_MAX;
    for(int i=0; i < bulbs.size(); i ++ ) {
        b.update(1, bulbs[i] + 1);
        int lefty = bulbs[i] - k - 1;
        int righty = bulbs[i] + k + 1;
        turnedOnBulbs.insert(bulbs[i]);
        if (lefty >= 0 && turnedOnBulbs.find(lefty) != turnedOnBulbs.end()) {
            cout<<lefty<<" "<< bulbs[i]<<endl;
            cout<<b.getValue(bulbs[i] + 1) <<" x "<< b.getValue(lefty + 1)<<endl;
            if (((b.getValue(bulbs[i] + 1) - b.getValue(lefty + 1)) == 1))
                ans = min(ans, i + 1);
        }
        if (righty < bulbs.size() && turnedOnBulbs.find(righty) != turnedOnBulbs.end()) {
            cout<<righty<<" "<< bulbs[i]<<endl;
            
            if (((b.getValue( righty + 1 ) - b.getValue(bulbs[i] + 1)) == 1))
                ans = min(ans, i + 1);
        }
    }
    cout<<ans<<endl;
    return 0;
}