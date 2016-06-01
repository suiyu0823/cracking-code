#include <iostream>
using namespace std;

//binary search method for O(logn)
int search(int a[], int left, int right, int val)
{
    int mid = (left + right) /2;
    if(val == a[mid]){
        return mid;
    }
    if(right < left)
    {
        return -1;
    }
    //Either the left or right half must be normally ordered.
    
    if(a[left] < a[mid]) // left is normally ordered
    {
        if(val >= a[left] && val <= a[mid])
        {
            return search(a, left, mid - 1, val);
        }
        else
        {
            return search(a, mid + 1, right, val);
        }
    }
    else if(a[mid] < a[left]) // right is normally ordered
    {
        if(val >= a[mid] && val <= a[right])
        {
            return search(a, mid + 1, right, val);
        }
        else
        {
            return search(a, left, mid - 1, val);
        }
    }
    else if(a[left] == a[mid])
    {
        if(a[mid] != a[right])
        {
            return search(a, mid + 1, right, val);
        }
        else
        {
            int result = search(a , left, mid - 1, val);
            if(result == -1)
            {
                return search(a, mid + 1, right, val);
            }
            else
            {
                return result;
            }
        }
    }
    return -1;
}

int main()
{
    int a1[] = {10, 15, 20, 0, 5};
    int a2[] = {50, 5, 20, 30, 40};
    int a3[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    int a4[] = {2, 2, 2, 3, 4, 2};
    int result;
    
    result = search(a1, 0, 4, 0);
    cout << result << endl;
    
    result =  search(a2, 0, 4, 5);
    cout << result << endl;
    
    result =  search(a3, 0, 11, 3);
    cout << result << endl;
    
    result =  search(a4, 0, 5, 2);
    cout << result << endl;
}