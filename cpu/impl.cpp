#include "interface.h"

namespace cpu
{

    array mul(const array &x_arr, const array &y_arr)
    {
        if (x_arr.n != y_arr.n)
        {
            throw std::runtime_error("Length of arrays should match");
        }

        auto len = x_arr.n;
        auto result = array(len); // empty result array
        auto result_ptr = result.storage.get();
        for (size_t sz = 0; sz < x_arr.n; ++sz)
        {
            auto x_ptr = x_arr.storage.get();
            auto y_ptr = y_arr.storage.get();
            result_ptr[sz] = x_ptr[sz] * y_ptr[sz];
        }
        return result;
    }

}
