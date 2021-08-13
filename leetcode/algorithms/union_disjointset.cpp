#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
vector<int>par;

int find(int x){
    return x == par[x]? x : par[x] = find(par[x]);
}

void unite(int a, int b ){

    a = find(a);
    b = find(b);
    if(a==b)
        return;
    par[b] = a;
    return;
}

signed main(){

    int n,m;
    cin>>n>>m;

    vector< vector<int> > v(n,vector<int> (m));

    for(int i=0;i<n;i++)
        for(int j =0;j<m;j++)
            cin>>v[i][j];
    cout<<endl;
    N = n*m;
    
    par.resize(N,0);

    for(int i=0;i<N;i++)    par[i] = i;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(v[i][j] == 0)
                continue;
                if(i > 0 && v[i-1][j] == 1) unite( i*m + j, (i-1)*m + j );
                // if(i > 0 && j > 0 && v[i-1][j-1] == 1) unite( i*m + j, (i-1)*m + j-1 );
                if(j > 0 && v[i][j-1] == 1) unite( i*m + j, (i)*m + j-1 );
                
                if(i+1 <n && v[i+1][j] == 1) unite( i*m + j, (i+1)*m + j );
                if(j+1 <m && v[i][j+1] == 1) unite( i*m + j, (i)*m + j+1 );
                // if(i+1 <n && j+1 <m && v[i+1][j+1] == 1) unite( i*m + j, (i+1)*m + j+1 );

                // if(i+1<n && j >0 && v[i+1][j-1] == 1) unite( i*m + j, (i+1)*m + j-1 );
                // if(i>0 && j + 1<m && v[i-1][j+1] == 1) unite( i*m + j, (i-1)*m + j+1 );
        }
    }


    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++) cout<<find(i*m + j)<<" ";
        cout<<endl;
    }

    int ans = 0;
    for(int i =0;i<N;i++){
        if( v[i/m][i%m] == 1 &&  find(i) == i )
            ans++;
    }
    cout<<ans;
    

    


}