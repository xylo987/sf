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
		x -> next = L -> head;
		L -> head -> prev = x;
		x -> prev = NULL;
	}
	L -> size ++;
}

void delete(struct LinkList *L, struct Node *x) {
	struct Node *head = L -> head;
	struct Node *prev, *next;
	while(head != NULL) {
		if (head == x) {
			// 这里原指针没有回收，程序会自动回收吗？
			prev = head -> prev;
			next = head -> next;

			prev -> next = next;
			next -> prev = prev;
			L -> size --;
		}
		head = head -> next;
	}
}

void print(struct LinkList *L) {
	struct Node *head = L -> head;
	while (head != NULL) {
		printf("%d\n", head -> key);
		head = head -> next;		
	}
}

/**
 * 测试
 */
int main() {
	struct LinkList L;

	init(&L);

	struct Node x;
	x.prev = NULL;
	x.next = NULL;
	x.key = 1;
	insert(&L, &x);

	struct Node x1;
	x1.prev = NULL;
	x1.next = NULL;
	x1.key = 2;
	insert(&L, &x1);

	struct Node x2;
	x2.prev = NULL;
	x2.next = NULL;
	x2.key = 2;
	insert(&L, &x2);

	print(&L);

	print("删除-----------------\n");
	delete(x2);
	print(&L);
}