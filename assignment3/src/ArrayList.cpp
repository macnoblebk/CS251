// Author: Mac-Noble Brako-Kusi
// File: ArrayList.cpp
// Date: September 19, 2023
// Purpose: Implementation file for ArrayList template class

/**
 * Constructor: Creates an empty ArrayList.
 * @param N/A
 * @modifies Initializes an empty ArrayList with default values.
 * @return N/A
 */
template<typename T>
ArrayList<T>::ArrayList()
    : mArray(nullptr),
      mSize(0),
      mCapacity(0){}

/**
 * Constructor: Creates an ArrayList with a specified size and initializes elements with a given value.
 * @param size  The initial size of the ArrayList.
 * @param value The value used to initialize the elements.
 * @modifies Initializes an ArrayList with 'size' elements, all set to 'value'.
 * @return N/A
 */
template<typename T>
ArrayList<T>::ArrayList(const uint32_t &size, const T &value)
        : mArray(new T[size]),
          mSize(size),
          mCapacity(size)
        {std::fill(mArray.get(), mArray.get() + mSize, value);}

/**
 * Copy Constructor: Creates a copy of an existing ArrayList.
 * @param src The ArrayList to be copied.
 * @modifies Initializes an ArrayList as a copy of 'src'.
 * @return N/A
 */
template<typename T>
ArrayList<T>::ArrayList(const ArrayList<T> &src)
    : mArray(new T[src.mCapacity]),
      mSize(src.mSize),
      mCapacity(src.mCapacity)
    {std::copy(src.mArray.get(), src.mArray.get() + src.mSize, mArray.get());}

/**
 * Move Constructor: Creates an ArrayList by moving the contents from another ArrayList.
 * @param src The ArrayList to be moved.
 * @modifies Initializes an ArrayList by moving the contents from 'src'.
 * @return N/A
 */
template<typename T>
ArrayList<T>::ArrayList(ArrayList<T> &&src) noexcept
    : mArray(src.mArray.release()),
      mSize(src.mSize),
      mCapacity(src.mCapacity)
    {src.mSize = src.mCapacity = 0;}

/**
 * Copy Assignment Operator: Assigns the contents of another ArrayList to this ArrayList.
 * @param src The ArrayList to be copied.
 * @modifies Copies the contents of 'src' to this ArrayList.
 * @return A reference to this ArrayList.
 */
template<typename T>
ArrayList<T> &ArrayList<T>::operator=(const ArrayList<T> &src) {
    if (this != &src) {
        ArrayList<T>(src).swap(*this);
    }
    return *this;
}

/**
 * Move Assignment Operator: Assigns the contents of another ArrayList to this ArrayList by moving.
 * @param src The ArrayList to be moved.
 * @modifies Moves the contents of 'src' to this ArrayList.
 * @return A reference to this ArrayList.
 */
template<typename T>
ArrayList<T> &ArrayList<T>::operator=(ArrayList<T> &&src) noexcept {
    if (this != &src) {
        this->swap(src);
        src.clear();
    }
    return *this;
}

/**
 * Adds an element to the end of the ArrayList.
 * @param value The value to be added to the ArrayList.
 * @modifies Adds 'value' to the end of the ArrayList.
 * @return A reference to the capacity of the ArrayList.
 */
template<typename T>
const uint32_t &ArrayList<T>::add(const T &value) {return add(mSize, value);}

/**
 * Inserts an element at a specific index in the ArrayList.
 * @param index The index at which to insert the element.
 * @param value The value to be inserted.
 * @modifies Inserts 'value' at 'index' in the ArrayList, shifting elements if necessary.
 * @return A reference to the capacity of the ArrayList.
 */
template<typename T>
const uint32_t &ArrayList<T>::add(const uint32_t &index, const T &value) {
    if(!check_range(index)) {
        resize();
        std::fill_n(mArray.get() + mSize, index - mSize, T());
    }

    if(index < mSize && mSize == mCapacity) {
        resize();
        std::move_backward(mArray.get() + index, mArray.get() + mSize, mArray.get() + mSize + 1);
    }

    ScopedArray<T> temp(new T[mCapacity]);
    std::copy(mArray.get(), mArray.get() + index, temp.get());
    temp[index] = value;
    std::copy(mArray.get() + index, mArray.get() + mSize, temp.get() + index + 1);

    mArray.swap(temp);
    ++mSize;

    return mCapacity;
}

/**
 * Resizes the internal array to accommodate more elements.
 * @param N/A
 * @modifies Resizes the internal array to double its current capacity.
 * @return N/A
 */
template<typename T>
void ArrayList<T>::resize() {
    uint32_t newCapacity = (mCapacity == 0) ? 1 : mCapacity * 2;
    ScopedArray<T> newArray(new T[newCapacity]);
    std::move(mArray.get(), mArray.get() + mSize, newArray.get());
    mArray.swap(newArray);
    std::swap(mCapacity, newCapacity);
}

/**
 * Clears the ArrayList, releasing memory and resetting its size and capacity.
 * @param N/A
 * @modifies Deallocates memory and resets the size and capacity of the ArrayList.
 * @return N/A
 */
template<typename T>
void ArrayList<T>::clear() {
    mArray.reset();
    mSize = mCapacity = 0;
}

/**
 * Retrieves the element at a specific index in the ArrayList.
 * @param index The index of the element to retrieve.
 * @modifies N/A
 * @throws std::out_of_range if the index is out of bounds.
 * @return A constant reference to the element at the specified index.
 */
template<typename T>
const T& ArrayList<T>::get(const uint32_t &index) const {
    if (!check_range(index))
        throw out_of_range(index);

    return mArray[index];
}

/**
 * Checks if an index is within the valid range of the ArrayList.
 * @param index The index to be checked.
 * @modifies N/A
 * @return 'true' if the index is within the valid range, 'false' otherwise.
 */
template<typename T>
bool ArrayList<T>::check_range(uint32_t index) const {return index < mCapacity;}

/**
 * Retrieves a reference to the element at a specific index in the ArrayList.
 * @param index The index of the element to retrieve.
 * @modifies N/A
 * @throws std::out_of_range if the index is out of bounds.
 * @return A reference to the element at the specified index, allowing modification.
 */
template<typename T>
T& ArrayList<T>::get(const uint32_t &index) {
    if (!check_range(index))
        throw out_of_range(index);

    return mArray[index];
}

/**
 * Accesses and returns a reference to the element at a specific index in the ArrayList.
 * @param index The index of the element to access.
 * @modifies N/A
 * @return A reference to the element at the specified index, allowing modification.
 */
template<typename T>
T& ArrayList<T>::operator[](const uint32_t &index) {return mArray[index];}

/**
 * Accesses and returns a constant reference to the element at a specific index in the ArrayList.
 * @param index The index of the element to access.
 * @modifies N/A
 * @return A constant reference to the element at the specified index.
 */
template<typename T>
const T& ArrayList<T>::operator[](const uint32_t &index) const {return mArray[index];}

/**
 * Checks if the ArrayList is empty.
 * @param N/A
 * @modifies N/A
 * @return 'true' if the ArrayList is empty, 'false' otherwise.
 */
template<typename T>
bool ArrayList<T>::isEmpty() const {return mSize == 0;}

/**
 * Removes and returns the element at a specific index in the ArrayList.
 * @param index The index of the element to remove.
 * @modifies Removes the element at the specified index, shifting elements if necessary.
 * @throws std::out_of_range if the index is out of bounds.
 * @return The removed element.
 */
template<typename T>
T ArrayList<T>::remove(const uint32_t &index) {
    if (!check_range(index))
        throw out_of_range(index);

    ScopedArray<T> newArray(new T[mCapacity]);

    std::copy(mArray.get(), mArray.get() + mSize, newArray.get());
    T removeValue = newArray[index];

    std::copy(newArray.get() + index + 1, newArray.get() + mSize, newArray.get() + index);
    mArray.swap(newArray);
    --mSize;
    return removeValue;
}

/**
 * Sets the value of the element at a specific index in the ArrayList.
 * @param index The index of the element to set.
 * @param value The new value to set.
 * @modifies Sets the value of the element at the specified index.
 * @throws std::out_of_range if the index is out of bounds.
 * @return N/A
 */
template<typename T>
void ArrayList<T>::set(const uint32_t &index, const T &value)  {
    if (!check_range(index))
        throw out_of_range(index);

    mArray[index] = value;
}

/**
 * Returns the current size of the ArrayList.
 * @param N/A
 * @modifies N/A
 * @return The current size of the ArrayList.
 */
template<typename T>
uint32_t ArrayList<T>::size() const {return mSize;}

/**
 * Swaps the contents of two ArrayList objects, effectively exchanging their elements and capacity.
 * @param src The ArrayList to swap content with.
 * @modifies Exchanges the size, capacity, and elements between this and 'src'.
 * @return N/A
 */
template<typename T>
void ArrayList<T>::swap(ArrayList<T> &src) noexcept {
    std::swap(mSize, src.mSize);
    std::swap(mCapacity, src.mCapacity);
    mArray.swap(src.mArray);
}

