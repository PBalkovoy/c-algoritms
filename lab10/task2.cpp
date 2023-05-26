#include "task2.h"
#include <iostream>
#include <cmath>

// Begin.15 Дана площа S кола. Знайти його діаметр D і довжину L кола, що обмежує це коло, з
//огляду на, що L = π · D, S = π · D^2/ 4. Як значення π вважати рівним 3.14.

const double PI = 3.14;

struct Circle {
    double radius;
    double diameter;
    double length;
};

void processCircle(Circle& circle) {
    circle.diameter = 2 * circle.radius;
    circle.length = PI * circle.diameter;
}

void fillInputData(Circle& circle, double area) {
    circle.radius = sqrt(area / PI);
}

void task2_15() {
    Circle circle;
    double area;

    std::cout << "-----Task 2----\nEnter the area of the circle: ";
    std::cin >> area;

    fillInputData(circle, area);
    processCircle(circle);

    std::cout << "Circle Data:" << std::endl;
    std::cout << "Radius: " << circle.radius << std::endl;
    std::cout << "Diameter: " << circle.diameter << std::endl;
    std::cout << "Length: " << circle.length << std::endl;
}