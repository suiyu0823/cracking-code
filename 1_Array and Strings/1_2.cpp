#include <iostream>
#include <string>

using namespace std;

string reverse (string &s)
	{
		char end [s.size()];
		string temp ;
		if (s.size() > 0)
		{
			int j = s.size() - 1;
			for (int i = 0; i < s.size(); i++)
			{
				cout << i << endl;
				end[i] += s[j];
				j--; 
			}
			temp = string(end);

		}
		return temp;
		
	}

int main()
{

	string s = "I love xiuxiu da bao";
	string test = reverse(s);
	cout << test << endl;
}