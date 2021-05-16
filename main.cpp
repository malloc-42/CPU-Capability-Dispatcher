#include <array>
#include "Dispatcher.h"

int main()
{
    Dispatcher dispatcher = Dispatcher{};

    std::array<double, 4> x = {4.0, 3.0, 2.0, 1.0};
    std::array<double, 4> y = {3.0, 0.0, 1.0, 0.0};

    dispatcher.mul(x, y);
}
