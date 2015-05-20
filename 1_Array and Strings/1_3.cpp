#include <iostream>
#include <string>

using namespace std;

bool permutation (string &s, string &t)
	{
		if (s.size() != t.size()) return false;

		char temp[s.size()];
		strcpy(temp, s.c_str());
		int j = s.size() - 1;
		for (int i = 0; i < s.size(); i++)
		{
			//cout << i << endl;
			if (temp[j] != t[i])
			{
				return false;
			}
			j--;
		}
		return true;
	}

int main()
	{
		string s = "dog";
		string t = "god";

		bool test = permutation(s, t);
		cout << test << endl;

	}