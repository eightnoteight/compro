#include <stdlib.h>
struct node
{
	int d;
	struct node *next;
};

int main(int argc, char const *argv[])
{
	struct node *head = NULL;
	head = malloc(sizeof(struct node));
	return 0;
}