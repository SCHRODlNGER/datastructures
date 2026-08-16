#include<bits/stdc++.h>
using namespace std;

set<int> s2;

string getNextClosestTime(string s) {
    char mini = '9';
    for(auto x: s) {
        if (x != ':') {
            s2.insert(x);
            mini = min(mini, x);
        }
    }
    if (s2.size() == 1) return s;
    // Find closest in minutes
    bool isFound = false;
    for(auto x: s2) {
        if (x > s[4]) {
            isFound = true;
            s[4] = x;
            break;
        }
    }
    if (isFound) {
        return s;
    }

    // Find closest in 10 minutes;
    for(auto x: s2) {
        if (x <= '6' && x > s[3]) {
            isFound = true;
            s[3] = x;
            s[4] = mini;
            break;
        }
    } 
    if (isFound) {
        return s;
    }

    // Find closest in hours;
    for(auto x: s2) {
        if (s[0] == '2') {
            if (x < 4 && s[1] < x) {
                isFound = true;
                s[1] = x;
                s[3] = mini;
                s[4] = mini;
                break;
            }
        }
        if (s[0] == '1' || s[0] == '0') {
            if (s[1] < x) {
                isFound = true;
                s[1] = x;
                s[3] = mini;
                s[4] = mini;
                break;
            }
        }
    }

    if (isFound) {
        return s;
    }

    // FInd closest in 10 hours

    for(auto x: s2) {
        if (x == '1' && s[0] < x) {
            isFound = true;
            s[0] = x;
            s[1] = mini;
            s[3] = mini;
            s[4] = mini;
            break;
        }
        if (x == '2' && s[0] < x) {
            for(auto y: s2) {
                if (y < 4) {
                    s[0] = x;
                    s[1] = y;
                    s[3] = mini;
                    s[4] = mini;
                    return s;
                }
            }
        }
    }

    // Find in next day

     s[0] = mini;
    s[1] = mini;
    s[3] = mini;
    s[4] = mini;
    
    return s;
}

int main() {

    string s = "02:09";

    string s2 = getNextClosestTime(s);
    cout<<s2<<endl;
    return 0;
}