#include "PhysicalNumber.h"

class PhysicalNumber
{
private:
  double value;
  string type;
  int unit;

public:
  PhysicalNumber(double value, int unit)
  {
    this->value = value;
    this->unit = unit;
    if (unit < 3)
    {
      type = "length";
    }
    else if (unit < 6 && unit > 2)
    {
      type = "time";
    }
    else if (unit > 5)
    {
      type = "weight";
    }
  }

  friend PhysicalNumber operator+(const PhysicalNumber &b)
  {
    if (this->type != b.type)
    {
      __throw_exception_again;
    }

    int val = this->value * multby[this->unit] + b.value * multby[this->unit];
    string t = this->type;
    if (MAX(this->unit, b->unit) < 8)
    {
      if (val > multby[this->unit + 1] && (val < 1000))
      {
        int unit = this->unit + 1;
      }
      else
      {
        int unit = this->unit;
      }
      PhysicalNumber pn = new (val, Unit);
      return pn;
    }
  }
  friend PhysicalNumber operator-(const PhysicalNumber &b){

  }
    PhysicalNumber &operator+=(const PhysicalNumber &other){

    }
    PhysicalNumber &operator-=(const PhysicalNumber &b){

    }
    friend PhysicalNumber operator++(const PhysicalNumber &b){

    }
    friend PhysicalNumber operator--(const PhysicalNumber &b){

    }
    friend istream &operator>>(istream &in, PhysicalNumber &vec){

    }
    friend ostream &operator<<(ostream &out, const PhysicalNumber &vec){
      
    }
}