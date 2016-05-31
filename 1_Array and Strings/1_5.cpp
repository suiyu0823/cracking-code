#include <iostream>
#include <string>

using namespace std;

//int countCompression(string &s) //very slow O(p+k*k)
//	{
//
//		if (s.empty()) return 0;
//		char last = s[i];
//		int size = 0;
//		int count = 1;
//
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (s[i] == last){
//				count++;
//			}
//			else{
//				last = s[i];
//				size += 1 + 
//				count = 1;
//			}
//		}
//	}

int countCompression(string &s)
{
    if(s.empty()) return 0;
    char last = s[0];
    int size = 0;
    int count = 1;
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] == last){
            count++;
        }
        else{
            last = s[i];
            size += 1 + to_string(count).size();
            count = 1;
        }
    }
    size += 1 + to_string(count).size();
    return size;
}

int setChar(char array[], char c, int index, int count)
{
    array[index] = c;
    index++;
    char cnt[to_string(count).size()];
    strcpy(cnt, to_string(count).c_str());
    int cnt_size = (sizeof (cnt)/ sizeof(cnt[0]));
    cout << cnt_size << endl;
    for(int i = 0; i < cnt_size; i++)
    {
        array[index] = cnt[i];
        index++;
        
    }
    cout << "cnt is " << cnt << endl;
    cout << "array is " << array<< endl;
    return index;
}

string compress(string &str)
{
    int size = countCompression(str);
    if (size > str.size())
    {
        return str;
    }
    char array[size + 1];
    memset(array, '\0', sizeof(array));
    int index = 0;
    char last = str[0];
    int count = 1;
    for(int i = 1; i < str.size(); i++)
    {
        if(str[i] == last){
            count++;
        }
        else
        {
            index = setChar(array, last, index, count);
            last = str[i];
            count = 1;
        }
    }
    index = setChar(array, last, index, count);
    return string(array);
}

int main()
{
     string s = "bbba";
     cout << compress(s) << endl;
}