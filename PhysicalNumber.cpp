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
    throw "NOT THE SAME TYPE";
  }

  int val = this->value * multby[this->unit] + b.value * multby[this->unit];
  char t = this->type;
  Unit unit = this->unit;

  PhysicalNumber pn = PhysicalNumber(val, unit);
  return pn;
}
const PhysicalNumber PhysicalNumber::operator+() const
{
  return *this;
}
const PhysicalNumber PhysicalNumber::operator-() const
{
  return PhysicalNumber(-(this->value), this->unit);
}

//x++
const PhysicalNumber PhysicalNumber::operator++(int)
{
  int val = this->value;
  this->value = this->value + 1;
  return PhysicalNumber(val, this->unit);
}

//++x
PhysicalNumber &PhysicalNumber::operator++()
{
  int val = this->value + 1;
  PhysicalNumber pn = PhysicalNumber(val, this->unit);
  return pn;
}

PhysicalNumber &PhysicalNumber::operator+=(const PhysicalNumber &pnum)
{
  this->value = this->value + pnum.value;
  return (*this);
}

bool ariel::operator==(const PhysicalNumber &lhs, const PhysicalNumber &rhs)
{
  if (lhs.type != rhs.type)
  {
    throw "NOT THE SAME TYPE";
  }
  else if (lhs.value == rhs.value)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool ariel::operator!=(const PhysicalNumber &lhs, const PhysicalNumber &rhs)
{
  if (lhs.type != rhs.type)
  {
    throw "NOT THE SAME TYPE";
  }
  else if (lhs.value != rhs.value)
  {
    return true;
  }
  else
  {
    return false;
  }
}

ostream &ariel::operator<<(ostream &out, const PhysicalNumber &pnum)
{
  switch (pnum.unit)
  {
  case Unit::CM:
    out << pnum.value << "[cm]" << endl;
    break;
  case Unit::M:
    out << pnum.value << "[m]" << endl;
    break;
  case Unit::KM:
    out << pnum.value << "[km]" << endl;
    break;
  case Unit::SEC:
    out << pnum.value << "[sec]" << endl;
    break;
  case Unit::MIN:
    out << pnum.value << "[min]" << endl;
    break;
  case Unit::HOUR:
    out << pnum.value << "[hour]" << endl;
    break;
  case Unit::G:
    out << pnum.value << "[g]" << endl;
    break;
  case Unit::KG:
    out << pnum.value << "[kg]" << endl;
    break;
  case Unit::TON:
    out << pnum.value << "[ton]" << endl;
    break;
  }
  return out;
}
