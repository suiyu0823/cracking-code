#include <iostream>
#include <vector>
#include <string>
using namespace std;

string print_binary(string val)
{
    int decimal_position = val.find('.', 0);
    int int_part = atoi(val.substr(0, decimal_position).c_str());
    double dec_part = atof(val.substr(decimal_position, val.length() - decimal_position).c_str());
    string int_str = "", dec_str = "";
    while(int_part > 0)
    {
        if(int_part & 1)
            int_str = "1" + int_str;
        else
            int_str = "0" + int_str;
        int_part >>= 1;
    }
    while(dec_part > 0)
    {
        if(dec_str.length() > 32) return "ERROR";
        dec_part *= 2;
        if(dec_part >= 1)
        {
            dec_str += "1";
            dec_part -= 1;
        }
        else
            dec_str += "0";
    }
    return int_str + "." + dec_str;
}

int main()
{

    string val = "11.25";
    cout << print_binary(val) << endl;
}