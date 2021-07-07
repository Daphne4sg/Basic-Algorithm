#include<iostream>
#include<iomanip>
using namespace std;
//heap sort
void showdata(int A[],int size){
	int i;
	for(i=0;i<size;i++){
		cout<<A[i]<<setw(3);
	} 
	cout<<endl;
}
void max_heapify(int A[], int i,int size){
	int l = 2*i+1;
	int r = 2*i+2;
	int tmp;
	int largest = i;
	
	if (l < size && A[l] > A[largest]){
		largest = l;
	}else{
		largest = i;
	}
	if (r < size && A[r] >A[largest]){
		largest = r;
	}
	if(largest != i){
		//exchange A[i] <-> A[largest]
		tmp = A[i];
		A[i] = A[largest];
		A[largest] = tmp; 
		showdata(A,11);
		max_heapify(A,largest,size);
	}
} 
void build_max_heap(int A[],int size){
	int i;
	for(i=size/2-1;i>=0;i--){
		cout<<"build_max_heap: "<<endl; 
		max_heapify(A,i,size);
		
	}
	
}
void heapSort(int A[],int size){
	int i,tmp;

	build_max_heap(A,size);
	
	for(i=size-1;i>=0;i--){
		//exchange A[1]<->A[i]
		tmp = A[0];
		A[0] = A[i];
		A[i] = tmp;
		cout<<"heapSort: "<<endl;
		max_heapify(A,0,i);
		
	}
	
}

int main(){
	int A[11]={3,8,6,1,9,11,2,5,4,20,15};
	cout<<"original data: "<<endl;
	showdata(A,11);
	
	heapSort(A,11);
	cout<<"\nafter heapsort: "<<endl;
	showdata(A,11);
	return 0;
}
