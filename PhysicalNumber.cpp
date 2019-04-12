#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
using namespace std;
//                cm, m,   km   s  min hour  g  kg    ton
long multby[9] = {1, 100, 100000, 1, 60, 3600, 1, 1000, 1000000};


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

const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber &pnum) const
{
  if (this->type != pnum.type)
  {
    throw "NOT THE SAME TYPE";
  }
  
  double val = (this->value * multby[this->unit]) + (pnum.value * multby[pnum.unit]);
  
  Unit unitA = this->unit;
  val=val/multby[unitA];
  return PhysicalNumber(val, unitA);
  
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

const PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber &pnum) const
{
  if (this->type != pnum.type)
  {
    throw "NOT THE SAME TYPE";
  }

  double val = this->value * multby[this->unit] - pnum.value * multby[pnum.unit];
  Unit unitA = this->unit;
  val=val/multby[unitA];

  return PhysicalNumber(val, unit);
  
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
  double val = this->value;
  this->value = this->value*multby[this->unit] + 1 * multby[this->unit];
  this->value /= multby[this->unit];
  return PhysicalNumber(val, this->unit);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

PhysicalNumber &PhysicalNumber::operator++()
{
  this->value = this->value*multby[this->unit] + 1 * multby[this->unit];
  this->value /= multby[this->unit];
  return *this;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

const PhysicalNumber PhysicalNumber::operator--(int)
{
  double val = this->value;
  this->value = this->value*multby[this->unit] - 1 * multby[this->unit];
  this->value /= multby[this->unit];
  return PhysicalNumber(val, this->unit);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
PhysicalNumber &PhysicalNumber::operator--()
{
  this->value = this->value*multby[this->unit] - 1 * multby[this->unit];
  this->value /= multby[this->unit];
  return *this;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

PhysicalNumber &PhysicalNumber::operator+=(const PhysicalNumber &pnum)
{
  if (this->type != pnum.type)
  {
    throw "NOT THE SAME TYPE";
  }
  this->value = this->value * multby[this->unit] + (pnum.value * multby[pnum.unit]);
  this->value /= multby[this->unit];
  return (*this);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

PhysicalNumber &PhysicalNumber::operator-=(const PhysicalNumber &pnum)
{
  if (this->type != pnum.type)
  {
  throw "NOT THE SAME TYPE";
  }
  this->value = this->value * multby[this->unit] - (pnum.value * multby[pnum.unit]);
  this->value /= multby[this->unit];

  return (*this);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

bool ariel::operator==(const PhysicalNumber &lhs, const PhysicalNumber &rhs)
{
  if (lhs.type != rhs.type)
  {
    throw "NOT THE SAME TYPE";
  }
  else if (lhs.value*multby[lhs.unit] == rhs.value*multby[rhs.unit])
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
  else if (lhs.value*multby[lhs.unit] != rhs.value*multby[rhs.unit])
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
  else if (lhs.value*multby[lhs.unit] > rhs.value*multby[rhs.unit])
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
  else if (lhs.value*multby[lhs.unit] < rhs.value*multby[rhs.unit])
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
    throw invalid_argument(s);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

istream &ariel::operator>>(istream &in, PhysicalNumber &pnum)
{
  string a ;
  in>>a;
  if(a.find("]")==-1||a.find("[")==-1||a.find("[]")){
    return in;
  }
  a = a.substr(0, a.length() - 1);
  stringstream ss(a);
  vector<string> result;

  while (ss.good())
  {
    string substr;
    getline(ss, substr, '[');
    result.push_back(substr);
  }
  double val = stod(result[0]);
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
