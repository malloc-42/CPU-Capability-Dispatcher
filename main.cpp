#include <array>
#include "Dispatcher.h"
#include "avx/interface.h"
#include "cpu/interface.h"

int main()
{
    Dispatcher op_dispatcher = Dispatcher{};
    Dispatcher cpu_dispatcher = Dispatcher{};
    cpu_dispatcher.use_cpu = true;

    std::array<double, 4> x = {4.0, 3.0, 2.0, 1.0};
    std::array<double, 4> y = {3.0, 0.0, 1.0, 0.0};

    op_dispatcher.binary_dispatch(avx2::mul, cpu::mul)(x, y);
    cpu_dispatcher.binary_dispatch(avx2::mul, cpu::mul)(x, y);
}
