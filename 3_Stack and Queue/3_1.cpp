#include <iostream>
using namespace std;

class array_stack{

private:
	int *buf;
	int p_top[3];
	int size;

public:
	array_stack(int size = 300)
	{
		buf = new int[size *3];
		p_top[0] = p_top[1] = p_top[2] = -1;
		this->size = size;
	}

	~array_stack()
	{
		delete[] buf;
	}

void push(int stackNum, int value)
	{
		int id = stackNum * size + p_top[stackNum] + 1;
		buf[id] = value;
		p_top[stackNum]++;
	}

void pop(int stackNum)
	{
		p_top[stackNum]--;
	}

int top (int stackNum)
	{
		int id = stackNum * size + p_top[stackNum];
		return buf[id];
	}

bool empty(int stackNum)
	{
		return p_top[stackNum] == -1;
	}
};

// typedef struct node
// {
// 	int val, preIdx;
// }node;


int main()
{
	array_stack mystack;

	for (int i = 0; i < 10; i++)
	{
		mystack.push(0 , i);
	}
	for (int i = 0; i < 20; i++)
	{
		mystack.push(1, i);
	}
	for (int i = 0; i < 150; i++)
	{
		mystack.push(2 , i);
	}

	for (int i = 0; i < 3; i++)
	{
		printf("this stack %d top is %d\n", i, mystack.top(i));
	}
	for(int i=0; i<3; ++i){
        mystack.pop(i);
        printf ("pop stack %d\n", i);
        printf("this stack %d top is %d\n", i, mystack.top(i));
    }
    cout << endl;
    mystack.push(0, 111);
    mystack.push(1, 222);
    mystack.push(2, 333);
    for(int i=0; i<3; ++i)
        
       printf("this stack %d top is %d\n", i, mystack.top(i));
    
    return 0;
}

