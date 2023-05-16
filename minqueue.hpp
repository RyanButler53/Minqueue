#ifndef MINQUEUE_HPP_INCLUDED
#define MINQUEUE_HPP_INCLUDED

#include <iostream>
#include "quack.hpp"

template<typename T>
class Minqueue
{
private:

    Quack<T> realQueue_;
    Quack<T> helperQueue_;
    size_t size_;

public:
    Minqueue();
    ~Minqueue() = default;

    void enqueue(T item);
    T dequeue();
    T findMin();
    size_t size() const;

    void printToStream(std::ostream &os) const;
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const Minqueue<T> &mq);

#include "minqueue-private.hpp"

#endif //MINQUEUE_HPP_INCLUDED