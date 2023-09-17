#include <iostream>
using namespace std;

class house {

    // member variables (private)
    int length, breadth;

public:

    // member functions (public)
    void setData(int x, int y) {
        this->length = x;
        this->breadth = y;
    }

    void area() {
        cout << this->length*this->breadth << endl;
    }
};

int main() {

    house h1;
    h1.setData(20,30);
    h1.area();

    // I can do like this 
    house* h2 = new house();
    h2->setData(40,30);
    h2->area();


}   