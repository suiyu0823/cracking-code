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

node *addlink(node *p, node *q)
{
	if (p == NULL) return q;
	if (q == NULL) return p;
	node *res = NULL;
	node *runner = NULL;
	int carry = 0;
	while (p && q)
	{
		int temp_val = p->data + q->data + carry;
		node *r = new node();
		r->data = temp_val%10;
		if (runner)
		{
			runner->next = r;
			runner = r;
		}
		else
		{
			runner = res = r;
		}
		carry = temp_val/10;
		p = p->next;
		q = q->next;
		
	}
	while (p)
	{
		int temp_val = p->data + carry;
		node *r = new node();
		r->data = temp_val%10;
		runner->next = r;
		runner = r;
		carry = temp_val/10;
		p = p->next;
	}
	while (q)
	{
		int temp_val = q->data + carry;
		node *r = new node();
		r->data = temp_val%10;
		runner->next = r;
		runner = r;
		carry = temp_val/10;
		q = q->next;
	}
	if (carry > 0)
	{
		node *r = new node();
		r->data = carry;
		runner->next = r;
	}
	return res;
}

node *reverse(node *head)
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
int main()
{
	vector<int> v_1;
	vector<int> v_2;

	v_1.push_back(1);
	for (int i = 1; i < 6 ; i++)
	{
		v_1.push_back(2*i+1);
		v_2.push_back(2*i);
	}
	node *p = init(v_1);
	node *q = init(v_2);
	cout << "forward order" << endl;
	print(p);
	print(q);
	node *result = addlink(p, q);
	print(result);
	cout << "reverse order" << endl;
	node *p_rev = reverse(p);
	node *q_rev = reverse(q);
	print(p_rev);
	print(q_rev);
	node *result_rev = addlink(p_rev, q_rev);
	print(result_rev);
}