#include <iostream>
#include <cstring>
#include <vector>
#include <list>
using namespace std;

const int maxn = 100;
struct Node{
    int key;
    Node *lchild, *rchild, *parent;
};
Node *p, node[maxn];
int cnt;
vector<int> v;
void init(){
    p = NULL;
    memset(node, '\0', sizeof(node));
    cnt = 0;
}
void createMinimalTree(Node* &head, Node *parent, int a[], int start, int end){
    if(start <= end){
        int mid = (start + end)>>1;
        node[cnt].key = a[mid];
        node[cnt].parent = parent;
        head = &node[cnt++];
        createMinimalTree(head->lchild, head, a, start, mid-1);
        createMinimalTree(head->rchild, head, a, mid+1, end);
    }
}

void copyBST(Node* root, vector<int> &v)
{
    if(root == NULL) return;
    copyBST(root->lchild, v);
    v.push_back(root->key);
    copyBST(root->rchild, v);
}

bool checkBST(Node* root)
{
    copyBST(root, v);
    cout << v.size() << endl;
    for(int i = 1; i < v.size(); i++)
    {
        if(v[i] <= v[i - 1])
            return false;
    }
    return true;
}


int main(){
    init();
    int a[] = {
        0, 1, 2, 3, 4, 5, 6
    };
    int b[] = {
        3, 5, 6, 1, 2, 4
    };
    Node *head = NULL;
    createMinimalTree(head, NULL, b, 0, 5);
    cout << checkBST(head) << endl;
    return 0;
}