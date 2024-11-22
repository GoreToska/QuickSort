#pragma once

#include <cstdlib>
#include <iostream>
#include "array.h"

template <typename T>
array<T>::array()
{
    size_ = 0;
    capacity_ = min_capacity_;
    data_ptr_ = static_cast<T*>(malloc(capacity_ * sizeof(T)));
}

template <typename T>
array<T>::array(int capacity)
{
    size_ = 0;
    capacity_ = capacity;
    data_ptr_ = static_cast<T*>(malloc(capacity_ * sizeof(T)));
}

template <typename T>
array<T>::array(const array& other)
{
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ptr_ = static_cast<T*>(malloc(capacity_ * sizeof(T)));

    for (size_t i = 0; i < size_; ++i)
    {
        new(data_ptr_ + i) T(other.data_ptr_[i]);
    }
}

template <typename T>
array<T>::array(array&& other) noexcept // move constructor
{
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ptr_ = other.data_ptr_;
    other.size_ = 0;
    other.capacity_ = 0;
    other.data_ptr_ = nullptr;
}

template <typename T>
array<T>::~array()
{
    for (size_t i = 0; i < size_; ++i)
    {
        (data_ptr_ + i)->~T();
    }

    free(data_ptr_);
}

template <typename T>
int array<T>::insert(const T& value)
{
    capacity_check();
    new(data_ptr_ + size_) T(value);

    return size_++;
}

template <typename T>
int array<T>::insert(int index, const T& value)
{
    insert(value);

    for (size_t i = index; i < size_; ++i)
    {
        std::swap(data_ptr_[i], data_ptr_[size_ - 1]);
    }

    return index;
}

template <typename T>
void array<T>::remove(int index)
{
    for (size_t i = index; i < size_ - 1; ++i)
    {
        data_ptr_[i] = std::move(data_ptr_[i + 1]);
    }

    data_ptr_[size_ - 1].~T();
    --size_;
}

template <typename T>
const T& array<T>::operator[](int index) const
{
    return data_ptr_[index];
}

template <typename T>
T& array<T>::operator[](int index)
{
    return data_ptr_[index];
}

template <typename T>
array<T>& array<T>::operator=(const array<T>& other)
{
    if (this != &other)
        return *this;

    array<T> temp(other);
    std::swap(capacity_, temp.capacity_);
    std::swap(size_, other.size_);
    std::swap(data_ptr_, other.data_ptr_);

    return *this;
}

template <typename T>
array<T>& array<T>::operator=(array<T>&& other) noexcept
{
    array<T> temp(std::move(other));
    std::swap(capacity_, temp.capacity_);
    std::swap(size_, other.size_);
    std::swap(data_ptr_, other.data_ptr_);

    return *this;
}

template <typename T>
int array<T>::size() const
{
    return size_;
}

template <typename T>
T* array<T>::begin() const
{
    return &data_ptr_[0];
}

template <typename T>
T* array<T>::end() const
{
    return &data_ptr_[size_];
}

template <typename T>
array<T>::const_iterator::const_iterator(const array<T>& array, bool is_reverse): array_(array)
{
    is_reverse_ = is_reverse;
    is_reverse_ ? i_ = array_.size_ - 1 : i_ = 0;
}

template <typename T>
const T& array<T>::const_iterator::get() const
{
    return array_[i_];
}

template <typename T>
void array<T>::const_iterator::set(const T& value)
{
    array_[i_] = value;
}

template <typename T>
void array<T>::const_iterator::next()
{
    is_reverse_ ? --i_ : ++i_;
}

template <typename T>
bool array<T>::const_iterator::has_next() const
{
    return is_reverse_ ? i_ >= 0 : i_ < array_.size_;
}

template <typename T>
const T& array<T>::const_iterator::operator*() const
{
    return array_[i_];
}

template <typename T>
typename array<T>::const_iterator& array<T>::const_iterator::operator++()
{
    next();
    return *this;
}

template <typename T>
typename array<T>::const_iterator array<T>::const_iterator::operator++(T)
{
    next();
    return *this;
}

template <typename T>
array<T>::iterator::iterator(array<T>& array, bool is_reverse) : array_(array)
{
    is_reverse_ = is_reverse;
    is_reverse_ ? i_ = array_.size_ - 1 : i_ = 0;
}

template <typename T>
const T& array<T>::iterator::get() const
{
    return array_[i_];
}

template <typename T>
void array<T>::iterator::set(const T& value)
{
    array_[i_] = value;
}

template <typename T>
void array<T>::iterator::next()
{
    is_reverse_ ? --i_ : ++i_;
}

template <typename T>
bool array<T>::iterator::has_next() const
{
    return is_reverse_ ? i_ >= 0 : i_ < array_.size_;
}

template <typename T>
T& array<T>::iterator::operator*()
{
    return array_[i_];
}

template <typename T>
typename array<T>::iterator& array<T>::iterator::operator++()
{
    next();
    return *this;
}

template <typename T>
typename array<T>::iterator array<T>::iterator::operator++(T)
{
    next();
    return *this;
}

template <typename T>
typename array<T>::iterator array<T>::get_iterator()
{
    iterator standard_iterator(*this, false);
    return standard_iterator;
}

template <typename T>
typename array<T>::const_iterator array<T>::get_iterator() const
{
    const_iterator const_iterator(*this, false);
    return const_iterator;
}

template <typename T>
typename array<T>::iterator array<T>::get_reverse_iterator()
{
    iterator reverse_iterator(*this, true);
    return reverse_iterator;
}

template <typename T>
typename array<T>::const_iterator array<T>::get_reverse_iterator() const
{
    const_iterator const_iterator(*this, true);
    return const_iterator;
}

template <typename T>
void array<T>::capacity_check()
{
    if (size_ < capacity_)
        return;

    capacity_ *= size_change_exponent;
    T* temp = static_cast<T*>(malloc(capacity_ * sizeof(T)));
    for (size_t i = 0; i < size_; ++i)
    {
        new(temp + i)T(std::move(data_ptr_[i]));
        (data_ptr_ + i)->~T();
    }

    data_ptr_ = temp;
    temp = nullptr;
}
