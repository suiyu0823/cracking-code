#include <iostream>

using namespace std;

typedef struct node
{
	int data;
	node *next;
}node;

node *init (int a[], int n)
{
	node *head, *p;

	for (int i = 0; i < n ; i++)
	{
		node *temp = new node();
		temp->data = a[i];
		if (i == 0)
		{
			head = p = temp;
			continue;
		}
		else
		{
			p->next = temp;
			p = temp;
		}
	}
	return head;
}

void print(node *head)
{
	if (head == NULL) return;

	while (head)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
	
}

int findNthelements(node *head, int n)
{
	if (head == NULL) return 0;

	int i = findNthelements(head->next, n) + 1;
	if (i == n)
	{
		print(head);
		
	}
	return i;
}

node * findNthelements_iteration(node *head, int n)
{
	if (head == NULL) return NULL;

	node *p1 = head;
	node *p2 = head;

	for (int i = 0; i < n-1 ; i++)
	{
	   if (p2 == NULL) return NULL;
		p2 = p2->next;
	}
	if (p2 == NULL) return NULL;

	while (p2->next != NULL)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	print(p1);
	return p1;
}


int main()
{
	int a[] = {1,2,3,4,5,6};
	int n = 6;
	node *head = init(a, n);
	findNthelements(head,2);
	cout << "iteration approach" << endl;
	node *head_new = init(a, n);
	findNthelements_iteration(head_new, 2);

}