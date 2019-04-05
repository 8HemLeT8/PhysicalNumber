#pragma once
#include <string>
#include "Unit.h"
using std::string, std::Unit, std::ostream, std::istream;

namespace ariel
{
class PhysicalNumber
{
  private:
    double value;
    string type;
    int unit;

  public:
    PhysicalNumber(double value, int unit);

    friend PhysicalNumber operator+(const PhysicalNumber &b);
    friend PhysicalNumber operator-(const PhysicalNumber &b);
    PhysicalNumber &operator+=(const PhysicalNumber &other);
    PhysicalNumber &operator-=(const PhysicalNumber &b);
    friend PhysicalNumber operator++(const PhysicalNumber &b);
    friend PhysicalNumber operator--(const PhysicalNumber &b);
    friend istream &operator>>(istream &in, PhysicalNumber &vec);
    friend ostream &operator<<(ostream &out, const PhysicalNumber &vec); // output
};
} // namespace ariel