
#define MOD 1000000007;
int exp(int a, int b){

    if(a == 0)
        return 0;
    if(b == 0)
        return 1;
    long long y;
    if(b%2 == 0){
        y = exp(a, b/2);
        y = (y *y)%MOD;
    }
    else {
        y = a%MOD;

        y = (y * exp(a, b-1))%MOD;
    }
    return (int)(y + MOD)%MOD;
}