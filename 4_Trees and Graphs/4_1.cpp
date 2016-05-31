#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
const int maxn = 100;

struct Node
{
    int key;
    Node* lchild;
    Node* rchild;
    Node* parent;
};

Node* head, *p;
Node node[maxn];
int cnt;


void init()
{
    head = p = NULL;
    memset(node, '\0', sizeof(node));
    cnt = 0;
}

void insert(Node*& head, int val) // 递归使用指针的引用
{
    if(head == NULL)
    {
        node[cnt].key = val;
        node[cnt].parent = p;
        head = &node[cnt++];
        return;
    }
    p = head;
    if(val < head->key)
        insert(head->lchild, val);
    else
        insert(head->rchild, val);
}

int d = 0 ,num = 0;
int dep[maxn];

void getDepth(Node*& head)
{
    if(head == NULL) return;
    ++d;
    getDepth(head->lchild);
    if(head->lchild == NULL && head->rchild == NULL)
    {
        dep[num++] = d;
        cout << "to the depth " << "d is " << d << " " << head->key << endl;
    }
    getDepth(head->rchild);
    --d;
}

bool isBalance(Node *head)
{
    if(head == NULL) return true;
    getDepth(head);
    int max = dep[0];
    int min = dep[0];
    for(int i = 0; i < num; i++)
    {
        if(dep[i] > max) max = dep[i];
        if(dep[i] < min) min = dep[i];
    }
    if(max - min > 1) return false;
    else return true;
}

int main(){
    init();
    //unbalanced tree, node 12 depth is 5.
    int a[] = {
        5, 3, 8, 1, 4, 7, 10, 2, 6, 9, 11
    };
    for(int i=0; i<11; ++i)
        insert(head, a[i]);
    cout<<isBalance(head)<<endl;
    return 0;
}