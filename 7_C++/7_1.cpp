#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void printLast_Kth_Lines(ifstream &fin, int k)
{
    string* line = new string[k]; //string array need to dynamically allocated
    int lines = 0;
    string temp;
    while(getline(fin, temp))
    {
        line[lines%k] = temp;
        lines++;
    }
    int start, count;
    
    if(lines < k)
    {
        start = 0;
        count = lines;
    }
    else
    {
        start = lines%k;
        count = k;
    }
    cout << start << endl;
    for(int i = 0; i < count; i++)
    {
        cout << line[(start + i) % k] << endl;
    }
    delete[]line;
}

int main(){
    ifstream fin("7_1.txt");
    int k = 4;
    printLast_Kth_Lines(fin, k);
    fin.close();
    return 0;
}