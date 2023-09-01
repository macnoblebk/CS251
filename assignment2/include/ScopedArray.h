// Author: Mac-Noble Brako-Kusi
// File: ScopedArray.h
// Date: August 31, 2023
// Purpose: Declaration file for ScopedArray class


#ifndef MY_SCOPED_ARRAY_H
#define MY_SCOPED_ARRAY_H

#include "iostream"

template<typename T>
class ScopedArray {

    public:
         explicit ScopedArray(T* ptr = nullptr);

        ~ScopedArray();

         T* get() const;

         const T& operator[](size_t) const;

         T& operator[](size_t) ;

         explicit operator bool() const;

         T* release();

         void reset(T* rhs = nullptr);

         void swap(ScopedArray& rhs);

    private:
        ScopedArray(const ScopedArray&) = delete;
        const ScopedArray& operator=(const ScopedArray&) = delete;

        T* scopedArray_;
};


#include "../src/ScopedArray.cpp"
#endif // MY_SCOPED_ARRAY_H
