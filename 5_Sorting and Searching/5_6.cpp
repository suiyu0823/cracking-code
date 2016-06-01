#include <iostream>
using namespace std;


int search(int a[][4], int r, int c, int val)
{
    int row = 0;
    int col = c - 1;
    while (row < r && col >= 0)
    {
        if(a[row][col] == val) // 和右上角的值比，如果小于减去一行，如果大于加上一列
            return row * c + col;
        else if(a[row][col] < val)
            row++;
        else
            col--;
    }
    return -1;
}
int main(){
    int a[4][4] = {
        {15,20,40,85},
        {20,35,80,95},
        {30,55,95,105},
        {40,80, 100, 120}
        };
    int result = search(a, 4, 4, 80);
    if (result == -1)
    {
        cout << "not found " << endl;
    }
    else
    {
        int row = result / 4 + 1;
        int col = result % 4 + 1;
        cout <<"position at row " << row << " and col " << col << endl;
    }
    return 0;
}