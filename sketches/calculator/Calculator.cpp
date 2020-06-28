#include <assert.h>

namespace calculator
{
int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

double divide(int a, int b)
{
    assert(b != 0);
    return static_cast<double>(a) / static_cast<double>(b);
}
} // namespace calculator
