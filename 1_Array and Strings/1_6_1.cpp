#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void transpose(int a[][4], int n)
{
    for(int row = 0; row < n; row++)
    {
        for(int col = row+1; col < n; col++)
        {
            swap(a[row][col], a[col][row]);
        }
    }
}

void rotate(int a[][4], int n)
{
    for(int row = 0; row < n/2; row++)
    {
        for(int col = 0; col < n; col++)
        {
            swap(a[row][col], a[n-1-row][col]);
        }
    }
}

int main()
{

    int a[4][4] = {{1,2,3,4}, {5,6,7,8},{9,10,11,12},{13,14,15,16}};
    cout << "before rotation: " << endl;
    for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout << a[i][j]<< " ";
        }
        cout << endl;
    }
    cout << "after rotation: " << endl;
    transpose(a, 4);
    rotate(a, 4);
    for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout << a[i][j] <<" ";
        }
        cout << endl;
    }
}