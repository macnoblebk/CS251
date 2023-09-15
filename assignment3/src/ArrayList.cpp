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
          mCapacity(2*size),
          mArray{value} {}

template<typename T>
ArrayList<T>::ArrayList(const ArrayList<T> &src)
    : mSize(src.mSize),
      mCapacity(src.mCapacity),
      mArray(std::make_unique<ScopedArray<T[]>>(src.mCapacity)) {
          for (size_t i = 0; i < src.mSize; ++i)
              mArray[i] = src.mArray[i];
      }

template<typename T>
ArrayList<T>::ArrayList(ArrayList<T> &&src) noexcept
    : mSize(src.mSize),
      mCapacity(src.mCapacity),
      mArray(src.mArray.release()){
          src.mSize = src.mCapacity = 0;
      }
