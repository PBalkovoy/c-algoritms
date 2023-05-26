#include "task3.h"
#include <iostream>

//Boolean21.Дано тризначне число. Перевірити істинність висловлювання:
// «Цифри даного числа утворюють зростаючу послідовність».

struct Number {
    int value;    // тризначне число
    bool isIncreasingSequence;    // прапорець, що позначає, чи утворюють цифри числа зростаючу послідовність
};

void processNumber(Number& num) {
    int digit1 = num.value / 100;    // перша цифра числа
    int digit2 = (num.value / 10) % 10;    // друга цифра числа
    int digit3 = num.value % 10;    // третя цифра числа

    num.isIncreasingSequence = (digit1 < digit2) && (digit2 < digit3);
}

void inputNumber(Number& num) {
    std::cout << "Enter a three-digit number: ";
    std::cin >> num.value;

    if (num.value < 100 || num.value > 999) {
        throw std::invalid_argument( "Not a three-digit number" );
    }
}

void task3_boolean21() {
    std::cout << "-----Task3-----" << std::endl;
    Number myNumber;
    inputNumber(myNumber);
    processNumber(myNumber);

    std::cout << "Is the sequence increasing? " << (myNumber.isIncreasingSequence ? "Yes" : "No") << std::endl;
}
