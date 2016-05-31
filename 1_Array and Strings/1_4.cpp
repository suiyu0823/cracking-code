#include <iostream>
#include <string>

using namespace std;

void replace(string &s)
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
		newsize = s.size() + space_count * 2;
		char tmp[newsize];
		tmp[newsize] = '\0';
		for (i = s.size()-1; i >= 0; i--)
		{
			if (s[i] == ' ')
			{
				tmp[newsize - 1] = '0';
				tmp[newsize - 2] = '2';
				tmp[newsize - 3] = '%';
                newsize = newsize - 3;
			}
			else
			{
				tmp[newsize - 1] = s[i];
				newsize = newsize - 1;
			}
		}
		s = string(tmp);
	}

int main ()
	{
		string s = "i love xiuxiu";
        replace(s);
		cout << s << endl;

	}