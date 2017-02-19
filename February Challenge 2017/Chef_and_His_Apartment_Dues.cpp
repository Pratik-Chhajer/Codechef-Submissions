    #include <bits/stdc++.h>
    using namespace std;
     
    int main(){
        
        long long int t,n,c,d;
        int a,b;
        scanf("%lld",&t);
        while(t--){
            scanf("%lld",&n);
            a = 0;
            c = 0;
            b = 0;
            d = -1;
            for(int i=0;i<n;i++){
                scanf("%d",&a);
                if(b==0 && a==0){
                    b = 1;
                    d = i;
                }
                else if(a==1){
                    c++;
                }
            }
            if(d>=0)
                printf("%lld\n",(n-c)*1000+(n-d)*100);
            else
                printf("0\n");
        }
        
        
        
        return 0;
    } 
