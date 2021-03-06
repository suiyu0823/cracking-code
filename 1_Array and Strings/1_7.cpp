#include <iostream>
using namespace std;

void setZero(int *m, int row, int col)
	{
		bool m_row [row];
		bool m_col [col];
		int i , j;
        
        memset(m_row, false, sizeof(m_row));
        memset(m_col, false, sizeof(m_col));
		

		for (i = 0; i < row; i++)
		{
			for (j =0 ;j < col; j++)
			{				
				if (*(m + i * col + j) == 0)
				{
					m_row[i] = true;
					m_col[j] = true;
				}
			}
		}
        
		for (i = 0; i < row; i++)
		{
				for (j = 0; j < col; j++)
				{
                    if(m_row[i] || m_col[j])
                    {
                        *(m + i * col + j) = 0;
                    }
				}
		}

	}
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
int main()
{
	int source[4][4] = {{1,2,0,4}, {5,6,7,8},{9,10,11,12},{13,14,15,16}};
	int row = 4;
	int col = 4;
	int *m = (int *)source;
	printMatrix(m, row, col);

    cout << endl;
	setZero(m,row,col);
	printMatrix(m,row,col);


}