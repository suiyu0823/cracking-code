#include <iostream>
using namespace std;

const int maxn = 100;

struct Node
{
    int key;
    Node* lchild;
    Node* rchild;
    Node* parent;
};

Node* head;
Node* p;
Node node[maxn];
int cnt;

void init()
{
    head = p = NULL;
    memset(node, '\0', sizeof(node));
    cnt = 0;
}

void create_minimum_tree(Node*& head, Node* parent, int a[], int start, int end)
{
    if(start <= end)
    {
        int mid = (start + end) / 2;
        node[cnt].key = a[mid];
        node[cnt].parent = parent;
        head = &node[cnt++];
        create_minimum_tree(head->lchild, head, a, start, mid-1);
        create_minimum_tree(head->rchild, head, a, mid+1, end);
    }
}

int height(Node* head)
{
    if(head == NULL) return 0;
    return max(height(head->lchild), height(head->rchild)) + 1;
}

int main(){
    init();
    int a[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8
    };
    Node *head = NULL;
    create_minimum_tree(head, NULL, a, 0, 8);
    cout<<height(head)<<endl;
    return 0;
}