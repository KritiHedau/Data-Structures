#include<stdio.h>
#include<stdlib.h>

typedef struct Node {

	int data;
	struct Node* next;
}Node;

Node* newnode(int data) {

	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}
Node* insertatend(Node* head, int data) {

	if (head == NULL) 
		return newnode(data);

	else
		head->next = insertatend(head->next, data);
	return head;
}

void traverse(Node* head) {

	if (head == NULL)
		return;
	printf("\t%d", head->data);
	traverse(head->next);

}

void middleoflinkedlist(Node* head) {

	Node* fast = head;
	Node* slow = head;

	while (fast != NULL && fast->next != NULL) {

		fast = fast->next->next;
		slow = slow->next;
	}
	printf("\n middle node %d", slow->data);
}

int main() {

	Node* head = NULL;
	head = insertatend(head, 10);
	head = insertatend(head, 20);
	head = insertatend(head, 30);
	head = insertatend(head, 40);
	head = insertatend(head, 50);
	traverse(head);
	middleoflinkedlist(head);

	return 0;
}