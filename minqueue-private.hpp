#include "minqueue.hpp"


using namespace std;

template <typename T>
Minqueue<T>::Minqueue() : realQueue_{}, helperQueue_{}, size_{0}
{
    // Nothing to do here
}

template <typename T>
void Minqueue<T>::enqueue(T item){
    realQueue_.push(item);
    while (!helperQueue_.empty() and item < helperQueue_.back())
    {
        helperQueue_.pop();
    }
    helperQueue_.push(item);
    ++size_;
}

template<typename T>
T Minqueue<T>::dequeue(){
    T item = realQueue_.front();
    realQueue_.dequeue();
    // Case where item is the minimum
    if (item == helperQueue_.front()){
        helperQueue_.dequeue();
    }
    --size_;
    return item;
}

template<typename T>
T Minqueue<T>::findMin(){
    return helperQueue_.front();
}

template <typename T>
size_t Minqueue<T>::size() const{
    return size_;
}

template <typename T>
void Minqueue<T>::printToStream(ostream &out) const {
    out << "Main: \n" << realQueue_ << "\n";
    out << "Helper: \n" << helperQueue_;
}

template <typename T>
std::ostream& operator<<(ostream &out, const Minqueue<T> &mq){
    mq.printToStream(out);
    return out;
}
