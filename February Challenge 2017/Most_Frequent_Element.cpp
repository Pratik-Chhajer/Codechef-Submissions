#include <bits/stdc++.h>
using namespace std;
 
 
void make(int A[],int B[],int i,int j){
    int c,x;
    int y = i;
    while(i<=j){
        c = 1;
        x = i;
        while(i+1<=j && A[i]==A[i+1]) i++,c++;
        for(int k=x;k<=i;k++){
            B[k] = c;
            c--;
        }
        i++;
    }
}
 
int majority(int A[],int B[],int i,int j,int k,int maxx){
    int index = i;
    int count = min(B[i],j-i+1);
    int c;
    int x = i;
    if(maxx<k) return -1;
    while(i<=j){
        if(min(B[i],j-i+1)>count){
            count = min(B[i],j-i+1);
            index = i;
        }
        if(count>=k)
            return A[index];
        i += B[i];
    }
    if(count>=k) return A[index];
    return -1;
}
 
int main(){
    
    int n,m,l,r,k,p,a,b,answer;
    scanf("%d %d",&n,&m);
    int A[n];
    int B[n];
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);
    make(A,B,0,n-1);
    int maxx = B[0];
    for(int i=0;i<n;i+=B[i])
        if(B[i]>maxx) maxx = B[i];
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&l,&r,&k);
        answer = majority(A,B,l-1,r-1,k,maxx);
        printf("%d\n",answer);
    }
    return 0;
