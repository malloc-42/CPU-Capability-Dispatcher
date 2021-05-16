#include "interface.h"

namespace cpu
{

    std::array<double, 4> mul(std::array<double, 4> x, std::array<double, 4> y)
    {
        std::array<double, 4> result;
        for (size_t sz = 0; sz < x.size(); ++sz)
        {
            result[sz] = x[sz] * y[sz];
        }
        std::cout << "NORMAL IMPL"
                  << "\n";
        return result;
    }

}
