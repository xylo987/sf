#include <stdio.h>

struct LinkList {
	struct Node *head;
	int size;
}

struct Node {
	int *prev;
	int *next;
	int key;
}

void init(struct LinkList *L) {
	L -> prev = NULL;
	L -> size = 0;
}

struct Node *search(struct LinkList *L, int key) {
	struct Node *x = L -> head;
	while (x != NULL && x -> key != key) {
		x = L -> next;
	}
	return x;
}

void insert(struct LinkList *L, struct Node *x) {
	if (L -> head == NULL) {
		L -> head = x;
		x -> prev = NULL;
		x -> next = NULL;
	} else {
		x -> next = L -> head -> prev;
		L -> head -> prev = x;
		x -> prev = NULL;
	}
}

void delete(struct LinkList *L, struct Node *x) {
	struct Node *head = L -> head;
	struct Node *prev, *next;
	while(head -> next != NULL) {
		if (head == x) {
			prev = head -> prev;
			next = head -> next;

			prev -> next = next;
			next -> prev = prev;
		}
		head = head -> next;
	}
}

int main() {
}