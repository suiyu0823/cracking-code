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

void remove(node *head)
{
	if(head == NULL) return;
	node * end = head->next;
	head->data = end->data;
	head->next = end->next;
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
    int cc = 3;
    node* c = head;
    for (int i = 1; i < cc; i++)
    {
        c = c->next;
    }
	remove(c);
    print(head);
}