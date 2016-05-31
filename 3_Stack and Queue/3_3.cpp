#include <iostream>

using namespace std;

class stack
{
private:
    int *buf;
    int cur;
    int capacity;
    
public:
    stack(int capa = 100)
    {
        buf = new int[capa];
        cur = -1;
        capacity = capa;
    }
    ~stack()
    {
        delete[]buf;
    }
    void push(int val)
    {
        buf[++cur] = val;
    
    }
    void pop()
    {
        --cur;
    }
    
    int top()
    {
        return buf[cur];
    }
    bool empty()
    {
        return cur == -1;
    }
    bool full()
    {
        return cur == capacity - 1;
    }
};

class SetOfStacks
{
private:
    stack* st;
    int cur;
    int capacity;
public:
    SetOfStacks(int capa = 10)
    {
        st = new stack[capa];
        cur = 0;
        capacity = capa;
    }
    ~SetOfStacks()
    {
        delete[]st;
    }
    void push(int val)
    {
        if(st[cur].full())
            ++cur;
        st[cur].push(val);
    }
    void pop()
    {
        while(st[cur].empty())
            --cur;
        st[cur].pop();
    }
    int top()
    {
        while(st[cur].empty())
            --cur;
        return st[cur].top();
    }
    bool empty()
    {
        while(st[cur].empty())
            --cur;
        if(cur == -1) return true;
        else return false;
    }
    bool full()
    {
        if(cur == capacity -1) return st[cur].full();
        else return false;
    }
    void popAt(int index)
    {
        while(st[cur].empty())
            --index;
        st[index].pop();
    }
    int getCur()
    {
        return cur;
    }
};

int main()
{
    SetOfStacks ss1;
    //create 4 child stacks, cur is equal to 3
    for(int i=0; i<3*100+1; ++i){
        ss1.push(i);
    }
    for(int i=0; i<100; ++i){
        ss1.popAt(0);
        //ss1.popAt(1);
        //ss1.popAt(2);
    }
     cout << ss1.getCur() << endl;
    for(int i=0; i<100; ++i){
        //ss1.popAt(0);
        //ss1.popAt(1);
        ss1.popAt(2);
    }
    cout << ss1.getCur() << endl;
    ss1.popAt(3);
    cout << ss1.getCur() << endl;
    while(!ss1.empty()){
      //  cout<<ss1.top()<<endl;
        ss1.pop();
    }
    cout << ss1.getCur() << endl;
    return 0;
}