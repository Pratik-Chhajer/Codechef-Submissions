        #include <bits/stdc++.h>
        using namespace std;
         
        int main(){
         
        	int n,q,x,s;
        	long long int u,v;
        	scanf("%d %d",&n,&q);
        	long long int A[n];
        	for(int i=0;i<n;i++) scanf("%lld",&A[i]);
        	vector<list<int> >P(n);
    		vector<int>B(n,-1);
    		B[0] = -1;
        	for(int i=0;i<n-1;i++){
        		scanf("%lld %lld",&u,&v);
        		u--;
        		v--;
        		P[u].push_back(v);
        		P[v].push_back(u);
        	}
        	vector<bool> V(n,0);
        	vector<int> L(n,-1);
        	L[0] = 0;
        	V[0] = 1;
        	s = 0;
        	queue<int> Q;
        	Q.push(s);
        	//cout<<"before bfs\n";
        	while(!Q.empty()){
        		s = Q.front();
        		Q.pop();
        		for(list<int>::iterator itr = P[s].begin();itr!=P[s].end();itr++){
        			if(V[*itr]==0){
        				Q.push(*itr);
        				V[*itr] = 1;
        				L[*itr] = L[s] + 1;
    					B[*itr] = s;
        			}
        		}
        	}
        	while(q--){
        		scanf("%d %lld %lld",&x,&u,&v);
        		u--;
        		if(x==2){
        			A[u] = v;
        		}
        		else{
        			v--;
        			set <long long int, greater <long long int> > S;
        			S.insert(A[u]);
        			S.insert(A[v]);
        			list<int>::iterator itr;
        			if(L[u]>L[v]){
        			    while(L[u]!=L[v]){
        			        //for(itr = P[u].begin();itr!=P[u].end() && L[u]-L[*itr]!=1;itr++);
            			    //S.insert(A[*itr]);
    					//	S.insert(A[u]);
            			    u = B[u];
            			    S.insert(A[u]);
        			    }
        			}
        			else if(L[u]<L[v]){
        			    while(L[u]!=L[v]){
        			        //for(itr = P[v].begin();itr!=P[v].end() && L[v]-L[*itr]!=1;itr++);
            			    //S.insert(A[*itr]);
            			    //v = *itr;
    					//	S.insert(A[v]);
            			    v = B[v];
            			    S.insert(A[v]);
        			    }
        			}
        			while(u!=v && u!=0 && v!=0){
        			    //for(itr = P[u].begin();itr!=P[u].end() && L[u]-L[*itr]!=1;itr++);
        			    //S.insert(A[*itr]);
        			    //u = *itr;
    					//S.insert(A[u]);
            			u = B[u];
            			S.insert(A[u]);
        			    //for(itr = P[v].begin();itr!=P[v].end() && L[v]-L[*itr]!=1;itr++);
        			    //S.insert(A[*itr]);
        			    //v = *itr;
    					//S.insert(A[v]);
            			v = B[v];
            			S.insert(A[v]);
        			}
        			if(u!=v){
        			    while(u!=0){
        			        //for(itr = P[u].begin();itr!=P[u].end() && L[u]-L[*itr]!=1;itr++);
            			    //S.insert(A[*itr]);
            			    //u = *itr;
    					//	S.insert(A[u]);
            			    u = B[u];
            			    S.insert(A[u]);
        			    }
        			    while(v!=0){
        			        //for(itr = P[v].begin();itr!=P[v].end() && L[v]-L[*itr]!=1;itr++);
            			    //S.insert(A[*itr]);
            			    //v = *itr;
    					//	S.insert(A[v]);
            			    v = B[v];
            			    S.insert(A[v]);
        			    }
        			}
        			printf("%d\n",S.size());
        		}
        	}
         
        	return 0;
        }  
