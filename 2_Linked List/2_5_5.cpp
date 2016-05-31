#include <iostream>
#include <complex>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class List
{
private:
    Node* head;
public:
    List(){head = NULL;}
    ~List(){};
    void addNode(int val);
    void reverse();
    void print();
    int size();
    void prepend(int data);

    Node* mhead(){return head;}
};

void List::addNode(int val)
{
    Node* temp = new Node();
    temp->data = val;
    temp->next = NULL;
    
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        Node* runner = head;
        while(runner->next != NULL)
        {
            runner = runner->next;
        }
        runner->next = temp;
    }
}

void List::print()
{
    Node* runner = head;
    while(runner != NULL)
    {
        cout << runner->data << " ";
        runner = runner->next;

    }
    cout << endl;
}
int List::size()
{
    Node* itr = head;
    int count = 0;
    while(itr != NULL)
    {
        itr = itr->next;
        count++;
    }
    return count;
}

void List::reverse()
{
    Node* current = head;
    Node* previous = NULL;
    Node* next = NULL;
    while(current != NULL)
    {
        head = current;
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
}

void List::prepend(int val)
{
    Node* temp = new Node();
    temp->data = val;
    temp->next = head;
    head = temp;
}

int addNode(Node* n1, Node* n2, List* l)
{
    if(n1 == NULL || n2 == NULL) return 0;
    int carry = addNode(n1->next, n2->next, l);
    int val = carry + n1->data + n2->data;
    int carry_next = val / 10;
    int node_val = val % 10;
    
    l->prepend(node_val);
    
    return carry_next;
}

void addList(List* l1, List* l2, List* l3)
{
    if(l1 == NULL || l2 == NULL) return;
    int size_1 = l1->size();
    int size_2 = l2->size();
    int diff = abs(size_1 - size_2);
    
    if(size_1 > size_2)
    {
        while(diff)
        {
            l2->prepend(0);
            diff--;
        }
    }
    else if(size_1 < size_2)
    {
        while(diff)
        {
            l1->prepend(0);
            diff--;
        }
    }
    
    int carry = addNode(l1->mhead(), l2->mhead(), l3);
    if(carry)
    {
        l3->prepend(carry);
    }
}



int main()
{
    List* list_1  = new List();
    list_1->addNode(6);
    list_1->addNode(1);
    list_1->addNode(7);
    List* list_2  = new List();
    list_2->addNode(2);
    list_2->addNode(9);
    list_2->addNode(5);
    
    list_1->reverse();
    list_2->reverse();
    
    List* list_3 = new List();
    
    addList(list_1, list_2, list_3);
    
    list_3->print();
    
    delete list_1;
    delete list_2;
    delete list_3;
}