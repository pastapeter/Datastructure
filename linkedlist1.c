

#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int data;
	struct node* next;
    struct node* prev;
    
}Node;

typedef struct list {
	Node* head;
	int size;
}List;

List* createList() {
	List* list = (List*)malloc(sizeof(List));

	list->head = NULL;
	list->size = 0;
	return list;
}


void insertElement(List** list, int index, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL
    newNode->prev = NULL;
	if (index > (*list)->size || index < 0) {
		puts("index error");
		return;
	}

	if (index == 0) {						
		if ((*list)->head == NULL) {
            (*list)->head = newNode;
		}
		else {
			Node* temp = (*list)->head;
			(*list)->head = newNode;
			newNode->next = temp;
		}
	}
	else if (index == (*list)->size) {		// ∏« µ⁄
		Node* node = (*list)->head;
		while (node->next != NULL) {
			node = node->next;
		}
		node->next = newNode;
	}
	else {									// ¡ﬂ∞£
		Node* node = (*list)->head;
		int cnt = 0;
		while (cnt < index) {
			node = node->next;
			cnt++;
		}
		newNode->next = node->next;
		node->next = newNode;
	}
	(*list)->size++;
}

void removeElement(List** list, int index) {

	if (index >= (*list)->size || index < 0) {
		puts("index error");
		return;
	}

	if (index == 0) {						// ∏« æ’
		Node* target = (*list)->head;
		(*list)->head = (*list)->head->next;
		
		free(target);
	}
	else if (index == (*list)->size - 1) {	// ∏« µ⁄
		Node* node = (*list)->head;
		// ∏« µ⁄ - 1π¯ ¬∞ ¿ßƒ°∑Œ ¿Ãµø
		while (node->next->next != NULL) {
			node = node->next;
		}

		Node* target = node->next;
		node->next = NULL;
		free(target);
	}
	else {									// ¡ﬂ∞£
		Node* node = (*list)->head;
		int cnt = 0;
		while (cnt < index-1) {
			node = node->next;
			cnt++;
		}

		Node* target = node->next;
		node->next = node->next->next;
		free(target);
	}
	(*list)->size--;
	return;
}

int findElement(List* list, int index) {

	if (index > list->size - 1 || index < 0) {
		puts("index error");
		return -1;
	}

	Node* node = list->head;
	int cnt = 0;
	while (cnt < index) {
		node = node->next;
		cnt++;
	}
	return node->data;
}

int main(void) {
	List* list = createList();

	insertElement(&list, 0, 1);
	insertElement(&list, 0, 2);
	insertElement(&list, 0, 3);
	insertElement(&list, 0, 4);

	removeElement(&list, 1);
	printf("Index 0: %d\n", findElement(list, 0));
	printf("Index 1: %d\n", findElement(list, 1));
	printf("Index 2: %d\n", findElement(list, 2));
	
	return 0;
}
