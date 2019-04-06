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
const PhysicalNumber PhysicalNumber::operator+() const{
  return *this;
}
const PhysicalNumber PhysicalNumber::operator-() const{
  return PhysicalNumber(-(this->value),this->unit);
}

//x++
const PhysicalNumber PhysicalNumber::operator++(int)
{
  int val = this->value;
  this->value = this->value + 1;
  return PhysicalNumber(val,this->unit);

}

//++x
 PhysicalNumber& PhysicalNumber::operator++()
{
  int val = this->value + 1;
  PhysicalNumber pn =PhysicalNumber(val, this->unit);
  return pn;
}

  PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber &pnum){
    this->value=this->value+pnum.value;
    return (*this);
  }

  //friend bool operator==(const PhysicalNumber &lhs, const PhysicalNumber &rhs);


