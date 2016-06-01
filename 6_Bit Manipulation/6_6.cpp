#include <iostream>
#include <vector>
using namespace std;

int swap_bit(int val)
{
    return ((val & 0x55555555) << 1) | ((val & 0xAAAAAAAA) >> 1); //AND with 0x55555555 to clear odd bits
                                                                  //AND with 0xAAAAAAAA to clear even bits
}

int main(){
    int a = 19;
    cout << swap_bit(19) << endl;
    return 0;
}