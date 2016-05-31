#include <iostream>
#include <stack>

using namespace std;

//using two stacks to implement queue

template <typename T>
class MyQueue {
    stack<T>in, out;
    
public:
    MyQueue(){}
    ~MyQueue(){}
    void move(stack<T>&src, stack<T>&dst)
    {
        if(dst.empty()) //avoid unnecessary movement unless dst stack is empty
        {
            while(!src.empty())
            {
                dst.push(src.top());
                src.pop();
            }
        }
    }
    void push(T val)
    {
        in.push(val);
    }
    void pop()
    {
        move(in, out);
        out.pop();
    }
    
    T front()
    {
        move(in, out);
        return out.top();
    }
    
    T back()
    {
        move(out, in);
        return in.top();
    }
    
    int size()
    {
        return in.size() + out.size();
    }
    
    bool empty()
    {
        return in.empty() && out.empty();
    }
};

int main(){
    MyQueue<int> q;
    for(int i=0; i<10; ++i){
        q.push(i);
    }
    
    cout<<q.front()<<" "<<q.back()<<endl;
    cout<<endl;
    q.pop();
    q.push(10);
    cout<<q.front()<<" "<<q.back()<<endl;
    cout<<endl;
    q.pop();
    q.push(11);
    cout<<q.size()<<" "<<q.empty()<<endl;
    return 0;
}