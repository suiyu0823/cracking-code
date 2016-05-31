#include <iostream>
#include <string>

using namespace std;

void reverse (string &s)
	{
		char end [s.size()];
		if (s.size() > 0)
		{
			int j = s.size() - 1;
			for (int i = 0; i < s.size(); i++)
			{
				end[i] += s[j];
				j--; 
			}
			s = string(end);

		}
		
	}

int main()
{

	string s = "I    love xiuxiu da bao";
	reverse(s);
	cout << s << endl;
}