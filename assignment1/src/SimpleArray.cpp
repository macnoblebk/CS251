// Author: Mac-Noble Brako-Kusi
// File: SimpleArray.cpp
// Date: August 28, 2023
// Purpose: Implementation file for SimpleArray class
//

#include "SimpleArray.h"

SimpleArray::SimpleArray(AllocationTracker* ptr): mArray(ptr) {}

SimpleArray::~SimpleArray()
{
    delete [] mArray;
}

AllocationTracker* SimpleArray::get() const
{
    return mArray;
}

bool SimpleArray::isNonNull() const
{
    return mArray != nullptr;
}

AllocationTracker& SimpleArray::getReference(const uint32_t i) const
{
    return mArray[i];
}

AllocationTracker* SimpleArray::release()
{
    AllocationTracker* temp = mArray;
    mArray = nullptr;
    return temp;
}

void SimpleArray::reset(AllocationTracker* rhs)
{
    if (rhs != mArray)
        delete[] mArray;

    mArray = rhs;

}

void SimpleArray::swap(SimpleArray& rhs)
{
    std::swap(mArray, rhs.mArray);
}
