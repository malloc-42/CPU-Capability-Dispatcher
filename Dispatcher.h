#include <cpuinfo.h>

struct Dispatcher
{

    using Arr = std::array<double, 4>;
    bool use_cpu = false;

    Dispatcher()
    {
        cpuinfo_initialize();
    }

    Dispatcher(bool use_cpu) : use_cpu(use_cpu)
    {
        cpuinfo_initialize();
    }

    template <typename AVXFunc, typename CPUFunc>
    auto binary_dispatch(AVXFunc avx_op, CPUFunc cpu_op)
    {
        return [=](Arr x, Arr y) -> Arr
        {
            if (cpuinfo_has_x86_avx() && !use_cpu)
            {
                return avx_op(x, y);
            }
            return cpu_op(x, y);
        };
    }
};
