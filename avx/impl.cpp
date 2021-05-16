#include "interface.h"
#include <x86intrin.h>

namespace avx2{

std::array<double, 4> mul(const std::array<double, 4> &x, const std::array<double, 4> &y)
{
    std::cout << "AVX IMPL\n";
    auto x_vec = __m256d{x[0], x[1], x[2], x[3]};
    auto y_vec = __m256d{y[0], y[1], y[2], y[3]};
    auto mul = _mm256_mul_pd(x_vec, y_vec);

    return {mul[0], mul[1], mul[2], mul[3]};
}

}
