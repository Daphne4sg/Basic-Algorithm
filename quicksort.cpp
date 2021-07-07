#include<iostream>
#include<iomanip>
using namespace std;

void show(int A[], int size){
     int i;
     for (i=0;i<size;i++){
         cout<<A[i]<<setw(3);
     }
     cout<<endl;
}     
int Partition(int A[], int p, int r){
    int i = p-1;
    int j,tmp;
    for(j = p;j<r;j++){
          if (A[j]<=A[r]){
              i+=1;
               //swap A[i] and A[r]
               tmp = A[i];
               A[i] = A[j];
               A[j] = tmp;
          }
          //show(A,9);
          }
    //swap A[i+1] and A[r]
    swap(A[i+1],A[r]);
    //show(A,9);
    return i+1;
} 
           
void Quicksort(int A[], int p, int r){
	int q;
	if(p<r){
		q = Partition(A, p, r);
		show(A,9);
		Quicksort(A,p,q-1);
		Quicksort(A, q+1, r);
	}
}


int main(){
   int A[9]={3,2,5,4,1,9,10,6,15};
   cout<<"The original data: "<<endl;;
   int size = sizeof(A)/sizeof(A[0]);  //length of size: all arraylength /elements' array length
   show(A,size);
   cout<<"QuickSort processing..."<<endl;
   Quicksort(A,0,8);   
   cout<<"After quicksort:"<<endl;
   show(A,size);
   return 0;
}
