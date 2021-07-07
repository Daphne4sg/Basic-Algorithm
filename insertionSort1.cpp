#include<iostream>
#include<iomanip>
using namespace std;
#define Size 5
void showdata(int A[],int size){
	for(int i=0;i<size;i++){
		cout<<A[i]<<setw(3);
	}
	cout<<endl;
}
int InsertionSort(int A[],int n){
    int key,i,j;
    for(j=1;j<n;j++){
            key = A[j];
            //Insert A[j] to the sorted sequence A[1,...,j-1]
            i=j-1;
            while(i>=0 && A[i]>key){
            	      int tmp =A[i+1];
                      A[i+1]=A[i];
                      A[i] = tmp;
                      i-=1;
                      
                      }
                      
            
            A[i+1]=key;
            
            showdata(A,n);
            
            }
    
    
    }
int main(){
	int A[] ={3,4,1,2,5};
	InsertionSort(A,Size);
	return 0;
	
}
