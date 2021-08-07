#include "interface.h"
#include <x86intrin.h>
#include <exception>

namespace avx2
{

    array mul(const array &x_arr, const array &y_arr)
    {
        if (x_arr.n != y_arr.n)
        {
            throw std::runtime_error("Length of arrays should match");
        }

        constexpr size_t vec_size = 4;
        auto len = x_arr.n;
        auto result = array(len); // empty result array
        auto result_ptr = result.storage.get();
        auto simd_iter = (len / vec_size);
        for (size_t i = 0; i < simd_iter; ++i)
        {
            auto x_ptr = x_arr.storage.get();
            auto y_ptr = y_arr.storage.get();
            auto offset = i * vec_size;
            auto x_vec = __m256d{x_ptr[offset + 0], x_ptr[offset + 1], x_ptr[offset + 2], x_ptr[offset + 3]};
            auto y_vec = __m256d{y_ptr[offset + 0], y_ptr[offset + 1], y_ptr[offset + 2], y_ptr[offset + 3]};
            auto mul = _mm256_mul_pd(x_vec, y_vec);
            result_ptr[offset + 0] = mul[0];
            result_ptr[offset + 1] = mul[1];
            result_ptr[offset + 2] = mul[2];
            result_ptr[offset + 3] = mul[3];
        }

        auto offset = simd_iter * vec_size;
        for (size_t i = 0; i < len % vec_size; i++)
        {
            auto x_ptr = x_arr.storage.get();
            auto y_ptr = y_arr.storage.get();
            
            result_ptr[offset + i] = x_ptr[offset + i] * y_ptr[offset + i];
        }

        return result;
    }

}
