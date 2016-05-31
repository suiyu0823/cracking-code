#include <iostream>
#include <vector>

using namespace std;
typedef struct node
{
	/* data */
	int data;
	node * next;
}node;

node *init (vector<int>v)
{
	node *head, *p, *q;

	for (int i = 0; i < v.size() ; i++)
	{
		node *temp = new node();
		temp->data = v.at(i);
		if (i == v.size()-3)
		{
			q = temp;
		}
		if (i == 0)
		{
			head = p = temp;
			continue;
		}
		p->next = temp;
		p = temp;
	}
	p->next = q;
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

node *findloopstart(node *head)
{
	node *fast = head;
	node *slow = head;
	int i = 0;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow)
		{
			break;
		}
	}

	if (fast == NULL || fast->next == NULL)
	{
		return NULL;
	}

	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return fast;
}
int main()
{
	vector<int> v_1;

	for (int i = 1; i < 12 ; i++)
	{
		v_1.push_back(i);
	}
	node *p = init(v_1);
	//print(p);
	node *loop = findloopstart(p);
	if (loop)
	{
		cout << loop->data << endl;
	}

}