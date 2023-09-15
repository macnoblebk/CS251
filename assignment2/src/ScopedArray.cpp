// Author: Mac-Noble Brako-Kusi
// File: ScopedArray.cpp
// Date: August 31, 2023
// Purpose: Implementation file for ScopedArray class

/**
 * Constructor: Creates a ScopedArray object and takes ownership of the provided pointer.
 * @param ptr Pointer to the dynamically allocated memory to be managed.
 * @modifies Initializes the ScopedArray with 'ptr'.
 * @return N/A
 */
template<typename T>
ScopedArray<T>::ScopedArray(T *ptr)
: mArray(ptr) {}

/**
 * Destructor: Deallocates the dynamically allocated memory held by the ScopedArray.
 * @param N/A
 * @modifies Deallocates the memory pointed to by 'mArray'.
 * @return N/A
 */
template<typename T>
ScopedArray<T>::~ScopedArray() {
    delete[] mArray;
}

/**
 * Returns a pointer to the held memory.
 * @param N/A
 * @modifies N/A
 * @return Pointer to the held memory.
 */
template<typename T>
T* ScopedArray<T>:: get() const {
    return mArray;
}

/**
 * Accessor operator for reading values from the held array.
 * @param index The index of the element to access.
 * @modifies N/A
 * @return A constant reference to the element at the specified index.
 */
template<typename T>
const T& ScopedArray<T>::operator[](size_t index) const {
    return mArray[index];
}

/**
 * Accessor operator for modifying values in the held array.
 * @param index The index of the element to access.
 * @modifies N/A
 * @return A reference to the element at the specified index, allowing modification.
 */
template<typename T>
T& ScopedArray<T>::operator[](size_t index) {
    return mArray[index];
}

/**
 * Explicit conversion operator to check if the ScopedArray holds a valid pointer.
 * @param N/A
 * @modifies N/A
 * @return 'true' if the ScopedArray holds a valid pointer, 'false' otherwise.
 */
template<typename T>
ScopedArray<T>::operator bool() const {
    return mArray != nullptr;
}

/**
 * Releases ownership of the held memory and returns the pointer without deallocating it.
 * @param N/A
 * @modifies Resets the internal pointer to nullptr, relinquishing ownership.
 * @return Pointer to the previously held memory.
 */
template<typename T>
T* ScopedArray<T>::release() {
    T* temp = mArray;
    mArray = nullptr;
    return temp;
}

/**
 * Resets the ScopedArray to point to a new memory location, optionally deallocating the previous memory.
 * @param rhs Pointer to the new memory location. If nullptr, only deallocate the previous memory.
 * @modifies Deallocates the previous memory (if not nullptr) and updates 'mArray' to 'rhs'.
 * @return N/A
 */
template<typename T>
void ScopedArray<T>::reset(T *rhs) {
    if (rhs != mArray) {
        delete[] mArray;
        mArray = rhs;
    }
}

/**
 * Swaps the contents of two ScopedArray objects, effectively exchanging their memory ownership.
 * @param rhs The ScopedArray to swap content with.
 * @modifies Exchanges the internal pointers between this and 'rhs'.
 * @return N/A
 */
template<typename T>
void ScopedArray<T>::swap(ScopedArray<T> &rhs) {
    std::swap(mArray, rhs.mArray);
}
