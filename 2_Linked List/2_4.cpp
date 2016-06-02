#include<iostream>
#include<vector>

using namespace std;

typedef struct node
{
	int data;
	node *next;
}node;

node *init (vector<int>v)
{
	node *head, *p;

	for (int i = 0; i < v.size() ; i++)
	{
		node *temp = new node();
		temp->data = v.at(i);
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

node *partition(node *n, int k)
{
	node *head = n;
	node *tail = n;
	while (n != NULL)
	{
		node *temp = n->next;
		if (n->data > k)
		{
			n->next = head;
			head = n;
		}
		else
		{
			tail = n;
		}
		n = temp;
	}
	tail->next = NULL;
	print(head);
	return head;
}
int main()
{

	vector<int> v;
	for (int i = 0; i < 5; i++)
	{
		v.push_back(i);
	}
	node *head = init(v);
	print(head);
	cout << "after partition" << endl;
	partition(head, 3);
	
}