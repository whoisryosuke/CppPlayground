#pragma once

#pragma once
#include <iostream>

namespace RangeLoopsCustomTypes {
    // Custom Array type
    template <typename T, size_t const Size>
    class dummy_array
    {
        T data[Size] = {};

    public:
        T const& GetAt(size_t const index) const
        {
            if (index < Size) return data[index];
            throw std::out_of_range("index out of range");
        }

        void SetAt(size_t const index, T const& value)
        {
            if (index < Size) data[index] = value;
            else throw std::out_of_range("index out of range");
        }

        size_t GetSize() const { return Size; }
    };

    // We create a type for our iterator (aka range)
    template <typename T, typename C, size_t const Size>
    class dummy_array_iterator_type
    {
    public:
        dummy_array_iterator_type(C& collection, size_t const index) :
            index(index),
            collection(collection)
        {
        }

        bool operator!= (dummy_array_iterator_type const& other) const
        {
            return index != other.index;
        }

        T const& operator* () const
        {
            return collection.GetAt(index);
        }

        dummy_array_iterator_type& operator++ ()
        {
            ++index;
            return *this;
        }

        dummy_array_iterator_type operator++ (int)
        {
            auto temp = *this;
            ++* this;
            return temp;
        }

    private:
        size_t   index;
        C& collection;
    };

    // We also create a type for mutable (the default) and `const` versions of our iterator
    // Notice how these types use and override the type above
    template <typename T, size_t const Size>
    using dummy_array_iterator = dummy_array_iterator_type<T, dummy_array<T, Size>, Size>;

    template <typename T, size_t const Size>
    using dummy_array_const_iterator = dummy_array_iterator_type<T, dummy_array<T, Size> const, Size>;

    // The begin and end methods required for the range
    template <typename T, size_t const Size>
    inline dummy_array_iterator<T, Size> begin(dummy_array<T, Size>& collection)
    {
        return dummy_array_iterator<T, Size>(collection, 0);
    }

    template <typename T, size_t const Size>
    inline dummy_array_iterator<T, Size> end(dummy_array<T, Size>& collection)
    {
        return dummy_array_iterator<T, Size>(collection, collection.GetSize());
    }

    // `const` version
    template <typename T, size_t const Size>
    inline dummy_array_const_iterator<T, Size> begin(dummy_array<T, Size> const& collection)
    {
        return dummy_array_const_iterator<T, Size>(collection, 0);
    }

    template <typename T, size_t const Size>
    inline dummy_array_const_iterator<T, Size> end(dummy_array<T, Size> const& collection)
    {
        return dummy_array_const_iterator<T, Size>(collection, collection.GetSize());
    }

    /// <summary>
    /// This is an example of using the iterator in a `const` setting.
    /// Notice the `const&` before the `arr` name.
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <typeparam name="Size"></typeparam>
    /// <param name="arr"></param>
    template <typename T, const size_t Size>
    void print_dummy_array(dummy_array<T, Size> const& arr)
    {
        for (auto&& e : arr)
        {
            std::cout << e << '\n';
        }
    }

    void CustomTypeExample();
};