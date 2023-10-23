#include <sstream>
#include "Rational.h"

Rational::Rational() : num_(0), denom_(1) {}

Rational::Rational(int numerator, int denominator) {
  if (denominator == 0) {
    std::stringstream ss;
    ss << "Argument must not be zero";
    throw std::invalid_argument(ss.str());
  }
  num_ = numerator;
  denom_ = denominator;
}
Rational::~Rational() = default;
int Rational::Numerator() const {
  return num_;
}
int Rational::Denominator() const {
  return denom_;
}
Rational operator+(const Rational &a, const Rational &b) {
  if (a.denom_ == b.denom_) {
    return Rational(a.num_ + b.num_, a.denom_);
  } else {
    return Rational(a.num_ * b.denom_ + b.num_ * a.denom_, a.denom_ * b.denom_);
  }
}
Rational operator*(const Rational &a, const Rational &b) {
  return Rational(a.num_ * b.num_, a.denom_ * b.denom_);
}
Rational operator/(const Rational &a, const Rational &b) {
  return Rational(a.num_ * b.denom_, b.num_ * a.denom_);
}
Rational operator-(const Rational &a, const Rational &b) {
  if (a.denom_ == b.denom_) {
    return Rational(a.num_ - b.num_, a.denom_);
  } else {
    return Rational(a.num_ * b.denom_ - b.num_ * a.denom_, a.denom_ * b.denom_);
  }
}
bool operator==(const Rational &a, const Rational &b) {
  return (a.num_ * b.denom_ == b.num_ * a.denom_);
}
std::ostream &operator<<(std::ostream &out, const Rational &a) {
  out << a.num_ << "/" << a.denom_;
  return out;
}
std::istream &operator>>(std::istream &in, Rational &a) {
  char slash;
  in >> a.num_ >> slash >> a.denom_;
  return in;
}

