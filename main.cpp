#include <iostream>
#include "Dispatcher.h"
#include "avx/interface.h"
#include "cpu/interface.h"

// Helper Function to print the values
std::ostream &operator<<(std::ostream &cout, const array &a)
{
    auto data_ptr = a.storage.get();
    auto len = a.n;
    for (size_t i = 0; i < len; i++)
    {
        std::cout << data_ptr[i] << ",";
    }
    return cout;
}

int main()
{
    Dispatcher op_dispatcher = Dispatcher{};
    Dispatcher cpu_dispatcher = Dispatcher{};
    cpu_dispatcher.use_cpu = true;

    array x_arr{/*numel=*/12, /*fill_value=*/5};
    array y_arr{/*numel=*/12, /*fill_value=*/4};

    auto out_arr_avx = op_dispatcher.binary_dispatch(avx2::mul, cpu::mul)(x_arr, y_arr);
    auto out_arr_cpu = cpu_dispatcher.binary_dispatch(avx2::mul, cpu::mul)(x_arr, y_arr);

    std::cout << (out_arr_cpu == out_arr_avx) << "\n";
}
