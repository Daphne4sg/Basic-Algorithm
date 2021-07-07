#include<iostream>
using namespace std;

class tree{
  public:
    int data;  // node data
	class tree *left, *right;  // node left pointer and right pointer
};
typedef class tree node;
typedef node *btree;
void Inorder(btree ptr){
	if (ptr!=NULL){
		Inorder(ptr->left);
		cout<<"["<<ptr->data<<"]";
		Inorder(ptr->right);
	}
} 

int main(){
	int i, level;
	int data[]={0,6,3,5,9,7,8,4,2};
	int btree[16]={0};
	cout<<"Original array:"<<endl;
	for(i=1;i<9;i++){
		cout<<"["<<data[i]<<"]";
	}
	cout<<endl;
	for(i=1;i<9;i++){
		for(level=1;btree[level]!=0;){
			//compare root and value in array
			if (data[i]>btree[level]){
				//if data[i]>root, then go to right subtree
				level = level *2+1;
			}else{
				//if data[i]<=root, then go to left subtree
				level = level *2;
			}
		}
		btree[level] = data[i];//put array's value in binary tree
	}
	cout<<"binary search tree: "<<endl;
	for(i=1;i<16;i++){
		cout<<"["<<btree[i]<<"] ";
	}
	cout<<endl;
	return 0;
}
