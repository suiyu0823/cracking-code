#include <iostream>
#include <string>

using namespace std;

//bool permutation (string &s, string &t) // its not permutation, its palidorme
//	{
//		if (s.size() != t.size()) return false;
//
//		//char temp[s.size()];
//		//strcpy(temp, s.c_str());
//		int j = s.size() - 1;
//		for (int i = 0; i < s.size(); i++)
//		{
//			//cout << i << endl;
//			if (s[j] != t[i])
//			{
//				return false;
//			}
//			j--;
//		}
//		return true;
//	}

bool isAnagram(string s, string t){
    if(s=="" || t=="") return false;
    if(s.length() != t.length()) return false;
    
    int len = s.length();
    int c[256];
    memset(c, 0, sizeof(c));
    for(int i=0; i<len; ++i){
        ++c[(int)s[i]];
        --c[(int)t[i]];
    }
    
    for(int i=0; i<256; ++i)
        if(c[i] != 0)
            return false;
    return true;
}
int main()
	{
		string s = "abbc";
		string t = "cbab";

		bool test = isAnagram(s, t);
		cout << test << endl;

	}