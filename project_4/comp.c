/* C program for 4th project from WPI (DAG) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node { 
	int data;
	int row;
	struct node *left;
	struct node *right;
};
struct list {
	struct node *tree;
	struct list *next;
};
/* freeList() frees a linked list */
void freeList(struct list* head) {
	struct list* tmp;

	while (head!=NULL) {
		tmp=head;
		head=head->next;
		free(tmp);
	}
}
/* freeTree() frees a binary tree*/
void freeTree(struct node* t) {	
	if (t!=NULL) {
		freeTree(t->right);
		freeTree(t->left);
		free(t);
	}
}
/* newNode() allocates a new node with the given data with NULL left and 
   right pointers. */
struct node* newNode(int data) {
	struct node* node=(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}
/* Take() recursively takes input and throws it into a tree. */
struct node* Take(int input) {
	struct node* t;
	t=newNode(input);
	if(scanf("%d", &input)>0) {
		if(input!=0) {t->left=Take(input);}
	}
	if(scanf("%d", &input)>0) {
		if(input!=0) {t->right=Take(input);}
	}
	return t;
}
/* identicalTrees() checks if two trees are identical */
int identicalTrees(struct node* a, struct node* b) {
	if (a==NULL && b==NULL) {return 1;}
	if (a!=NULL && b!=NULL) {
		return(a->data==b->data && identicalTrees(a->left, b->left) && 
		identicalTrees(a->right, b->right));
	}
	else {return 0;}
}
/*	have() returns pointer to identical tree, and returns NULL if there
	such tree in the record */
struct node* have(struct node* t, struct list* l) {
	while(l!=NULL) {
		if(identicalTrees(l->tree, t)) {return l->tree;}
		l=l->next;
	}
	return NULL;
}
/*	preprend2nd() adds to the second position of the linked list. */
void prepend2nd(struct node* t, struct list* l) {
	struct list* new_node=(struct list*)malloc(sizeof(struct list));
	new_node->tree=t;
	new_node->next=l->next;
	l->next=new_node;
}
/* Traverse() recursively traverses the tree and checks if we have 
   such a tree in the record with function have() and if not, we add it 
   to our record with prepend2nd(). */
void Traverse(struct node* t, struct list* l, int *i) {
	(*i)++; //row number
	if(t==NULL) {
		printf("%d\n", 0);
		return;
	}
	t->row=(*i);
	struct node* a;
	a=have(t,l);
	if(a!=NULL) { //a is either NULL or a pointer to a similar subtree
		printf("%d\n", a->row-*i);
		return;
	}
	else {
		prepend2nd(t,l);
	}
	printf("%d\n", t->data);
	Traverse(t->left,l,i);
	Traverse(t->right,l,i);
}
int main(void) {
	int i=0; //Starting row
	int input;
	struct node* T;
	struct list* L;
	L=(struct list*)malloc(sizeof(struct list));
	L->next=NULL;
	L->tree=NULL;
	if(scanf("%d", &input)>0) { //Starts the recursion
		T=Take(input);
	}
	Traverse(T,L,&i);
	freeTree(T);
	freeList(L);
	return 0;
}
