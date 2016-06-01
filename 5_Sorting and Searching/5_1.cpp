#include <iostream>

using namespace std;

void merge(int a[], int b[], int lastA, int lastB)
{
    int indexA = lastA - 1;
    int indexB = lastB - 1;
    int indexMerged = lastB + lastA - 1;
    
    while(indexB >= 0)
    {
        if(indexA >= 0 && a[indexA] > b[indexB])
        {
            a[indexMerged] = a[indexA];
            indexA--;
        }
        else
        {
            a[indexMerged] = b[indexB];
            indexB--;
        }
        indexMerged--;
    }
}

int main()
{
    int a[10] = {1,2,3,4,5,6};
    int b[] = {4,7,8,};
    
    merge(a, b , 6, 3);
    
    for(int i = 0; i < 10; i ++)
    {
        cout << a[i] << " ";
    }
        cout << endl;
}