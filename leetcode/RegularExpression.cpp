class Solution {
public:
    
    
    bool isMatch(string s, string p) {
        
        int n = s.length();
        int m = p.length();
        bool f[n+1][m+1];
        
        f[0][0] = true;
        
        int c = 0;
        for(int i =1; i<=m;i++){
            if(p[i-1] == '*'){
                c++;
            }
            if( i%2 == 0 && c == i/2 )
                f[0][i] = true;
            else{
                f[0][i] = false;
            }
        }
        for(int i =1; i<=n;i++)     f[i][0] = false;

        // for(int i = 0; i<=m;i++)    cout<<f[0][i]<<" ";
        
        for(int i =1;i<=n;i++){
            
            cout<<f[i][0]<<" ";
            for(int j = 1;j<=m;j++){
                
                if(s[i-1] == p[j-1] || p[j-1] == '.'){
                    f[i][j] = f[i-1][j-1];
                }
                
                else if(p[j-1] == '*'){
                    f[i][j] = f[i][j-2];
                    if(s[i-1] == p[j-2] || p[j-2] == '.')
                        f[i][j] |= f[i-1][j];
                } 
                
                else{
                    f[i][j] = false;
                }
                // cout<<f[i][j]<<" ";
            }
            // cout<<endl;
            
        }
        return f[n][m];
        
    }
};