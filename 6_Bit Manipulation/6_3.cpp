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
int next(int val)
{
    int max_int = ~(1 << 31);
    int num = count_one(val);
    if(num == 0 || val == -1) return -1;
    for(++val; count_one(val) != num && val < max_int; ++val);
    if(count_one(val == num)) return val;
    return -1;
}

int previous(int val)
{
    int min_int = (1 << 31);
    int num = count_one(val);
    if(num == 0 || val == -1) return -1;
    for(--val; count_one(val) != num && val > min_int; --val);
    if(count_one(val == num)) return val;
    return -1;
}


int main(){
    int a = 4;
    cout << next(a) << " " << previous(a) << endl;
    return 0;
}