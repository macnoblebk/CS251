// Author: Mac-Noble Brako-Kusi
// File: ArrayList.cpp
// Date: September 14, 2023
// Purpose: Implementation file for ArrayList class



template<typename T>
ArrayList<T>::ArrayList()
    : mSize(0),
      mCapacity(0),
      mArray(nullptr) {}

template<typename T>
ArrayList<T>::ArrayList(const uint32_t &size, const T &value)
        : mSize(size),
          mCapacity(2*size)
        {std::fill(std::begin(mArray), std::end(mArray), value);}

template<typename T>
ArrayList<T>::ArrayList(const ArrayList<T> &src)
    : mSize(src.mSize),
      mCapacity(src.mCapacity),
      mArray(new T[src.mCapacity])
    {std::copy(std::begin(src.mArray), std::end(src.mArray), std::begin(mArray));}

template<typename T>
ArrayList<T>::ArrayList(ArrayList<T> &&src) noexcept
    : mSize(src.mSize),
      mCapacity(src.mCapacity),
      mArray(src.mArray.release())
    {src.mSize = src.mCapacity = 0;}

template<typename T>
ArrayList<T> &ArrayList<T>::operator=(const ArrayList<T> &src) {
    if (this != src) {
        ArrayList<T>(src).swap(*this);
    }
    return *this;
}

template<typename T>
ArrayList<T> &ArrayList<T>::operator=(ArrayList<T> &&src) noexcept {
    if (this != &src) {
        mSize = src.mSize;
        mCapacity = src.mCapacity;
        mArray.reset(src.mArray.release());
        src.mSize = src.mCapacity = 0;
    }
    return *this;
}

template<typename T>
const uint32_t &ArrayList<T>::add(const T &value) {
    if (full()) {
        resize();
    }
    mArray[size++] = value;
    return mCapacity;
}

template<typename T>
void ArrayList<T>::set(const uint32_t &index, const T &value)  {
    if (!range())
        throw out_of_range();

    // Call add
}

template<typename T>
const T& ArrayList<T>::get(const uint32_t &index) const {
    return mArray[index];
}

template<typename T>
T& ArrayList<T>::get(const uint32_t &index) {
    return mArray[index];
}

template<typename T>
const T& ArrayList<T>::operator[](const uint32_t &index) {
    return mArray[index];
}

template<typename T>
T& ArrayList<T>::operator[](const uint32_t &index) {
    return mArray[index];
}

template<typename T>
uint32_t ArrayList<T>::size() const {
    return mSize;
}

template<typename T>
void ArrayList<T>::swap(ArrayList<T> &src) noexcept {
    std::swap(mSize,src.mSize);
    std::swap(mCapacity, src.mCapacity);
    mArray.swap(src.mArray);
}