#pragma once
#include <iostream>
#include <numeric>
#include <stdexcept>
class Rational
{
private:
    long long numerator; 
    long long denominator;

    void reduce();

public:
    // �����������
    Rational(long long n = 0, long long d = 1);
    Rational(double value);

    double toDecimal();
    static double toDecimal(Rational item);
    

    // ���������� �������������� ���������� (����� � �����)
    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    // ���������� �������������� ���������� (����� � �����)
    Rational operator+(const long long& other) const;
    Rational operator-(const long long& other) const;
    Rational operator*(const long long& other) const;
    Rational operator/(const long long& other) const;

    //���������� ������� ����������
    Rational operator++();
    Rational operator++(int);
    Rational operator--();
    Rational operator--(int);
    Rational operator-();

    // ���������� ���������� ���������
    bool operator==(const Rational& other);
    bool operator!=(const Rational& other);
    bool operator<(const Rational& other);
    bool operator>(const Rational& other);
    bool operator<=(const Rational& other);
    bool operator>=(const Rational& other);

    // ���������� ���������� ����� � ������
    friend std::ostream& operator<<(std::ostream& os, const Rational& Rational);
    friend std::istream& operator>>(std::istream& is, Rational& Rational);


};