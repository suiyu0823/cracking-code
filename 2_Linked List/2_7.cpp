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
	node *head, *p;

	for (int i = 0; i < v.size(); i++)
	{
		node *temp = new node();
		temp->data = v.at(i);

		if (i == 0)
		{
			head = p = temp;
			continue;
		}
		p->next = temp;
		p = temp;
	}
	return head;
}

node * reverse(node *head)
{
	node *cur = head;
	node *forward = NULL;
	node *previous = NULL;

	while (cur != NULL)
	{
		forward = cur->next;
		cur->next = previous;
		previous = cur;
		cur = forward;
	}
	return previous;
}

bool isPalindrome(node *p, node *q)
{
	if ((p == NULL) || (q == NULL)) return false;

	while (p && q)
	{
 		if (p->data != q->data)
 		{
 			cout << "is not Palindrome"<< endl;
 			return false;
 		}
 		p = p->next;
 		q = q->next;
	}
	cout << "is Palindrome"<< endl;
	return true;
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
int main()
{
	vector<int>v;

	for (int i = 0; i < 3; i ++)
	{
		v.push_back(i);
	}

	for (int i = 2; i >= 1; i--)
	{
		v.push_back(i);
	}

	node *p = init(v);

	print(p);

	node *q = reverse(p);

	print(q);

	bool res = isPalindrome(p, q);

	cout << res << endl;

}