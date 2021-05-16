#include <cpuinfo.h>
#include "cpu/interface.h"
#include "avx/avx_interface.h"
#include <array>

int main()
{
    cpuinfo_initialize();    

    std::array<double, 4> x = {4.0, 3.0, 2.0, 1.0};
    std::array<double, 4> y = {3.0, 0.0, 1.0, 0.0};

    if (cpuinfo_has_x86_avx()){
        avx2::mul_impl(x, y);
    } else {
        cpu::mul_impl(x, y);
    }
}
