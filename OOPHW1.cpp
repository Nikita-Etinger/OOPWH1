

#include <iostream>
using namespace std;


class Drob {
private:
    int numerator;   // числитель
    int denominator; // знаменатель


public:
    Drob() {
        numerator = 0;
        denominator = 1;
    }
    Drob(int numerator,int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    void input(int numerator, int denominator) {
       this->numerator = numerator;
       this->denominator = denominator;

    }
    // сложение
    Drob add(const Drob& secondDrob) {
        int resultNum = numerator * secondDrob.denominator + secondDrob.numerator * denominator;
        int resultDenom = denominator * secondDrob.denominator;
        return Drob(resultNum, resultDenom);
    }

    // вычитание
    Drob subtract(const Drob& secondDrob) {
        int resultNum = numerator * secondDrob.denominator - secondDrob.numerator * denominator;
        int resultDenom = denominator * secondDrob.denominator;
        return Drob(resultNum, resultDenom);
    }

    // умножение
    Drob multiply(const Drob& secondDrob) {
        int resultNum = numerator * secondDrob.numerator;
        int resultDenom = denominator * secondDrob.denominator;
        return Drob(resultNum, resultDenom);
    }

    // деление
    Drob divide(const Drob& secondDrob) {
        int resultNum = numerator * secondDrob.denominator;
        int resultDenom = denominator * secondDrob.numerator;
        return Drob(resultNum, resultDenom);
    }

    void print() const {
        std::cout << numerator << "/" << denominator << std::endl;
    }




};


int main()
{
    setlocale(LC_ALL, "Russian");

    Drob d1, d2;

    d1.input(12,1);

    d2.input(20,3);

    Drob sum = d1.add(d2);
    Drob difference = d1.subtract(d2);
    Drob product = d1.multiply(d2);
    Drob quotient = d1.divide(d2);

    std::cout << "Сумма: ";
    sum.print();

    std::cout << "Разность: ";
    difference.print();

    std::cout << "Произведение: ";
    product.print();

    std::cout << "Частное: ";
    quotient.print();

}

