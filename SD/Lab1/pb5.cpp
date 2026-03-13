#include <iostream>
using namespace std;
class MyVector {
private:
    int* data;
    int size;
    int capacity;
public:
    void init() {
        size=0;
        capacity=1;
        data=new int[capacity];
    }

    void push_back(int value) {
        if (size==capacity) {
            capacity*=2;
            int* newdata=new int[capacity];
            for (int i=0;i<size;i++) {
                newdata[i]=data[i];
            }
            delete [] data;
            data=newdata;
        }
        data[size]=value;
        size++;
    }

    int get_size() {
        return size;
    }

    void pop_back() {
        if (size>0) size--;
    }
};
int main() {
    MyVector v;
    v.init();
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.pop_back();
    cout<<v.get_size()<<endl;
    v.push_back(0);
    cout<<v.get_size();
    return 0;
}