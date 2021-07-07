//#include "stdafx.h"
#include<iostream>
#include<iomanip>
using namespace std;
#define SIZE 5
void showdata(int A[],int size){
	for(int i = 0;i<SIZE;i++){
		cout<<A[i]<<setw(3);
	}
}

void bubbleSort(int A[],int size){
	int i,j;
	bool swap;
	int s = SIZE-1;
	for (i = 0;i<SIZE;i++) {
	  swap = false;
	  for (j = 0;j<s;j++){
		if( A[j]>A[j+1]){
		  int tmp = A[j];
		  A[j]=A[j+1];
		  A[j+1]=tmp;
		//swap(A[j],A[j+1]);
		  swap = true;
		  
		}
		showdata(A,SIZE);
		cout<<"\n";
		}
	  s-=1;
	  if (swap==false){
		  break;
		}
	  
	}
}

int main(int argc, const char** argv) {
	int A[] ={3,2,5,4,1};
\\ 
	bubbleSort(A,SIZE);
	return 0;
}
