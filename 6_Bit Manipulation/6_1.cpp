#include <iostream>
#include <vector>
using namespace std;

void print_binary(int n){
    vector<int> v;
    int len = 8 * sizeof(int); // 32 bits
    int mask = 1;
    while(len--){ //iterate 32 times
        if(n&mask) v.push_back(1);
        else v.push_back(0);
        mask <<= 1; // shift mask to the left
    }
    while(!v.empty()){
        cout<<v.back();
        v.pop_back();
    }
    cout<<endl;
}

int update_bits(int n, int m, int i, int j){
    int ret = (1 << i) -1;
    print_binary(ret);
    ret &= n;  //ret is to save the value of n from postion 0 to i-1;
    // n >> (j+1) << (j+1) to clear all bits from position 0 to j;
    // m << i shift value of m with i.
    //it is clear now, 0 to j all clear , we restore 0 to i-1 value, keep the i to j for value of m
    return ((n>>(j+1)) << (j+1)) | (m<<i) | ret;
}

int main(){
   // int n = 1<<10, m = 19;
    //int ans = update_bits(n, m, 2, 6);
    int n = 27;
    int m = 0;
    int ans = update_bits(n, m, 1, 3);
    print_binary(n);
    print_binary(m);
    print_binary(ans);
    
    //extra test
//    
//    int a = 1;
//    a<<= 31;
//    print_binary(a);
//    a >>= 31;
//    print_binary(a);
//    
//    unsigned int b = 1;
//    b<<= 31;
//    print_binary(b);
//    b >>= 31;
//    print_binary(b);
    return 0;
}