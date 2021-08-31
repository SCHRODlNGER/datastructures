
int exponentiation(int a, int b, int m){

    int ans = 1;
    int c = 1;
    while(b>0){
        if(b&1){
            ans = (ans * a) % m;
        }
        a = (a*a)%m;
        b = b>>1;
    }   
    return ans
}