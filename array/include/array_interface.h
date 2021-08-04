#pragma once

#include <memory>
#include <exception>

struct array
{
    using len_t = size_t;
    using T = double;
    std::shared_ptr<T[]> storage;
    const len_t n;
    array(size_t n, T val) : n(n) {
        auto ptr = new T[n];

        for (int i = 0; i < n; ++i) {
            *(ptr + i) = val;
        }
        storage = std::shared_ptr<T[]>(ptr);
    }

    array(size_t n) : n(n) {
        storage = std::shared_ptr<T[]>(new T[n]);
    }

    array(std::shared_ptr<T[]> storage, size_t n) : storage(storage), n(n) {}

    bool operator==(const array &rhs)
    {
        if (rhs.n != n)
        {
            return false;
        }

        auto rhs_ptr = rhs.storage.get();
        auto ptr = storage.get();
        for (size_t i = 0; i < n; ++i)
        {
            if (rhs_ptr[i] != ptr[i])
            {
                return false;
            }
        }
        return true;
    }
};
