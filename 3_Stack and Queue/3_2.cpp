#include <iostream>
using namespace std;

const int MAX = ~(1<<31);

typedef struct node
{
    int val, min;
}node;

class stack
{
private:
    int *buf;
    int cur;
public:
    stack(int size = 100)
    {
        buf = new int[size];
        cur = -1;
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
        cur--;
    }
    int top()
    {
        return buf[cur];
    }
    bool empty()
    {
        return cur==-1;
    }
    void print()
    {
        cout << "stack is " << "{ ";
        for(int i = cur; i >= 0; i--)
        {
          cout << buf[i] << " ";
        }
        cout << "} ";
    }
};

class stackwithmin
{
private:
    stack s1, s2;
public:
    void push(int val)
    {
        s1.push(val);
        if(val <= min())
        {
            s2.push(val);
        }
        s1.print();
        cout << "min is " << s2.top() << "."<<endl;
    }
    
    void pop()
    {
        if(s1.top() == min())
        {
            s2.pop();
        }
        s1.pop();
        s1.print();
        cout << "min is " << s2.top() <<"."<< endl;
    }
    int top()
    {
        return s1.top();
    }
    bool empty()
    {
        return s1.empty();
    }
    
    int min()
    {
        if(s2.empty())
            return MAX;
        else
            return s2.top();
    }
};

int main()
{
    stackwithmin mystack;//StackWithMin mystack;
    mystack.push(5);
    mystack.push(6);
    mystack.push(3);
    mystack.push(7);
    mystack.pop();
    mystack.pop();
    return 0;
}