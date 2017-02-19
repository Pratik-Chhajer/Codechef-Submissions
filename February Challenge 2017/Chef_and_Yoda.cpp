    #include <cstdio>
     
    double f(int n,int k){
     
    	double p,answer=0.5;
    	p = 0.5;
    	int count = n-1;
    	int kcount = 1;
    	while(kcount<k){
    		p *= (n-kcount+1);
    		p /= (kcount);
    		answer += p;
    		while(count>0 && p>1){
    		    p *= 0.5;
    		    answer *= 0.5;
    		    count--;
    		}
    		kcount++;
    	}
    	while(count>0){
    		answer *= 0.5;
    		count--;
    	}
    	return answer;
    }
    int main(){
        int t;
        int n,m,p,k;
        scanf("%d",&t);
        while(t--){
            scanf("%d %d %d %d",&n,&m,&p,&k);
            if(!p){
                printf("1.000000\n");
            }
            else if(!(n&1) && !(m&1)){
                printf("1.000000\n");
            }
            else if(!((n*m)&1)){
                printf("%6f\n",1-f(k,p));
            }
            else{
                printf("0.000000\n");
            }
        }
        return 0;
    }  
