// 13.8 Implement a smart pointer class, which is capable of automatic garbage collection. Count of reference is the key to this problem.
// Answer:
//    int *ref_count;
//    referece count must be int *, instead of int. Think about why.
//    The destructor function is called for (*ref_count) times, only at the last time the real data is freed.
#include <iostream>
using namespace std;

//template <class T>
template <typename T>
class Pointer {
public:
    Pointer(T *ptr) {
        data = ptr;
        ref_count = new int(1);
    };
    
    Pointer(Pointer<T> &p) {
        data = p.data;
        ref_count = p.ref_count;
        ++(*ref_count);
    };
    
    Pointer<T>& operator = (Pointer<T> &p) {
        if (this == &p) {
            // nothing to do.
            return *this;
        }
        if (*ref_count > 0) {
            cout << "operator= clear" << endl;
            remove();
        }
        data = p.data;
        ref_count = p.ref_count;
        ++(*ref_count);
        
        return *this;
    };
    
    T getData() {
        return *data;
    };
    
    void setData(const T &val) {
        *data  = val;
    };
    
    int getcount()
    {
        return *ref_count;
    }
    
    ~Pointer() {
        remove();
    };
protected:
    T *data;
    int *ref_count;
    
    void remove() {
        --(*ref_count);
        if (*ref_count == 0) {
            // if the reference count becomes 0, the data is never to be found again.
            // it must be freed.
            cout << "destructor clear" << endl;
            delete data;
            data = nullptr;
            delete ref_count;
            ref_count = nullptr;
        }
    };
};

int main()
{
    int *ptr = new int(7);
    int *ptr2 = new int (3);
    Pointer<int> p1(ptr);
    Pointer<int> p2(ptr2);
    Pointer<int> p3 = p1;
//   // cout << p1.getData() << endl;
//    p2.setData(12);
//   // cout << p2.getData() << endl;
//    p3.setData(15);
//    cout << p1.getData() << endl;
//    cout << p2.getData() << endl;
//    cout << p3.getData() << endl;
    cout << p1.getcount() <<" "<< p2.getcount() <<" " << p3.getcount() << endl;
    p2 = p3; // p2 points p3, so ptr2 needs to be clear
    cout << p1.getcount() <<" "<< p2.getcount() <<" " << p3.getcount() << endl;
    return 0;
}