## Description

Dispatch to vectorized function based on the capability available at runtime.

**AVX2** Instruction Set was introduced by Intel in 2014, which provided significant performance boost over Intel's AVX and SIMD instruction sets. According to the <a href="https://www.intel.com/content/dam/www/public/us/en/documents/white-papers/performance-xeon-e5-v3-advanced-vector-extensions-paper.pdf">official release</a>, AVX2 provides following benefits over other existing instruction sets during that period:

1. Doubling the number of FLOPS per clock cycle.
2. 256-bit integer instructions.
3. Floating-point fused multiply-add instructions and gather operations.

This Dispatcher aims to dispatch the operation to the capability depending on your CPU during the runtime itself. If AVX2 is supported and demanded (`use_cpu` is not set to `true`), then the operator will be dispatched to AVX2 instruction set (see [supported operators](#supported-operators) section).

## Build Instructions

**Update the submodule**: `git submodule update --init`

**Build the source code**:

```
$ mkdir build && cd build
$ cmake ..
$ make
$ ./test_bin  # Run tests
```

## Usage

As of Release 0.0.1, the Dispatcher supports arrays of size 4 and [these operators](#supported-operators) for both AVX2 and SIMT instruction sets. Here is a sample code to start with: (also check `main.cpp` for complete template)

Let's start with the necessary header files.

```cpp
#include <array>  // for using std::array
#include "Dispatcher.h"  // for accessing Dispatcher struct
#include "avx/interface.h"  // for accessing avx2::<op>
#include "cpu/interface.h"  // for accessing cpu::<op>
```

Initialize 2 arrays `x, y` using `std::array<double, 4> x = {1.0, 2.0, 3.0, 4.0}` and `std::array<double, 4> y = {4.0, 3.0, 2.0, 1.0}` and initialize the Dispatcher.

```cpp
Dispatcher op_dispatcher = Dispatcher{};
Dispatcher cpu_dispatcher = Dispatcher{};
```

In order to allow `cpu_dispatcher` to use CPU, you need to set `use_cpu` flag (default is `false`): `cpu_dispatcher.use_cpu = true`. Now since the arrays and dispatchers are initialized, go ahead and dispatch the op (`mul` for example, see [supported operators section](#supported-operators)):

```cpp
op_dispatcher.binary_dispatch(avx2::mul, cpu::mul)(x, y);
cpu_dispatcher.binary_dispatch(avx2::mul, cpu::mul)(x, y);
```

If the dispatcher found AVX2 capability available, the `op_dispatcher.binary_dispatch` call should print `AVX IMPL` while `cpu_dispatcher.binary_dispatch` should print `NORMAL IMPL`.

## Supported Operators

As of Release 0.0.1, the Dispatcher supports following ops:

* `mul`
