#include<iostream>
#include <math.h>  
using namespace std;
//A: input array
//i: left index
//j: right index
int MaxCrossSubarray(int A[], int i, int j, int k){
//left_sum = -inf
	int sum = 0;
//for p = k downto i
    int left_sum,max_left,right_sum,max_right,p,q; 
	for(p=k;p<i;p--){
		sum = sum + A[p];
  		if (sum > left_sum){
  			left_sum = sum;
			max_left = p;
		  }
			
	}
  	
	//right_sum = -inf
	for (q = k+1 ;q<j;q++){
		sum = sum + A[q];
		if (sum > right_sum){
			right_sum = sum;
			max_right = q;
		}
			
	}
		
	return (max_left, max_right, left_sum + right_sum);
 }
int MaxSubarray(int A[], int i, int j){
  int l_low, l_high, l_sum, r_low, r_high, r_sum, c_low, c_high, c_sum;
  int ans = new int[3];
  if (i == j)
	return (i, j, A[i]);
  else{
  	int k = floor((i+j)/2);
    (l_low, l_high, l_sum) = MaxSubarray(A, i, k);
	(r_low, r_high, r_sum) = MaxSubarray(A, k+1, j); 
	(c_low, c_high, c_sum) = MaxCrossSubarray(A, i, k, j);

  }
  if (l_sum >= r_sum && l_sum >= c_sum){
  	ans[0]=l_low;
  	ans[1]=l_high;
  	ans[2]=l_sum;
  	// l_low, l_high, l_sum
  	return ans;
  }
	
  else if (r_sum >= l_sum && r_sum >= c_sum)
	return (r_low, r_high, r_sum);
  else
	return (c_low, c_high, c_sum);
}


int main(){
	int A[6]={2,-3,6,8,-4,7};
	MaxSubarray(A, 0, 5);
	return 0;
}
