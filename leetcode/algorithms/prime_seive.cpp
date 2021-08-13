
#include<bits/stdc++.h>
using namespace std;
vector<long long> prime;

void get_prime(int n){
    bool b[n+1];
    memset(b, true, sizeof(b));

    for(int i=2;i*i<n;i+=1){
        // cout<<"x";

        if(b[i]){
            
            for(int j = i*i ; j<n; j+=i){
                b[j] = false;
            }
        }
    }

    for(int i =2;i<n;i++){
        if(b[i])
            prime.push_back(i);
    }

}
