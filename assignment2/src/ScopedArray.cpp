// Author: Mac-Noble Brako-Kusi
// File: ScopedArray.h
// Date: August 31, 2023
// Purpose: Implementation file for ScopedArray class

template<typename T>
ScopedArray<T>::ScopedArray(T *ptr)
: scopedArray_(ptr) {}

template<typename T>
ScopedArray<T>::~ScopedArray() {
    delete[] scopedArray_;
}

template<typename T>
T* ScopedArray<T>:: get() const {
    return scopedArray_;
}

template<typename T>
const T& ScopedArray<T>::operator[](size_t index) const {
    return scopedArray_[index];
}

template<typename T>
T& ScopedArray<T>::operator[](size_t index) {
    return scopedArray_[index];
}

template<typename T>
ScopedArray<T>::operator bool() const {
    return scopedArray_ != nullptr;
}

template<typename T>
T* ScopedArray<T>::release() {
    T* temp = scopedArray_;
    scopedArray_ = nullptr;
    return temp;
}

template<typename T>
void ScopedArray<T>::reset(T *rhs) {
    delete[] scopedArray_;
    scopedArray_ = rhs;
}

template<typename T>
void ScopedArray<T>::swap(ScopedArray<T> &rhs) {
    std::swap(scopedArray_, rhs.scopedArray_);
}
