#include <iostream>
#include <cstdio>

namespace ariel
{

enum Unit
{
    CM,
    M,
    KM,
    SEC,
    MIN,
    HOUR,
    G,
    KG,
    TON
};

long multby[] = {1, 100, 1000, 1, 60, 3600, 1, 1000, 1000000};

} // namespace ariel