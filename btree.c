#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct SYMBOL{
	char *id;
	char *type;
	int index;
}symbol;
typedef struct TNODE{
	symbol* data;
	struct TNODE* left;
	struct TNODE* right;
}Tnode;
symbol* create (char* id,char* type,int index);
void insert(Tnode*,symbol*);
Tnode* new_node(symbol* n);
void dump(Tnode*);



int main(void)
{
	Tnode* root;
	symbol* t1;
	symbol* t2;
	symbol* t3;
	root = (Tnode*)malloc(sizeof(Tnode));
	root = new_node(create("t","tt",5));
	t1 = create("t","tt",3);
	t2 = create("t","tt",6);
	insert(root,t1);
	insert(root,t2);
	getchar();
	dump(root);


}
symbol* create (char* id,char* type,int index)
{
	symbol* new = (symbol*)malloc(sizeof(symbol));
	new->id = (char*)malloc(strlen(id)*sizeof(char));
	strcpy(new->id,id);
	printf("id \t %s\n", new->id);
	new->type = (char*)malloc(strlen(type)*sizeof(char));
	strcpy(new->type,type);
	printf("type \t %s\n", new->type);
	new->index = index;
	printf("index \t %d\n", new->index);
	return new;

}
Tnode* new_node(symbol* n)
{
	Tnode* new;
	new = (Tnode*)malloc(sizeof(Tnode));
	new->data = (symbol*)malloc(sizeof(symbol));
	new->data->id = (char*)malloc(strlen(n->id)*sizeof(char));
	strcpy(new->data->id,n->id);
	new->data->type = (char*)malloc(strlen(n->type)*sizeof(char));
	strcpy(new->data->type,n->type);
	new->data->index = n->index;
	new->left = NULL;
	new->right = NULL;
	return new;
}
void insert(Tnode* t,symbol* n)
{
	
	if( n->index > t->data->index)
	{
		if( t->right == NULL)
		{
			t->right = new_node(n);
			return;
		}
		insert(t->right,n);
	}

	if( n->index <= t->data->index)
	{
		if( t->left == NULL)
		{
			t->left = new_node(n);
			return;
		}
		insert(t->left,n);
	}
}
void dump(Tnode* node)
{
	if(node != NULL)
	{
		dump(node->left);
		printf("%d \t %s \t %s\n",node->data->index,node->data->type,node->data->id );
		dump(node->right);
	}
	else
		return;

}