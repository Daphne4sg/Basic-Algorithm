#include<iostream>
#include<iomanip>
using namespace std;
void honai(int size, char p1, char p2, char p3){
	if (size > 0){
		
		honai(size-1,p1,p3,p2);
	    cout<<"Disk "<<size<<" from "<<p1<<" move to "<<p3<<endl;
		honai(size-1,p2,p1,p3);
	}
	
	
}
int main(){
	int n;
	cout<<"Please enter a number: ";
	cin>>n;
	honai(n,'A','B','C');
}
