#include "rational.h"

using namespace std;
void Rational::reduce()
{
	//cout << "Rational: Reduce" << endl;

	if (denominator < 0) {
		denominator *= -1;
		numerator *= -1;
	}

	long long gcd = std::gcd(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
}

Rational::Rational(long long n, long long d) : numerator(n), denominator(d) 
{
	//cout << "Rational: Constructor " << endl;
	if (d == 0) throw std::invalid_argument("Denominator can't be zero");
	reduce();
}

Rational::Rational(double value)
{
	//cout << "Rational: Double To Rational Constructor" << endl;
	union {
		double d;
		uint64_t bits;
	} u;
	u.d = value;
	int sign = (u.bits >> 63) ? -1 : 1;
	int exponent = ((u.bits >> 52) & 0x7FF) - 1023;
	uint64_t mantissa = u.bits & 0xFFFFFFFFFFFFF;

	mantissa |= (1ULL << 52);
	
	long long num = sign * mantissa;
	long long den = (1LL << 52);

	if (exponent > 0) {
		num <<= exponent;
	}
	else {
		den <<= -exponent;
	}
	long long gcd = std::gcd(num, den);
	numerator = num / gcd;
	denominator = den / gcd;
}

double Rational::toDecimal()
{
	//cout << "Rational: Rational To Double" << endl;
	return (numerator+0.0) / denominator;
}

double Rational::toDecimal(Rational item)
{
	return item.toDecimal();
}

Rational Rational::operator+(const Rational& other) const
{
	//cout << "Rational: operator + rational" << endl;
	return Rational(this->numerator * other.denominator + other.numerator * this->denominator, this->denominator * other.denominator);
}

Rational Rational::operator-(const Rational& other) const
{
	//cout << "Rational: operator - rational" << endl;
	return Rational(this->numerator * other.denominator - other.numerator * this->denominator, this->denominator * other.denominator);
}

Rational Rational::operator*(const Rational& other) const
{
	//cout << "Rational: operator * rational" << endl;
	return Rational(this->numerator * other.numerator , this->denominator * other.denominator);
}

Rational Rational::operator/(const Rational& other) const
{
	//cout << "Rational: operator / rational" << endl;
	return Rational(this->numerator * other.denominator, this->denominator * other.numerator);
}

Rational Rational::operator+(const long long& other) const
{
	//cout << "Rational: operator + long long" << endl;
	return Rational(this->numerator  + this-> denominator * other, this->denominator);
}

Rational Rational::operator-(const long long& other) const
{
	//cout << "Rational: operator - long long" << endl;
	return Rational(this->numerator - this->denominator * other, this->denominator);
}

Rational Rational::operator*(const long long& other) const
{
	//cout << "Rational: operator * long long" << endl;
	return Rational(this->numerator  * other, this->denominator);
}

Rational Rational::operator/(const long long& other) const
{
	//cout << "Rational: operator / long long" << endl;
	return Rational(this->numerator, this->denominator * other);
}

Rational Rational::operator++()
{
	//cout << "Rational: Prefix increment" << endl;
	this->numerator += this->denominator;
	return *this;
}

Rational Rational::operator++(int)
{
	//cout << "Rational: Postfix increment" << endl;
	Rational temp = *this;
	this->numerator += this->denominator;
	return temp;
}

Rational Rational::operator--()
{
	//cout << "Rational: Prefix decrement" << endl;
	this->numerator -= this->denominator;
	return *this;
}

Rational Rational::operator--(int)
{
	//cout << "Rational: Postfix decrement" << endl;
	Rational temp = *this;
	this->numerator -= this->denominator;
	return temp;
}

Rational Rational::operator-()
{
	//cout << "Rational:  unary negative" << endl;
	this->numerator *= -1;
	return *this;
}

bool Rational::operator==(const Rational& other)
{
	//cout << "Rational: compare ==" << endl;
	return (this->numerator == other.numerator)&&(this->denominator == other.denominator);
}

bool Rational::operator!=(const Rational& other)
{
	//cout << "Rational: compare != " << endl;
	return !(*this == other);
}

bool Rational::operator<(const Rational& other)
{
	//cout << "Rational: compare < " << endl;
	return this->numerator * other.denominator < other.numerator * this->denominator;
}

bool Rational::operator>(const Rational& other)
{
	//cout << "Rational: compare > " << endl;
	return this->numerator * other.denominator > other.numerator * this->denominator;
}

bool Rational::operator<=(const Rational& other)
{
	//cout << "Rational: compare <= " << endl;
	return ! (*this>other);
}
bool Rational::operator>=(const Rational& other)
{
	//cout << "Rational: compare >= " << endl;
	return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const Rational& r)
{
	os << r.numerator << "/" << r.denominator;
	return os;
}

std::istream& operator>>(std::istream& is, Rational& r)
{
	is >> r.numerator >> r.denominator;
	return is;
}

