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
         // Constructor: Creates a ScopedArray object with an optional pointer to dynamically allocated memory.
         explicit ScopedArray(T* ptr = nullptr);

        // Destructor: Deallocates the memory held by the ScopedArray object.
        ~ScopedArray();

         // Returns a pointer to the held memory.
         T* get() const;

         // Accessor operator for reading values from the held array.
         const T& operator[](size_t) const;

         // Accessor operator for modifying values in the held array.
         T& operator[](size_t) ;

         // Explicit conversion operator to check if the ScopedArray holds a valid pointer.
         explicit operator bool() const;

         // Releases ownership of the held memory and returns the pointer without deallocating it.
         T* release();

         // Resets the ScopedArray to point to a new memory location, optionally deallocating the previous memory.
         void reset(T* rhs = nullptr);

         // Swaps the contents of two ScopedArray objects.
         void swap(ScopedArray& rhs);

    private:
        // Disallow copy construction.
        ScopedArray(const ScopedArray&) = delete;

        // Disallow copy assignment.
        const ScopedArray& operator=(const ScopedArray&) = delete;

        // Pointer to the dynamically allocated memory.
        T* mArray;
};


#include "../src/ScopedArray.cpp"
#endif // MY_SCOPED_ARRAY_H
