    #include <bits/stdc++.h>
    using namespace std;
     
    int main(){
        int n;
        long long int l,r;
        scanf("%d %lld %lld",&n,&l,&r);
        long long int A[n];
        for(int i=0;i<n;i++) scanf("%lld",&A[i]);
        sort(A,A+n);
        long long int a,b;
        int x,y;
        list<pair<long long int,long long int> > P;
        list<pair<long long int,long long int> > :: iterator itr;
			
				if(n<=1000){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            // max(l,A[j]-A[i]+1) to min(r,A[i]+A[j]-1)
            a = max(l,A[j]-A[i]+1);
            b = min(r,A[i]+A[j]-1);
		//	cout<<"Reached 2\n";
            if(a<=b){
			//	cout<<"Reached 3\n";
				//cout<<P.size()<<endl;
			//	cout<<"i,j : "<<i<<","<<j<<endl;
			//	cout<<P.size()<<endl;
                if(P.empty()==true){
		//			cout<<"Reached 4 a\n";
                    P.push_back(make_pair(a,b));
			//		cout<<"Reached 4 b\n";
                }/*
                else if(P.front().first>=a && P.back().second<=b){
				//	cout<<"Reached 5 a\n";
                    P.clear();
			//		cout<<"Reached 5 b\n";
				//	cout<<"Reached 6 a\n";
                    P.push_back(make_pair(a,b));
					//cout<<"Reached 6 b\n";
                }*/
                else{
				//	cout<<"here!\n";
                    itr = P.begin();
					int c = P.size();
					while(c!=0 && itr!=P.end()){
						if( ( (*itr).second>=a && (*itr).first<=a ) || ( (*itr).second>=b && (*itr).first<=b ) ){
						   while(c!=0 && itr!=P.end() && ( ( (*itr).second>=a && (*itr).first<=a ) || ( (*itr).second>=b && (*itr).first<=b ) ) ){
								if( ( (*itr).second>=a && (*itr).first<=a ) && ( (*itr).second>=b && (*itr).first<=b ) ){
									a = min(a,(*itr).first);
                                	b = max(b,(*itr).second);
								}
								else if( (*itr).second>=a && (*itr).first<=a ){
									a = min(a,(*itr).first);
								}
								else{
									b = max(b,(*itr).second);
								}
					//			cout<<"Reached 7 a\n";
								P.erase(itr);
								c--;
						//		cout<<"Reached 7 b\n";
							}
							//cout<<"Reached 8 a\n";
							if(P.empty()==true)
								P.push_back(make_pair(a,b));
							else
								P.insert(itr,make_pair(a,b));
							//cout<<"Reached 8 b\n";
							break;
						}
						itr++;
						c--;
					}
/*
                    while( itr!=P.end() ){
                        if( (*itr).second>=a ){
							cout<<"Size of P : "<<P.size()<<endl;
                            while(itr!=P.end() &&  (*itr).second>=a ){
								cout<<"Reached 7 a\n";
                                a = min(a,(*itr).first);
                                b = max(b,(*itr).second);
								cout<<"Reached 7 b\n";
								cout<<"Reached 8 a\n";
								cout<<"a,b : "<<a<<","<<b<<endl;							
								cout<<(*itr).first<<"  "<<(*itr).second<<endl;
								cout<<(P.end()==itr)<<endl;
                                P.erase(itr);
								cout<<"Reached 8 b\n";
                            }
							cout<<"Reached 9 a\n";
                            P.insert(itr,make_pair(a,b));
							cout<<"Reached 9 b\n";
                            break;
                        }
                        itr++;
                    }
*/
                }
            }
        }
    }
    long long int answer = 0;
    for(itr=P.begin();itr!=P.end();itr++){
        answer += (*itr).second - (*itr).first + 1;
    }
    printf("%lld\n",answer);
					
 
 
				} // If ends here
	
		else{
			
		        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<i+2;j++){
                // max(l,A[j]-A[i]+1) to min(r,A[i]+A[j]-1)
                a = max(l,A[j]-A[i]+1);
                b = min(r,A[i]+A[j]-1);
    		//	cout<<"Reached 2\n";
                if(a<=b){
    			//	cout<<"Reached 3\n";
    				//cout<<P.size()<<endl;
    			//	cout<<"i,j : "<<i<<","<<j<<endl;
    			//	cout<<P.size()<<endl;
                    if(P.empty()==true){
    		//			cout<<"Reached 4 a\n";
                        P.push_back(make_pair(a,b));
    			//		cout<<"Reached 4 b\n";
                    }/*
                    else if(P.front().first>=a && P.back().second<=b){
    				//	cout<<"Reached 5 a\n";
                        P.clear();
    			//		cout<<"Reached 5 b\n";
    				//	cout<<"Reached 6 a\n";
                        P.push_back(make_pair(a,b));
    					//cout<<"Reached 6 b\n";
                    }*/
                    else{
    				//	cout<<"here!\n";
                        itr = P.begin();
    					int c = P.size();
    					while(c!=0 && itr!=P.end()){
    						if( ( (*itr).second>=a && (*itr).first<=a ) || ( (*itr).second>=b && (*itr).first<=b ) ){
    						   while(c!=0 && itr!=P.end() && ( ( (*itr).second>=a && (*itr).first<=a ) || ( (*itr).second>=b && (*itr).first<=b ) ) ){
    								if( ( (*itr).second>=a && (*itr).first<=a ) && ( (*itr).second>=b && (*itr).first<=b ) ){
    									a = min(a,(*itr).first);
                                    	b = max(b,(*itr).second);
    								}
    								else if( (*itr).second>=a && (*itr).first<=a ){
    									a = min(a,(*itr).first);
    								}
    								else{
    									b = max(b,(*itr).second);
    								}
    					//			cout<<"Reached 7 a\n";
    								P.erase(itr);
    								c--;
    						//		cout<<"Reached 7 b\n";
    							}
    							//cout<<"Reached 8 a\n";
    							if(P.empty()==true)
    								P.push_back(make_pair(a,b));
    							else
    								P.insert(itr,make_pair(a,b));
    							//cout<<"Reached 8 b\n";
    							break;
    						}
    						itr++;
    						c--;
    					}
    /*
                        while( itr!=P.end() ){
                            if( (*itr).second>=a ){
    							cout<<"Size of P : "<<P.size()<<endl;
                                while(itr!=P.end() &&  (*itr).second>=a ){
    								cout<<"Reached 7 a\n";
                                    a = min(a,(*itr).first);
                                    b = max(b,(*itr).second);
    								cout<<"Reached 7 b\n";
    								cout<<"Reached 8 a\n";
    								cout<<"a,b : "<<a<<","<<b<<endl;							
    								cout<<(*itr).first<<"  "<<(*itr).second<<endl;
    								cout<<(P.end()==itr)<<endl;
                                    P.erase(itr);
    								cout<<"Reached 8 b\n";
                                }
    							cout<<"Reached 9 a\n";
                                P.insert(itr,make_pair(a,b));
    							cout<<"Reached 9 b\n";
                                break;
                            }
                            itr++;
                        }
    */
                    }
                }
            }
        }
        long long int answer = 0;
        for(itr=P.begin();itr!=P.end();itr++){
            answer += (*itr).second - (*itr).first + 1;
        }
        printf("%lld\n",answer);
 
		} // Else ends here
    return 0;
}
