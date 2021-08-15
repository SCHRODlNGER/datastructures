#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class DSU{

//union find with path compression 
    public: 
        int n , comp;
        int *par,*sz;
        DSU(int k){
            par = new int[k];
            sz = new int[k];
            n = k;
            init();
        }

        void init(){
            for(int i=0;i<n;i++){
                par[i] = i;
                sz[i] = 1;
            }
            comp = n;
        }

        bool _union(int a,int b){
            int root1 = _find(a);
            int root2 = _find(b);
            if(root1==root2) return 0;
            if(sz[root1]<sz[root2]){
                sz[root2]+=sz[root1];
                par[root1] = par[root2];
            }else{
                sz[root1]+=sz[root2];
                par[root2] = par[root1];
            }
            comp--;
            return 1;
        }

        int _find(int a){
            int tmp = a;
            while(tmp!=par[tmp]){
                tmp = par[tmp];
            }
            while(a!=par[a]){
                int z = par[a];
                par[a] = tmp;
                a = z;
            }
            return a;
        }

        bool _is_connected(int a,int b){
            return _find(a)==_find(b);
        }
        
        int get_size(int i){
            return sz[_find(i)];
        }

};

int main(){

    DSU *d;
    d = new DSU(11);
    d->_union(3,4);
    for(int i=0;i<11;i++){
        cout << d->par[i] << "\n";
    }
    return 0;

}
