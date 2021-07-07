#include<iostream>
using namespace std;
//input: A:sorted array ,target:target value, i: starting index, j:ending index
//output: if target exist, the index of target value; else, -1
int binarySearchRecursive(int A[],int target, int i, int j){
    if (i>= j){
            if(A[i] == target){
                    return i;
            }else {
            	 cout<<"no target value in this array"<<endl;
                 return -1;
                 }
    }else{
           int mid = (i+j)/2;
           if (target<=A[mid]){
           	binarySearchRecursive(A,target,i,mid);
		   }else{
		   	binarySearchRecursive(A,target,mid+1,j); 
		   }
}
}
int main(){
    int target = 16;
    int A[6] ={1,3,8,9,12,16};
    int i = 0;
    int j = sizeof(A)/sizeof(A[0]);
    
    cout<<binarySearchRecursive(A,target,i,j);
    return 0;
}
