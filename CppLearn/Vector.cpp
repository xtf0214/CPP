#include <cstdlib>
#include <initializer_list>
#include <iostream>
#include <stdexcept>

template <typename T> class Vector {
  public:
    Vector() : data(nullptr), size(0), capacity(0) {}
    Vector(size_t n, const T &value = T{}) : data(new T[n]), size(n), capacity(n) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = value;
        }
    }
    Vector(std::initializer_list<T> il)
        : data(new T[il.size()]), size(il.size()), capacity(il.size()) {
        size_t i = 0;
        for (const auto &elem : il) {
            data[i++] = elem;
        }
    }
    Vector(const Vector &other) : data(new T[other.size]), size(other.size), capacity(other.size) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    Vector &operator=(const Vector &other) {
        if (this != &other) {
            delete[] data;
            data = new T[other.size];
            size = other.size;
            capacity = other.size;
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    ~Vector() { delete[] data; }

    // 迭代器
    T *begin() { return data; }
    T *end() { return data + size; }
    const T *begin() const { return data; }
    const T *end() const { return data + size; }

    // 访问元素
    T &at(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
    T &operator[](size_t index) { return data[index]; }
    const T &operator[](size_t index) const { return data[index]; }

    // 容量
    size_t getSize() const { return size; }
    size_t getCapacity() const { return capacity; }
    bool empty() const { return size == 0; }

    // 修改
    void push_back(const T &value) {
        if (size == capacity) {
            reserve(capacity == 0 ? 1 : capacity * 2);
        }
        data[size++] = value;
    }
    void reserve(size_t new_capacity) {
        if (new_capacity > capacity) {
            T *new_data = new T[new_capacity];
            for (size_t i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
    }
    void resize(size_t new_size, const T &value = T{}) {
        reserve(new_size);
        for (size_t i = size; i < new_size; ++i) {
            data[i] = value;
        }
        size = new_size;
    }

  private:
    T *data;
    size_t size;
    size_t capacity;
};

int main() {
    Vector<int> v = {1, 2, 3, 4, 5};
    v.push_back(6);
    v[1] = 30;
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}