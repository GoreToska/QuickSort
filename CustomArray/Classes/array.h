#pragma once

template <typename T>
class array final
{
public:
    explicit array();
    explicit array(int capacity);
    array(const array& other);
    array(array&& other) noexcept;
    ~array();
    array<T>& operator=(const array<T>& other);
    array<T>& operator=(array<T>&& other) noexcept;

    int insert(const T& value);
    int insert(int index, const T& value);
    void remove(int index);
    int size() const;

    const T& operator[](int index) const;
    T& operator[](int index);

    class const_iterator
    {
    public:
        const_iterator(const array<T>& array, bool is_reverse);
        const T& get() const;
        void set(const T& value);
        void next();
        bool has_next() const;

        const T& operator *() const;
        const_iterator& operator ++();
        const_iterator operator ++(T);

    private:
        const array<T>& array_;
        bool is_reverse_ = false;
        int i_ = 0;
    };

    class iterator
    {
    public:
        iterator(array<T>& array, bool is_reverse);
        const T& get() const;
        void set(const T& value);
        void next();
        bool has_next() const;

        T& operator *();
        iterator& operator ++();
        iterator operator ++(T);

        friend array;

    private:
        array<T>& array_;
        bool is_reverse_ = false;
        int i_ = 0;
    };

    T* begin() const;
    T* end() const;
    
    iterator get_iterator();
    const_iterator get_iterator() const;
    iterator get_reverse_iterator();
    const_iterator get_reverse_iterator() const;

private:
    size_t size_;
    size_t capacity_;
    T* data_ptr_;

    const int min_capacity_ = 16;
    const int size_change_exponent = 2;

    void capacity_check();
};
