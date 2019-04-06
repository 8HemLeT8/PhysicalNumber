#pragma once
#include <string>
#include "Unit.h"
using std::string, ariel::Unit, std::ostream, std::istream;

namespace ariel
{
class PhysicalNumber
{
private:
  double value;
  char type;
  Unit unit;

public:
  PhysicalNumber(double value, Unit unit);
  /*** Arithmetic Operators ***/
  // +
  PhysicalNumber operator+(const PhysicalNumber &pnum);
  // -
  PhysicalNumber operator-(const PhysicalNumber &pnum);
  /*** Unary Operators ***/
  // unary +
  const PhysicalNumber operator+() const;
  // unary -
  const PhysicalNumber operator-() const;
  /*** Post/Pre Operators ***/
  // post ++
  const PhysicalNumber operator++(int);
  // post --
  const PhysicalNumber operator--(int);
  // ++ pre
  PhysicalNumber &operator++();
  // -- pre
  PhysicalNumber &operator--();
  /** Assignment Operators ***/
  // +=
  PhysicalNumber &operator+=(const PhysicalNumber &pnum);
  // -=
  PhysicalNumber &operator-=(const PhysicalNumber &pnum);
  /*** Relational operators ***/
  // ==
  friend bool operator==(const PhysicalNumber &lhs, const PhysicalNumber &rhs);
  // !=
  friend bool operator!=(const PhysicalNumber &lhs, const PhysicalNumber &rhs);
  // <
  friend bool operator>(const PhysicalNumber &lhs, const PhysicalNumber &rhs);
  // >
  friend bool operator<(const PhysicalNumber &lhs, const PhysicalNumber &rhs);
  // >=
  friend bool operator>=(const PhysicalNumber &lhs, const PhysicalNumber &rhs);
  // <=
  friend bool operator<=(const PhysicalNumber &lhs, const PhysicalNumber &rhs);
  /*** Stream Operators ***/
  // <<
  friend ostream &operator<<(ostream &out, const PhysicalNumber &pnum);
  // >>
  friend istream &operator>>(istream &in, PhysicalNumber &pnum);
};
} // namespace ariel