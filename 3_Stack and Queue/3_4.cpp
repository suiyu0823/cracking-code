#include <iostream>
#include <stack>
using namespace std;


//hanoi tower problem, first we try the classical method with recursive

//void hanoi(int n, char src, char bri, char dst)
//{
//
//    if(n == 1)
//    {
//        cout << "Move disk " << n << " from " << src << " to " <<dst << endl;
//    }
//    else
//    {
//        hanoi(n-1 , src, dst, bri);
//        cout << "Move disk " << n << " from " << src << " to " <<dst << endl;
//        hanoi(n-1, bri, src, dst);
//    }
//}

struct hanoi
{
    int begin, end;
    char src, bri, dst;
    hanoi(int pbegin, int pend, char psrc, char pbri, char pdst)
    {
        begin = pbegin;
        end = pend;
        src = psrc;
        bri = pbri;
        dst = pdst;
    }
    hanoi()
    {}
};

void hanoi_stack(int n, char src, char bri, char dst)
{
    stack<hanoi>st;
    hanoi temp;
    st.push(hanoi(1, n, src, bri, dst));
    while(!st.empty())
    {
        temp = st.top();
        st.pop();
        if(temp.begin != temp.end)
        {
            st.push(hanoi(temp.begin, temp.end-1, temp.bri, temp.src, temp.dst));
            st.push(hanoi(temp.end, temp.end,temp.src, temp.bri, temp.dst));
            st.push(hanoi(temp.begin, temp.end-1, temp.src, temp.dst, temp.bri));
        }
        else{
            cout<<"Move disk "<<temp.begin<<" from "<<temp.src<<" to "<<temp.dst<<endl;
        }
    }
}
int main(){
    int n = 3;
    hanoi_stack(n, 'A', 'B', 'C');
    return 0;
}