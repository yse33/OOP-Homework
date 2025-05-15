// Yasen Angelov 7MI0600465

#pragma once
#include <iostream>

using namespace std;

template<typename T>
class MyVector;

template<typename T>
ostream& operator<<(ostream& os, const MyVector<T>& myVector);
template<typename T>
istream& operator>>(istream& is, MyVector<T>& myVector);

template<typename T>
class MyVector {
private:
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void copyFrom(const MyVector& other);
    void moveFrom(MyVector&& other) noexcept;
    void free();
    void resize(size_t newCapacity);
public:
    MyVector() = default;

    explicit MyVector(size_t size);

    MyVector(const MyVector& other);
    MyVector(MyVector&& other) noexcept;

    MyVector& operator=(const MyVector& other);
    MyVector& operator=(MyVector&& other) noexcept;

    ~MyVector();

    friend ostream& operator<< <>(ostream& os, const MyVector& myVector);
    friend istream& operator>> <>(istream& is, MyVector& myVector);

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    size_t getSize() const;
    const T* getData() const;

    void push(const T& value);
};