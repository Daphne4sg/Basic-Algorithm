#include<iostream>
#define Size 6
using namespace std;
int binarySearch(int A[],int n, int x){
	int low = 1;
	int upper = n;
	int idx;
	while(1){
		if (upper<low){
			break;
		}
		int mid = (upper+low)/2;
		if (x<A[mid]){
			upper = mid-1;
		}else if (x>A[mid]){
			low = mid+1;
		}else{
			idx = mid;
		
			return idx;
		}
	} 
} 
int main(){
	int A[]={-1,3,5,7,10,12};
	int x = 7;
	cout<<binarySearch(A,6,x);
	
}
