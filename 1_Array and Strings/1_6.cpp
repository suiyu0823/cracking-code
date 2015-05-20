#include <iostream>
using namespace std;

void printMatrix(int *m, int row, int col)
	{
		int i, j;
		if (m == NULL)
			return;
		for (i = 0; i < row; i++){
			for (j = 0; j < col; j++){
				cout << *(m + i*col + j) << "\t";
			}
			cout << endl;
		}
	}

void rotateMatrix(int *m, int *dest, int row, int col)
	{
		int i, j, k, l;
		for (i = 0, l = row -1; i < row; i++, l--)
		{
			for (j = 0, k = 0; j < col; j++, k++)
			{
				*(dest + k * row + l) = * (m + i * col + j);
			}
		}
	}

int main()
	{
		int test[4][4] = {{1,2,3,4}, {5,6,7,8},{9,10,11,12},{13,14,15,16}};
		int row = 4;
		int col = 4;
		int *source = (int *)test;
		int *destination = (int *)new int[4][3];

		cout << "source matrix..." << endl;
		printMatrix(source, row, col);
		cout << endl;

		cout << "after rotating 90 deg.." << endl;
		rotateMatrix(source, destination, row, col);
		printMatrix(destination, col, row);
		cout << endl;

		return 0;
	}