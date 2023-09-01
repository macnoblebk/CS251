// Author: Mac-Noble Brako-Kusi
// File: SimpleArray.cpp
// Date: August 28, 2023
// Purpose: Implementation file for SimpleArray class
//

#include "SimpleArray.h"
/**
 * Constructor: Creates a SimpleArray object and takes ownership of the provided AllocationTracker pointer.
 * @param ptr Pointer to the AllocationTracker array to be managed.
 * @modifies Initializes the SimpleArray with 'ptr'.
 * @return N/A
 */
SimpleArray::SimpleArray(AllocationTracker* ptr): mArray(ptr) {}

/**
 * Destructor: Deallocates the dynamically allocated AllocationTracker array held by the SimpleArray.
 * @param N/A
 * @modifies Deallocates the array pointed to by 'mArray'.
 * @return N/A
 */
SimpleArray::~SimpleArray()
{
    delete [] mArray;
}

/**
 * Returns a pointer to the held AllocationTracker array.
 * @param N/A
 * @modifies N/A
 * @return Pointer to the held AllocationTracker array.
 */
AllocationTracker* SimpleArray::get() const
{
    return mArray;
}

/**
 * Checks if the SimpleArray holds a non-null AllocationTracker array.
 * @param N/A
 * @modifies N/A
 * @return 'true' if the SimpleArray holds a non-null array, 'false' otherwise.
 */
bool SimpleArray::isNonNull() const
{
    return mArray != nullptr;
}

/**
 * Accessor method for obtaining a reference to an AllocationTracker element at a specific index.
 * @param i The index of the element to access.
 * @modifies N/A
 * @return A reference to the AllocationTracker element at the specified index.
 */
AllocationTracker& SimpleArray::getReference(const uint32_t i) const
{
    return mArray[i];
}

/**
 * Releases ownership of the held AllocationTracker array and returns the pointer without deallocating it.
 * @param N/A
 * @modifies Resets the internal pointer to nullptr, relinquishing ownership.
 * @return Pointer to the previously held AllocationTracker array.
 */
AllocationTracker* SimpleArray::release()
{
    AllocationTracker* temp = mArray;
    mArray = nullptr;
    return temp;
}

/**
 * Resets the SimpleArray to point to a new AllocationTracker array, optionally deallocating the previous array.
 * @param rhs Pointer to the new AllocationTracker array. If nullptr, only deallocate the previous array.
 * @modifies Deallocates the previous array (if not nullptr) and updates 'mArray' to 'rhs'.
 * @return N/A
 */
void SimpleArray::reset(AllocationTracker* rhs)
{
    if (rhs != mArray){
        delete[] mArray;
        mArray = rhs;
    }
}

/**
 * Swaps the contents of two SimpleArray objects, effectively exchanging their AllocationTracker array ownership.
 * @param rhs The SimpleArray to swap content with.
 * @modifies Exchanges the internal pointers between this and 'rhs'.
 * @return N/A
 */
void SimpleArray::swap(SimpleArray& rhs)
{
    std::swap(mArray, rhs.mArray);
}
