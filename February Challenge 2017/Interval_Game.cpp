    #include <bits/stdc++.h>
    using namespace std;
     
    int n,m;
     
    // A utility function to get minimum of two numbers
    long long int minVal(long long int x, long long int y) { return (x < y)? x: y; }
     
    // A utility function to get the middle index from corner indexes.
    long long int getMid(long long int s, long long int e) {  return s + (e -s)/2;  }
     
    /*  A recursive function to get the minimum value in a given range
         of array indexes. The following are parameters for this function.
     
        st    --> Pointer to segment tree
        index --> Index of current node in the segment tree. Initially
                  0 is passed as root is always at index 0
        ss & se  --> Starting and ending indexes of the segment represented
                      by current node, i.e., st[index]
        qs & qe  --> Starting and ending indexes of query range */
    long long int RMQUtil(long long int *st, long long int ss, long long int se, long long int qs, long long int qe, long long int index)
    {
        // If segment of this node is a part of given range, then return
        //  the min of the segment
        if (qs <= ss && qe >= se)
            return st[index];
     
        // If segment of this node is outside the given range
        if (se < qs || ss > qe)
            return INT_MAX;
     
        // If a part of this segment overlaps with the given range
        long long int mid = getMid(ss, se);
        return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                      RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
    }
     
    // Return minimum of elements in range from index qs (quey start) to
    // qe (query end).  It mainly uses RMQUtil()
    long long int RMQ(long long int *st, long long int n,long long int qs,long long int qe)
    {
        // Check for erroneous input values
        if (qs < 0 || qe > n-1 || qs > qe)
        {
            printf("Invalid Input");
            return -1;
        }
     
        return RMQUtil(st, 0, n-1, qs, qe, 0);
    }
     
    // A recursive function that constructs Segment Tree for array[ss..se].
    // si is index of current node in segment tree st
    long long int constructSTUtil(long long int arr[], long long int ss, long long int se, long long int *st, long long int si)
    {
        // If there is one element in array, store it in current node of
        // segment tree and return
        if (ss == se)
        {
            st[si] = arr[ss];
            return arr[ss];
        }
     
        // If there are more than one elements, then recur for left and
        // right subtrees and store the minimum of two values in this node
        long long int mid = getMid(ss, se);
        st[si] =  minVal(constructSTUtil(arr, ss, mid, st, si*2+1),
                         constructSTUtil(arr, mid+1, se, st, si*2+2));
        return st[si];
    }
     
    /* Function to construct segment tree from given array. This function
       allocates memory for segment tree and calls constructSTUtil() to
       fill the allocated memory */
    long long int *constructST(long long int arr[], long long int n)
    {
        // Allocate memory for segment tree
     
        //Height of segment tree
        long long int x = (long long int)(ceil(log2(n))); 
     
        // Maximum size of segment tree
        long long int max_size = 2*(long long int)pow(2, x) - 1; 
     
        long long int *st = new long long int[max_size]; 
     
        // Fill the allocated memory st
        constructSTUtil(arr, 0, n-1, st, 0);
     
        // Return the constructed segment tree
        return st;
    }
     
    long long int f(vector< vector<long long int> > & P,long long int B[],int C[],int chance,int start,int end){
    	//cout<<start<<" "<<end<<endl;
    	if(chance==m){
    		long long int p = 0;
    		for(int i=start;i+C[m]-1<=end;i++){
    			if(P[i][m]>p)
    				p = P[i][m];
    		}
    		if(chance%2==0) p = -p;
    		return p;
    	}
    	if(P[start][chance]!=-1)
    		return P[start][chance];
    	else{
    		if(chance%2==1){
    			long long int p = 0,q=0;
    			for(int i=start;i+C[chance]-1<=end;i++){
    				if(end-1-i>=C[chance+1]){
    					q = B[i+C[chance]-1]-B[i-1] + f(P,B,C,chance+1,i+1,i+C[chance]-2);
    					if(p<q){
    						p =q;
    					}
    				}
    			}
    			P[start][chance] = p;
    			return p;
    		}
    		else if(chance%2==0){
    			long long int p = 9999999999999,q=0;
    			for(int i=start;i+C[chance]-1<=end;i++){
    				q = -B[i+C[chance]-1]+B[i-1] + f(P,B,C,chance+1,i+1,i+C[chance]-2);
    				if(end-1-i>=C[chance+1]){
    					if(p>q){
    						p =q;
    					}
    				}
    			}
    			P[start][chance] = p;
    			return p;
    		}
    	}
    }
     
    int main(){
        
    	int t;
    	scanf("%d",&t);
    	while(t--){
    		scanf("%d %d",&n,&m);
    		long long int B[n+1];
    		B[0] = 0;
    		for(int i=1;i<=n;i++){
    			scanf("%lld",&B[i]);
    			B[i] += B[i-1];
    		}
    		if(m!=2){
    			int C[m+1];
    			C[0] = 0;
    			for(int i=1;i<=m;i++){
    				scanf("%d",&C[i]);
    			}
    			vector< vector<long long int> >P;
    			vector<long long int>Q(m+1,-1);
    			for(int i=1;i<=n+1;i++){
    				P.push_back(Q);
    			}
    			for(int i=1;i<=n;i++){
    				P[i][m] = B[i+C[m]-1] - B[i-1];
    			}
    			printf("%lld\n",f(P,B,C,1,1,n));
    			/*
    			cout<<"*******************\n";	
    			for(int i=1;i<=n;i++){
    				for(int j=1;j<=m;j++){
    					printf("%lld\t",P[i][j]);
    				}
    				printf("\n");
    			}
    			*/
    		}
    		else{
    			        int C[m];
            for(int i=0;i<m;i++){
                scanf("%d",&C[i]);
            }
    			long long int answer = 0;
                long long int p = 0;
                long long int D[n-C[0]+2];
                long long int E[n-C[1]+2];
                for(int i=1;i<=n-C[0]+1;i++){
                    D[i] = B[i+C[0]-1]  - B[i-1];
                }
                for(int i=1;i<=n-C[1]+1;i++){
                    E[i] = -(B[i+C[1]-1]  - B[i-1]);
                }
                E[0] = 0;
                // j+C[1]-1<i+C[0]-1
                // j <= i + C[0] - C[1] - 1
                long long int *st = constructST(E, n-C[1]+3);
                for(int i=1;i<=n-C[0]+1;i++){
                    p = -RMQ(st,  n-C[1]+3, i+1, i + C[0] - C[1] - 1);
                    answer = max(answer,D[i]-p);
                }
                printf("%lld\n",answer);
    		}
    		
    	}
     
    	return 0;
    	} 
