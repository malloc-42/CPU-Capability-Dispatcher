#include <iostream>
#include <cpuinfo.h>
#include "array_interface.h"

struct Dispatcher
{
    bool use_cpu = false;

    Dispatcher()
    {
        cpuinfo_initialize();
    }

    template <typename AVXFunc, typename CPUFunc>
    auto binary_dispatch(AVXFunc avx_op, CPUFunc cpu_op)
    {
        return [=](const array& x, const array& y) -> array
        {
            if (cpuinfo_has_x86_avx() && !use_cpu)
            {
                std::cout << "AVX\n";
                return avx_op(x, y);
            }
            std::cout << "CPU\n";
            return cpu_op(x, y);
        };
    }
};
