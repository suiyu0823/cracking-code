#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

//using two stacks to implement queue

stack<int>stack_sort(stack<int>src)
{
    stack<int>dst;
    while(!src.empty())
    {
        int data = src.top();
        src.pop();
        while(!dst.empty() && dst.top() > data)
        {
            src.push(dst.top());
            dst.pop();
        }
        dst.push(data);
    }
    return dst;

}
int main(){
   // srand((unsigned)time(0));
    
    stack<int>s;
//    
//    for (int i = 0; i < 10; i++)
//    {
//        s.push((rand()%100));
//    }
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    s = stack_sort(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout << endl;
    return 0;
}