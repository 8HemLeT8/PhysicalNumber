#include "PhysicalNumber.h"

using ariel::PhysicalNumber, ariel::Unit;
using namespace std;

ariel::PhysicalNumber::PhysicalNumber(double value, Unit unit)
{
  this->value = value;
  this->unit = unit;
  if (unit < Unit::SEC)
  {
    type = 'l';
  }
  else if (unit < Unit::G && unit > Unit::KM)
  {
    type = 't';
  }
  else if (unit > Unit::HOUR)
  {
    type = 'w';
  }
}

PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber &b)
{
  if (this->type != b.type)
  {
    __throw_exception_again;
  }

  int val = this->value * multby[this->unit] + b.value * multby[this->unit];
  char t = this->type;
  Unit unit = this->unit;

  PhysicalNumber pn = PhysicalNumber(val, unit);
  return pn;
}


