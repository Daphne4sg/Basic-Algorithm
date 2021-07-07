#include<iostream>
#include<cstdlib>
#define MAXSIZE 10 // define the max volume in queue
using namespace std;
int front = -1; // point to front of queue
int rear = -1; // point to back of queue

struct list{  // the vertices of graph
  int x; // vertex data
  struct list *next;   //point to the next vertex's pointer
}; 

typedef struct list node;
typedef node *link;

struct GraphLink{
	link first;
	link last;
};

int run[9]; // record every vertex has been visited or not
int queue[MAXSIZE];
struct GraphLink Head[9];
void print(struct GraphLink temp){
	link current = temp.first;
	while(current != NULL){
		cout<<"["<<current->x<<"]";
		current = current->next;
	}
	cout<<endl;
}
void insert(struct GraphLink *temp, int x){
	link newNode;
	newNode = new node;
	
	newNode->x = x;
	newNode->next = NULL; 
	if (temp->first == NULL){
		temp->first = newNode;
		temp->last = newNode;
	}else{
		temp->last->next = newNode;
		temp->last = newNode;
	}
}
//store data in queue
void enqueue(int value){
	if(rear >= MAXSIZE){
		return;
	}
	rear++;
	queue[rear] = value;
}
//get data from queue
int dequeue(){
	if(front == rear){
		return -1;
	}
	front++;
	return queue[front];
}

//breadth first search
void bfs(int current){
	link tempnode; 
	enqueue(current);  //store the first vertex in queue
	run[current] = 1;  // the visited vertex set = 1
	cout<<"["<<current<<"]";  // print the visted vertex  
	while(front != rear){  // empty queue?
	  current = dequeue(); // get vertex from queue
	  tempnode = Head[current].first;  //record the current vertex position
	  while(tempnode != NULL){
	  	if(run[tempnode->x]==0){
	  		enqueue(tempnode->x);
	  		run[tempnode->x]=1;
	  		cout<<"["<<tempnode->x<<"]";
		  }
		  tempnode = tempnode->next;
	  }
	  	
	
	}
}

int main(){
	//graph array
	int Data[20][2]=
	{{1,2},{2,1},{1,3},{3,1},{2,4},{4,2},{2,5},{5,2},{3,6},{6,3},
	{3,7},{7,3},{4,5},{5,4},{6,7},{7,6},{5,8},{8,5},{6,8},{8,6}};
	int DataNum;
	int i,j;
	cout<<"linked list of graph "<<endl;
	for(i=1;i<=8;i++){
		run[i]=0; //set all of the vertices has not been visited
		cout<<"Vertex"<<i<<"=>";
		Head[i].first=NULL;
		Head[i].last = NULL;
		for(j=0;j<20;j++){
			if(Data[j][0]==i){  //if start == the head of linked list, then add the vertex inti list
				DataNum = Data[j][1];
				insert(&Head[i],DataNum);
			}
		}
		print(Head[i]); // print the graph linked list
	}
	cout<<"Bradth first search Visted vertex:"<<endl; // pront the visited vertex
	bfs(1);
	cout<<endl;
	return 0;
}
