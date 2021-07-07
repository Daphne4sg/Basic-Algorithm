#include<iostream>
#include<iomanip>
using namespace std;

//input A[1,...,n] whre A[j] is positive
//output sorted array B
void showdata(int A[],int size){
     int i;
     for(i = 0;i<size;i++){
           cout<<A[i]<<setw(3);
           }
     cout<<endl;    
}

void countingSort(int A[],int k){
    int i,j;
    int *C = new int[5];
    int *B = new int[6];
    int size = k;

    for (i=0;i<k;i++){
    	C[i] = 0;
	}
   
    for(j = 0;j<size;j++){
          C[A[j]] = C[A[j]]+1;}
//    cout<<"C";
//    cout<<"size"<<size<<endl;

    for(i =1;i<k-1;i++){
          C[i+1] = C[i]+C[i+1];

          }
//    cout<<"C";
//    cout<<"size"<<size<<endl;
//       showdata(C,size); 
    
     for(j = size-1;j>-1;j--){
     	
           B[C[A[j]]] = A[j];
           
           C[A[j]] = C[A[j]]-1;
           
           }
    
      for(i = 1;i<size+1;i++){
           cout<<B[i]<<setw(3);
           }
     cout<<endl; 
}


int main(){
    int A[6] = {2,2,1,1,1,5};
    int size = sizeof(A)/sizeof(A[0]);
    cout<<"original data: ";
    showdata(A,size);
    cout<<"after counting sort: ";
    countingSort(A,6);
    return 0;
}
 
