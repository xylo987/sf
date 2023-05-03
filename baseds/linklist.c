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

voide delete(struct LinkList *L, struct Node *x) {
	struct Node *tmp = L -> head;
	while(tmp -> next != NULL) {
		if (tmp == x) {
			tmp -> prev = tmp -> next;
			tmp -> next -> prev = tmp;
		}
		tmp = tmp -> next;
	}
}

int main() {
}