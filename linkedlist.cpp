/*

Author: Chitrang Talaviya 
Linedin: www.linkedin.com/in/chitrangtalaviya


THis file containes the implementation of the linked list and its helper function to manipulate it.

*/


#include <iostream>

using namespace std;

typedef struct node
{
	int data;
	struct node* next;
}node;

// This is the helper function to create single node.


node* createNode(int key)
{
	node* nodePtr = (node *) malloc(sizeof(node));
	nodePtr->data = key;
	nodePtr->next = NULL;
	return nodePtr;
}

// THis is the helper funtion to insert the node at the start of the linnked list.


node* push(node* headRef, int key)
{

	node* temp = createNode(key);

	if(headRef == NULL)
	{	
		headRef = temp;
		return headRef;
	}

	else
	{
		temp->next = headRef;
		headRef = temp;
		return headRef;
	}

}


// Funtion to Create a linked list.

node* CreateList(node* headRef, int* key, int num)
{

	for(int i = 0 ; i < num; i++)
	{
		headRef = push(headRef, key[i]);
	}

	return headRef;

}


void printList(node* headRef)
{
	node* cur = headRef;
	cout<<"HEAD -> ";
	while(cur != NULL)
	{
		cout<<cur->data<<"->";
		cur = cur->next;
	}

	cout<<"NULL"<<endl;
}




int main()
{

	node* head; // Here we are making the uhead of the linked list as the local variable(pointer) in the main function.

	// So every method we will write will going to return the head pointer to update the head pointer.


	int data[10] = {1, 4,53, 32, 423, 42, 42,673, 63, -13};


	head = CreateList(head, data, 10);
	printList(head);

}




