// Yasen Angelov 7MI0600465

#include "MyVector.h"

#include <stdexcept>

template<typename T>
void MyVector<T>::copyFrom(const MyVector& other) {
    size = other.size;
    capacity = other.capacity;
    data = new int[capacity];
    for (size_t i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

template<typename T>
void MyVector<T>::moveFrom(MyVector&& other) noexcept {
    data = other.data;
    size = other.size;
    capacity = other.capacity;

    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

template<typename T>
void MyVector<T>::free() {
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

template<typename T>
void MyVector<T>::resize(const size_t newCapacity) {
    if (newCapacity <= capacity) {
        return;
    }

    T* newData = new T[newCapacity];
    if (data) {
        for (size_t i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
    }
    data = newData;
    capacity = newCapacity;
}

template<typename T>
MyVector<T>::MyVector(const size_t size) : capacity(size) {
    data = new T[capacity];
}

template<typename T>
MyVector<T>::MyVector(const MyVector& other) {
    copyFrom(other);
}

template<typename T>
MyVector<T>::MyVector(MyVector&& other) noexcept {
    moveFrom(move(other));
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(MyVector&& other) noexcept {
    if (this != &other) {
        free();
        moveFrom(move(other));
    }
    return *this;
}

template<typename T>
MyVector<T>::~MyVector() {
    free();
}

template<typename T>
ostream& operator<<(ostream& os, const MyVector<T>& myVector) {
    for (size_t i = 0; i < myVector.size; i++) {
        os << myVector.data[i] << endl;
    }
    return os;
}

template<typename T>
istream& operator>>(istream& is, MyVector<T>& myVector) {
    for (size_t i = 0; i < myVector.size; i++) {
        is >> myVector.data[i];
    }
    return is;
}

template<typename T>
T& MyVector<T>::operator[](size_t index) {
    if (index >= size) throw out_of_range("Index out of range");
    return data[index];
}

template<typename T>
const T& MyVector<T>::operator[](size_t index) const {
    if (index >= size) throw out_of_range("Index out of range");
    return data[index];
}

template<typename T>
size_t MyVector<T>::getSize() const {
    return size;
}

template<typename T>
const T* MyVector<T>::getData() const {
    return data;
}

template<typename T>
void MyVector<T>::push(const T& value) {
    if (size == capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = value;
}