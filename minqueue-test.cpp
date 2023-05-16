#include "minqueue.hpp"

int main(){
    // Test program
    Minqueue<double> mq;
    vector<double> v{5.5, 6.1, 9.0, 10.2, -1.0, 1.2, 1.5, 1.39, -2.54, 16.0};
    for (size_t i = 0; i < 5; ++i) {
        mq.enqueue(v[i]);
    }
    assert(mq.findMin() == -1.0);
    assert(mq.size() == 5);
    for (size_t i = 5; i < 8; ++i){
        mq.enqueue(v[i]);
    }
    assert(mq.dequeue() == 5.5);
    for (size_t i = 0; i < 6; ++i) {
        mq.dequeue();
    }
    assert(mq.findMin() == 1.39);
    mq.enqueue(v[8]);
    mq.enqueue(v[9]);
    assert(mq.findMin() == -2.54);
    assert(mq.size() == 3);
    cout << "All Tests pass!" << endl;
}