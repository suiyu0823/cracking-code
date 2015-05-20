#include <iostream>
#include <string>

using namespace std;

string replace(string &s)
	{
		string temp;
		int space_count = 0, newsize, i;
		for (i = 0; i < s.size(); i++)
		{
			if(s[i] == ' ')
			{
				space_count++;
			}
		}
		newsize = s.size() + space_count * 3;
		char tmp[newsize];
		tmp[newsize] = '\0';
		for (i = s.size()-1; i >= 0; i--)
		{
			if (s[i] == ' ')
			{
				tmp[newsize - 1] = '0';
				tmp[newsize - 2] = '2';
				tmp[newsize - 3] = '5';
				tmp[newsize - 4] = '%';
				newsize = newsize - 4;
			}
			else
			{
				tmp[newsize - 1] = s[i];
				newsize = newsize - 1;
			}
		}
		temp = string(tmp);
		return temp;

	}

int main ()
	{
		string s = "i love xiuxiu baobao pangpang";
		string temp = replace(s);
		cout << temp << endl;

	}