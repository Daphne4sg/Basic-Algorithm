#include<iostream>
using namespace std;

int findMax(int A[], int low, int high){
	if(low == high){
		return A[low];
	}
	int mid = (high+low)/2;
	int left = findMax(A,low,mid);
	int right = findMax(A, mid+1, high);
	
	if(left>right){
		cout<<"left"<<left<<endl;
		return left;
	}else{
		cout<<"right"<<right<<endl;
		return right;
	}
}

int main(){
	int A[5]= {3,4,6,1,8};
	cout<<"the maximum value is "<<findMax(A,0,4);
	return 0;
}
