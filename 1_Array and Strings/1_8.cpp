#include <iostream>
#include <string>

using namespace std;

bool isSubstring(string s1, string s2)
{
    if(s1.find(s2) != string::npos) return true;
    else return false;
}

bool isRotation(string s1, string s2)
{
    if(s1.length()!= s2.length() || s1.length() <= 0)
    {
        return false;
    }
    return isSubstring(s1+s1, s2);
}

int main()
{
    string s1 = "apple";
    string s2 = "leapp";
    string s3 = "pplea";
    string s4 = "eappl";
    
    cout << isRotation(s1, s2) << endl;
    cout << isRotation(s1, s3) << endl;
    cout << isRotation(s1, s4) << endl;
    cout << isRotation(s2, s4) << endl;

    
}