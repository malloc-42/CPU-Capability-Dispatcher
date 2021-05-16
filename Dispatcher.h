#include <cpuinfo.h>
#include "cpu/interface.h"
#include "avx/avx_interface.h"

struct Dispatcher
{
    
    using Arr = std::array<double, 4>;
    Dispatcher(){
        cpuinfo_initialize();
    }

    template <typename AVXFunc, typename CPUFunc>
    auto binary_dispatch(AVXFunc avx_op, CPUFunc cpu_op, Arr x, Arr y)
    {
        if (cpuinfo_has_x86_avx())
        {
            return avx_op(x, y);
        }
        return cpu_op(x, y);
    }

    Arr mul(Arr x, Arr y){
        return binary_dispatch(avx2::mul, cpu::mul, x, y);
    }
};