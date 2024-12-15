#include <iostream>
#include "rational.h"

int main() {
    try {
        // Создание объектов Rational
        Rational r1(3, 4); // 3/4
        Rational r2(5, 6); // 5/6
        Rational r3;       // 0/1 (по умолчанию)

        std::cout << "Rational numbers:" << std::endl;
        std::cout << "r1: " << r1 << std::endl;
        std::cout << "r2: " << r2 << std::endl;
        std::cout << "r3: " << r3 << std::endl;

        // Арифметические операции
        Rational sum = r1 + r2;
        Rational diff = r1 - r2;
        Rational prod = r1 * r2;
        Rational quot = r1 / r2;

        std::cout << "\nArithmetic operations:" << std::endl;
        std::cout << "r1 + r2 = " << sum << std::endl;       // 38/24 -> 19/12
        std::cout << "r1 - r2 = " << diff << std::endl;      // -1/12
        std::cout << "r1 * r2 = " << prod << std::endl;      // 15/24 -> 5/8
        std::cout << "r1 / r2 = " << quot << std::endl;      // 18/20 -> 9/10

        // Операции с целыми числами
        long long integer = 2;
        Rational addInt = r1 + integer;
        Rational subInt = r1 - integer;

        std::cout << "\nOperations with integers:" << std::endl;
        std::cout << "r1 + 2 = " << addInt << std::endl;      // 11/4
        std::cout << "r1 - 2 = " << subInt << std::endl;      // -5/4

        // Унарные операторы
        Rational preInc = ++r3;   // Увеличиваем на 1
        Rational postInc = r3++;   // Увеличиваем на 1 после использования

        std::cout << "\nUnary operations:" << std::endl;
        std::cout << "++r3: " << preInc << ", after increment: " << r3 << std::endl; // 1/1
        std::cout << "r3++: " << postInc << ", after increment: " << r3 << std::endl; // 1/1

        // Сравнение дробей
        bool isEqual = (r1 == r2);
        bool isNotEqual = (r1 != r2);

        std::cout << "\nComparison:" << std::endl;
        std::cout << "r1 == r2: " << (isEqual ? "true" : "false") << std::endl;
        std::cout << "r1 != r2: " << (isNotEqual ? "true" : "false") << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
