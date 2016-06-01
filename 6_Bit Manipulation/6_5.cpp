#include <iostream>
#include <vector>
using namespace std;

int count_one(int val)
{
    int cnt = 0;
    for(int i = 0; i < 32; i++)
    {
        if(val&1)
        {
            cnt++;
        }
        val >>= 1;
    }
    //cout << cnt << endl;
    return cnt;
}
int convert(int a, int b)
{
   return count_one(a ^ b);
}

int main(){
    int a = 31;
    int b = 14;
    cout << convert(a, b) << endl;
    return 0;
}