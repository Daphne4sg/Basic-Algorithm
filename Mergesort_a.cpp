#include<iostream>
#include<iomanip>
using namespace std ;

void showdata(int A[],int size){
	for(int i = 0;i<size;i++){
		cout<<A[i]<<setw(3);
	}
	cout<<endl;
}
//Merge sort
void Merge(int A[],int p, int q,int r){
	int n1 = q-p+1;
	int n2 = r-q;
	int i,j;
	int L[n1];
	int R[n2];
	for (i=0;i<n1;i++){
		L[i] = A[p+i];
	} 
	for(j=0;j<n2;j++){
		R[j] = A[q+j+1];
	}
	cout<<"L"<<endl;
	showdata(L,n1);
	cout<<"R"<<endl;
	showdata(R,n2);
	cout<<endl;
	i = 0;
	j = 0;
	for(int k = p;k<=r;k++){
		if(L[i] <= R[j]  && i<n1 || j>=n2){
			A[k] = L[i];
			i+=1;
		}else if(j<n2){
			A[k] = R[j];
			j+=1;
		}
	}
}

void MergeSort(int A[], int p, int r){
	if (p<r){
		int q = (p+r)/2;
		MergeSort(A,p,q);
		MergeSort(A,q+1,r);
		
		Merge(A,p,q,r);
		showdata(A,r+1);
		
	}
}
int main(){
	int A[] = {3,4,6,1,2};
	int r = 4;
	showdata(A,r+1);
	MergeSort(A,0,r);
	
	
}



