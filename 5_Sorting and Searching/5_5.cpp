#include <iostream>
using namespace std;

//binary search method for O(logn)
int search(string s[], int left, int right, string val)
{
    if(val == "") return -1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int t = mid;
        while(s[t] == "" && t <= right) //increment t position until not "" string
        {
            ++t;
        }
        if(t > right) // if t is out of right position, just seach left hand side
        {
            right = mid - 1;
        }
        else
        {
            if(s[t] == val) return t; // if we find search string, return
            else if (s[t] < val)
                left = t + 1; // search right hand side
            else
                right = mid - 1; // search left hand side
        }
    }
    return -1;
}

int main(){
    string s[13] = {
        "at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""
    };
    cout<<search(s, 0, 12, "ball")<<endl;
    return 0;
}