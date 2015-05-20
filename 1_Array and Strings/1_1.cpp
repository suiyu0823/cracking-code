#include <iostream>
#include <string>

using namespace std;

bool unique_character(string &s)
	{

		if (s.size() > 128) return false;

		bool char_set [256];
		for (int i = 0; i < s.size(); i++)
		{

			int val = s.at(i);
			char c = s.at(i);
			//cout << c << endl;
			if (char_set[val]){
				cout << "fk" << endl;
				return false;
			}
			cout << "jj" << endl;
			char_set[val] = true;
		}
		return true;
	}

int main()
{
	string s = "Test string" ;
	bool test = unique_character(s);
	cout << test << endl;

}