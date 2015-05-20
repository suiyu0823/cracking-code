#include <iostream>
#include <string>

using namespace std;

int countCompression(string &s)
	{

		if (s.empty()) return 0;
		char last = s[i];
		int size = 0;
		int count = 1;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == last){
				count++;
			}
			else{
				last = s[i];
				size += 1 + 
				count = 1;
			}
		}
	}