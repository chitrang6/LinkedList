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

node* CreateList(node* headRef, int* key,  int num)
{

	for(int i = 0 ; i < num; i++)
	{
		headRef = push(headRef, key[i]);
	}

	return headRef;

}


// This is the print function for the linked list.

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




// Delete a node in the linked list.


node* deleteNode(node* headRef, int position)
{
	
	if(position == 1)
	{
		node* temp = headRef;
		headRef = temp->next;
		delete temp;

	}

	else
	{
		node* cur = headRef;
		for(int i = 0 ; i < position-2; i++)
		{
			cur = cur->next;
		}
		node* temp = cur->next;
		cur->next = temp->next;
		delete temp;

	}

	return headRef;
}



// Reverse a linked list 


// head -> 10 -> 15 -> 20 -> NULL

node* reverse_iterative(node* headRef)
{

	node* prev = NULL;
	node* next_node;
	node* current = headRef;
	while(current != NULL)
	{
		next_node = current->next;
		current->next = prev;
		prev = current;
		current = next_node;
	}

	headRef = prev;
	return headRef;
}

/*

// Reverse a linedlist using recursion.

node* reverseRecursion(node* headRef)
{



	if(headRef->next == NULL)
	{
		return headRef;
	}

	headRef = reverseRecursion(headRef);

	node* q = headRef->next;
	q->next = headRef;
	headRef->next = NULL;

}

*/


int main()
{

	node* head; // Here we are making the uhead of the linked list as the local variable(pointer) in the main function.

	// So every method we will write will going to return the head pointer to update the head pointer.


	int data[10] = {12 , 21 , 2 , 23 ,234  , 123  , 234 , 23 , 1234 , 124};
	head = CreateList(head, data, 10);
	printList(head);

	head = deleteNode(head , 6);

	printList(head);

	head = reverse_iterative(head);

	printList(head);

}





