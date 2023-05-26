#include <iostream>
#include "task1.h"

// Param59. Описати тип TDate - запис з полями цілого типу Day (день), Month (місяць) і
//Year (рік) - і функцію LeapYear (D) логічного типу з параметром типу TDate,
//яка повертає True, якщо рік у даті D є високосним, і False в іншому випадку.
//Вивести значення функції LeapYear для п'яти даних дат (передбачається, що всі
//дати є правильними) .Вісокосним вважається рік, ділиться на 4, за винятком
//тих років, які діляться на 100 і не діляться на 400.

struct TDate {
    int Day;
    int Month;
    int Year;
};

bool LeapYear(const TDate& date) {
    if (date.Year % 4 == 0) {
        if (date.Year % 100 == 0) {
            if (date.Year % 400 == 0)
                return true;
            else
                return false;
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}

void task1_59() {
    std::cout << "-----Task1-----" << std::endl;
    TDate dates[5] = {
            { 1, 1, 2000 },  // високосний рік
            { 29, 2, 2020 }, // високосний рік
            { 28, 2, 2021 }, // не високосний рік
            { 31, 12, 2022 }, // не високосний рік
            { 29, 2, 2024 } // високосний рік
    };

    for (int i = 0; i < 5; i++) {
        bool isLeap = LeapYear(dates[i]);
        std::cout << "Date: " << dates[i].Day << "/" << dates[i].Month << "/" << dates[i].Year;
        std::cout << " Leap Year: " << (isLeap ? "True" : "False") << std::endl;
    }
}
