#include<iostream>
using namespace std;

//counterfeit currency problem
//input: A:an array of n coin weights, i:the starting index,j:the ending index 
int findTheMin(int A[],int i, int j){
	
	if(A[i] != A[j] || i==j){
		//return min(A[i],A[j]
		if(A[i]<A[j]){
			return i;
		}else{
			return j;
		}
	}
	int mid = (i+j)/2;
	findTheMin(A,i,mid);
	findTheMin(A,mid+1,j);
}

int main(){
	int A[5]={3,3,3,3,1};
	
	cout<<"the fake coin's index is "<<findTheMin(A,0,4);
}
