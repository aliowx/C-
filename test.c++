int fib(int n){
    int f1=0,f2=1,f;
        if (n == 0) return f1;
        else if(n==1)return f2;
    int i = 0;
    for( i=2; i<=n; i++){
        f=f1+f2;
        f1=f2;
        f2=f;
    }
    return f;
};