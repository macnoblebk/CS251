// Author: Mac-Noble Brako-Kusi
// File: ArrayList.cpp
// Date: September 14, 2023
// Purpose: Implementation file for ArrayList class



template<typename T>
ArrayList<T>::ArrayList()
    : mSize(0),
      mCapacity(0),
      mArray(nullptr){}

template<typename T>
ArrayList<T>::ArrayList(const uint32_t &size, const T &value)
        : mSize(size),
          mCapacity(2*size),
          mArray{value}{}
