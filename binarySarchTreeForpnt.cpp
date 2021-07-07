#include<iostream>
#include<iomanip>
using namespace std;

class tree{
	public:
		int data;
		class tree *left, *right;
};
typedef class tree node;
typedef node *btree;
btree create_tree(btree root, int val)
{
	btree newnode, current, backup;
	newnode = new node;
	newnode->data = val;
	newnode->left = NULL;
	newnode->right = NULL;
	if(root == NULL){
		root = newnode;
		return root;
	}else{
		for(current = root;current != NULL;){
			backup = current;
			if (current->data > val){
				current = current->left;
			}else{
				current = current->right;
			}
		}
		if(backup->data > val){
			backup->left = newnode;
		}else{
			backup->right = newnode;
		}
	}
	return root;
}

btree pre(btree ptr, int val){
  	int i = 1; // know the excute times 
	while(1){
		if(ptr == NULL){
			return NULL;
		}
		if(ptr->data == val){
			cout<<"Total search for "<<setw(3)<<i<<" times"<<endl;
			return ptr;
		}else if(ptr->data > val){
			ptr = ptr->left;
		}else{
			ptr = ptr->right;
			
		}
		i++;
	} 
}

int main(){
	int data, arr[]={7,4,1,5,13,8,11,12,15,9,2};
	btree ptr = NULL;
	cout<<"Original array: "<<endl;
	for(int i = 0;i<11;i++){
		ptr = create_tree(ptr, arr[i]);
		cout<<"["<<setw(2)<<arr[i]<<"]";
	}
	cout<<endl;
	cout<<"Enter target value"<<endl;
	cin>>data;
	if((pre(ptr, data)) != NULL){
		cout<<"The target value ["<<setw(3)<<data<<"] has been found!"<<endl;
	}else{
		cout<<"The target value hasn't been found!"<<endl;
	}
	return 0;
}
