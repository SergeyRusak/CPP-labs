#include "Matrix.h"
#include <iostream>

using namespace std;

int main() {
    Vect<int> vect1(5);
    vect1[0] = 1;
    vect1[1] = 6;
    vect1[4] = 4;
    cout << "Vector 1" << endl; vect1.print();

    Vect<int> vect2(5);
    vect2[2] = 2;
    vect2[4] = 3;
    vect2[3] = 9;
    cout << "Vector 2" << endl; vect2.print();

    Vect<int> vect3 = vect1 + vect2;
    cout << "Sum of vecttors" << endl; vect3.print();

    int dot_product = vect1.dot(vect2);
    cout << "dot: " << dot_product << endl;

    Matr<int> mat1(3, 3);
    mat1(0, 0) = 1;
    mat1(1, 1) = 2;
    mat1(2, 2) = 3;
    cout << "Matrix 1" << endl; mat1.print();

    Matr<int> mat2(3, 3);
    mat2(0, 2) = 4;
    mat2(1, 1) = 5;
    mat2(2, 0) = 6;
    cout << "Matrix 2" << endl; mat2.print();

    Matr<int> mat3 = mat1 + mat2;
    cout << "Sum of matrix" << endl; mat3.print();

    Matr<int> transposed = mat1.transpose();
    cout << "Matrix transposed" << endl; transposed.print();

    return 0;
}