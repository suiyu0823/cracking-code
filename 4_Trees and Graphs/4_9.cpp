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

void init(){
    p = NULL;
    memset(node, '\0', sizeof(node));
    cnt = 0;
}
void create_minimal_tree(Node* &head, Node *parent, int a[], int start, int end){
    if(start <= end){
        int mid = (start + end)>>1;
        node[cnt].key = a[mid];
        node[cnt].parent = parent;
        head = &node[cnt++];
        create_minimal_tree(head->lchild, head, a, start, mid-1);
        create_minimal_tree(head->rchild, head, a, mid+1, end);
    }
}

void print(Node* head, int level){
    vector<int> v;
    for(int i=0; i<level; ++i){
        v.push_back(head->key);
        head = head->parent;
    }
    while(!v.empty()){
        cout<<v.back()<<" ";
        v.pop_back();
    }
    cout<<endl;
}
void find_sum(Node* head, int sum){
    if(head == NULL) return;
    Node *no = head;
    int tmp = 0;
    for(int i=1; no!=NULL; ++i){
        tmp += no->key;
        if(tmp == sum)
            print(head, i);
        no = no->parent;
    }
    //cout << "tmp is " << tmp << endl;
    find_sum(head->lchild, sum);
    find_sum(head->rchild, sum);
}

int main(){
    init();
    int a[] = {
        4, 3, 8, 5, 2, 1, 6
    };
    Node *head = NULL;
    create_minimal_tree(head, NULL, a, 0, 6);
   // cout << head->rchild->lchild->key << endl;
    find_sum(head, 8);
    return 0;
}