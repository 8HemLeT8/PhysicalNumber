#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
using namespace std;

long multby[9] = {1, 100, 1000, 1, 60, 3600, 1, 1000, 1000000};


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
/////////////////////////////////////////////////////////////////////////////////////////////////////////

PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber &pnum)
{
  if (this->type != pnum.type)
  {
    throw "NOT THE SAME TYPE";
  }
  
  int val = this->value * multby[this->unit] + pnum.value * multby[this->unit];
  char t = this->type;
  Unit unit = this->unit;

  PhysicalNumber pn = PhysicalNumber(val, unit);
  return pn;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber &pnum)
{
  if (this->type != pnum.type)
  {
    throw "NOT THE SAME TYPE";
  }

  int val = this->value * multby[this->unit] - pnum.value * multby[this->unit];
  char t = this->type;
  Unit unit = this->unit;

  PhysicalNumber pn = PhysicalNumber(val, unit);
  return pn;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

const PhysicalNumber PhysicalNumber::operator+() const
{
  return *this;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

const PhysicalNumber PhysicalNumber::operator-() const
{
  return PhysicalNumber(-(this->value), this->unit);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

const PhysicalNumber PhysicalNumber::operator++(int)
{
  int val = this->value;
  this->value = this->value + 1 * multby[this->unit];
  return PhysicalNumber(val, this->unit);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

PhysicalNumber &PhysicalNumber::operator++()
{
  int val = this->value + 1 * multby[this->unit];
  PhysicalNumber pn = PhysicalNumber(val, this->unit);
  return pn;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

const PhysicalNumber PhysicalNumber::operator--(int)
{
  int val = this->value;
  this->value = this->value - 1 * multby[this->unit];
  return PhysicalNumber(val, this->unit);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
PhysicalNumber &PhysicalNumber::operator--()
{
  int val = this->value - 1 * multby[this->unit];
  PhysicalNumber pn = PhysicalNumber(val, this->unit);
  return pn;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

PhysicalNumber &PhysicalNumber::operator+=(const PhysicalNumber &pnum)
{
  this->value = this->value + (pnum.value * multby[pnum.unit]);
  return (*this);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

PhysicalNumber &PhysicalNumber::operator-=(const PhysicalNumber &pnum)
{
  this->value = this->value - (pnum.value * multby[pnum.unit]);
  return (*this);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

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
/////////////////////////////////////////////////////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////

bool ariel::operator>(const PhysicalNumber &lhs, const PhysicalNumber &rhs)
{
  if (lhs.type != rhs.type)
  {
    throw "NOT THE SAME TYPE";
  }
  else if (lhs.value > rhs.value)
  {
    return true;
  }
  else
  {
    return false;
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
bool ariel::operator<(const PhysicalNumber &lhs, const PhysicalNumber &rhs)
{
  if (lhs.type != rhs.type)
  {
    throw "NOT THE SAME TYPE";
  }
  else if (lhs.value < rhs.value)
  {
    return true;
  }
  else
  {
    return false;
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

bool ariel::operator>=(const PhysicalNumber &lhs, const PhysicalNumber &rhs)
{
  if (lhs.type != rhs.type)
  {
    throw "NOT THE SAME TYPE";
  }
  else if (lhs.value >= rhs.value)
  {
    return true;
  }
  else
  {
    return false;
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
bool ariel::operator<=(const PhysicalNumber &lhs, const PhysicalNumber &rhs)
{
  if (lhs.type != rhs.type)
  {
    throw "NOT THE SAME TYPE";
  }
  else if (lhs.value <= rhs.value)
  {
    return true;
  }
  else
  {
    return false;
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
Unit getUnit(const string s){
  static map<string, Unit> string2unit{
       { "CM", ariel::CM }, 
       { "M", ariel::M },
       { "KM", ariel::KM }, 
       { "SEC", ariel::SEC },
       { "MIN", ariel::MIN },
       { "HOUR", ariel::HOUR }, 
       { "G", ariel::G },
       { "KG", ariel::KG },
       { "TON", ariel::TON },  
    
  };
  auto x = string2unit.find(s);
    if(x != end(string2unit)) {
        return x->second;
    }
    throw invalid_argument("s");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

istream &ariel::operator>>(istream &in, PhysicalNumber &pnum)
{
  string a ;
  in>>a;
  a = a.substr(0, a.length() - 1);
  stringstream ss(a);
  vector<string> result;

  while (ss.good())
  {
    string substr;
    getline(ss, substr, '[');
    result.push_back(substr);
  }
  double val = stoi(result[0]);
  transform(result[1].begin(), result[1].end(),result[1].begin(), ::toupper);

  
  const string unt = result[1];
  Unit u = getUnit(unt);

  pnum = PhysicalNumber(val,u);
  return in;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////
ostream &ariel::operator<<(ostream &out, const PhysicalNumber &pnum)
{
  switch (pnum.unit)
  {
  case Unit::CM:
    out << pnum.value << "[cm]";
    break;
  case Unit::M:
    out << pnum.value << "[m]";
    break;
  case Unit::KM:
    out << pnum.value << "[km]";
    break;
  case Unit::SEC:
    out << pnum.value << "[sec]";
    break;
  case Unit::MIN:
    out << pnum.value << "[min]";
    break;
  case Unit::HOUR:
    out << pnum.value << "[hour]";
    break;
  case Unit::G:
    out << pnum.value << "[g]";
    break;
  case Unit::KG:
    out << pnum.value << "[kg]";
    break;
  case Unit::TON:
    out << pnum.value << "[ton]";
    break;
  }
  return out;
}
