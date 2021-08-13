#include <bits/stdc++.h>
using namespace std;
#define ifr(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int * func(int *arr, int n, int *rep, int m){

    if(arr == NULL) 
        return NULL;
    else if(rep == NULL)
        return arr;

    sort(rep, rep + m);

    int j = m-1;
    for(int i=0;i<n;i++){
        if(j >=0 && rep[j] > arr[i])
            arr[i] = rep[j--];
    }

    return arr;
}

signed main(){
    int n,m,i;
    cin>>n>>m;
    int a[n], b[m];
    ifr(i,0,n)
        cin>>a[i];
    ifr(i,0,m)
        cin>>b[i];
    
    int* c = func(a, n,b,m);

    ifr(i,0,n)
        cout<<a[i];
}