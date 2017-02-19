    #include <bits/stdc++.h>
    using namespace std;
     
    int main(){
        
        int t,o1,o2,n,c,answer;
        scanf("%d",&t);
        while(t--){
            answer = 0;
            scanf("%d %d",&o1,&o2);
            n = o1*o2;
            int A[n+1];
            A[0] = 0;
            for(int i=1;i<=n;i++){
                scanf("%d",&A[i]);
                A[i] += A[i-1];
            }
            for(int start=1;start<=o2;start++){
                c = 0;
                if(start+o2-1>n){
                    if(2*(A[(start+o2-1)%n]+A[n]-A[n-o2+(start+o2-1)%n]) > o2){
                        c++;
                    //    cout<<"ok\n";
                    } 
                }
                else if(2*(A[start+o2-1]-A[start-1]) > o2){
                    c++;
                //    cout<<"up\n";
                } 
                for(int i=start+o2;i%n!=start;i+=o2){
                    //cout<<"i : "<<i<<endl;
                    if(i+o2-1>n){
                        if(2*(A[(i+o2-1)%n]+A[n]-A[n-o2+(i+o2-1)%n]) > o2){
                            c++;
                  //          cout<<"\n"<<(i+o2-1)%n<<"  + "<<n<<" - "<< n-o2+(i+o2-1)%n - 1<<endl;
                    //       cout<<"in\n";
                        } 
                    }
                    else if(2*(A[i+o2-1]-A[i-1]) > o2){
                        c++;
                      //  cout<<"found\n";
                    }
                }
                //return 0;
                //cout<<"c : "<<c<<endl;
             //   cout<<"start : "<<start<<endl;
                if(2*c>o1){
                    answer = 1;
                    break;
                }
            }
            printf("%d\n",answer);
        }
        
        
        
        return 0;
    } 
