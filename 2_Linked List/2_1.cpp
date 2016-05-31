#include <iostream>
#include <cstring>

using namespace std;

typedef struct node
{
	/* data */
	int data;
	node *next;
}node;
bool table[100];

void remove(node *head)
{
	if (head == NULL ) return;

	node *current = head;
	while (current != NULL)
	{
		node * runner = current;
		while (runner->next != NULL)
		{
			if (runner->next->data == current->data)
			{
				runner->next = runner->next->next;
			}
			else
			{
				runner = runner->next;
			}
		}
		current = current->next;
	}
}

void remove_withHash(node * head)
{
	if (head == NULL) return ;
	node * current = head; 
	node * runner = head->next;
	table[head->data] = true;
	while(runner)
	{
		if(table[runner->data])
		{
			current->next = runner->next;
			runner = runner->next;
		}
		else
		{
			table[runner->data] = true;
			current = runner;
			runner = runner->next;
		}
	}
}

node *init(int a[], int n)
{
	//int size = sizeof(a);sizeof(a)/sizeof(a[0])
	node *head, *p;
	for (int i = 0; i < n; i++)
	{
		node *temp = new node();
		temp->data = a[i];
		if(i == 0)
		{
			head = p = temp;
			continue;
		}
		p->next = temp;
		p = temp;
	}
	return head;
}

void print(node *head)
{
	while (head)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
int main()
{
	int a[] = {10,10,8,7,6,5,4,3,3,2};
	int n = 10;
	node *head = init(a,n);
	print(head);
	remove(head);
	print(head);
	//delete head;
	cout << "with Buffer approach" << endl;
	memset(table, false, sizeof(table));
	node *head_new = init(a,n);
	print(head_new);
	remove(head_new);
	print(head_new);


}