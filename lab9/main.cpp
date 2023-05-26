#include <iostream>
#include <string>

void task1_10();
void task2_60();
std::string& assign(size_t n, char c);
std::string remove_first_directory_name(std::string& filePath);
bool test_remove_second_directory_name(std::string **test_cases, int cases_count);

int main() {
    task1_10(); // виклик функції виконання першого завдання
    task2_60(); // виклик функції виконання другого завдання
    return 0;
}

// string& assign (size_t n, char c);
void task1_10() {
    char symbol;
    int amount;

    std::cout << "-----Task1-----\n" << std::endl;

    std::cout << "Enter symbol to assign: ";
    std::cin >> symbol; // введення символу для виконання функії assign

    std::cout << "Enter amount of copies: ";
    std::cin >> amount; // введеня кількості разів, скільки потрібно повторити значення

    std::string result = assign(amount, symbol); // Присвоювання результату функії assign до змінної result

    std::cout << "New assigned line: " << result << std::endl;
}

// String60.Дано рядок, що містить повне ім'я файлу, тобто ім'я диска, список
// каталогів (путь), власне ім'я та розширення.. Виділити з цього рядка
// назву першого каталогу (без символів «\»). Якщо файл міститься в
// кореневому каталозі, то вивести символ «\».
void task2_60() {
    std::cout << "\n-----Task2-----\n" << std::endl;

    int test_case_counts = 5; // кількість тестових завдань для перевірки

    // виділення пам'яті під матрицю тестування
    std::string** test_cases = new std::string*[test_case_counts];
    for (int i = 0; i < test_case_counts; i++) {
        test_cases[i] = new std::string[2];
    }

    // ініціалізація тестових даних, де елемент [i][0] - вхідні дані,
    // а елемент [i][1] - очікуваний результат виконаня функції
    test_cases[0][0] = "C:\\Users\\Documents\\file.txt";
    test_cases[0][1] = "C:\\Documents\\file.txt";

    test_cases[1][0] = "C:\\file.txt";
    test_cases[1][1] = "C:\\";

    test_cases[2][0] = "C:\\";
    test_cases[2][1] = "C:\\";

    test_cases[3][0] = "file.txt";
    test_cases[3][1] = "file.txt";

    test_cases[4][0] = "C:\\Program Files\\file.txt";
    test_cases[4][1] = "C:\\file.txt";

    // виклик функції тестування функціоналу
    test_remove_second_directory_name(test_cases, test_case_counts);
}

// власна реалізакція функії assign
std::string& assign(size_t n, char c) {
    char* str = new char[n + 1]; // створення нового динамічного массиву символів
    for (size_t i = 0; i < n; ++i) {
        str[i] = c; // заповнення массиву символами відповідно до їх кількості
    }
    str[n] = '\0'; // закінчення строки нульовим символом

    // створення змінної результату у форматі std::string
    std::string& result = *new std::string(str);

    // очистка пам'ті для непотрібної більше змінної
    delete[] str;

    return result; // повернення результату
}

// функція видалення із рядка шляху до файлу, вирізає перший каталог, якщо такий є
std::string remove_first_directory_name(std::string& filePath) {
    // знаходження першого входження символу '\' або '/' та додавання 1, щоб пропустити його
    size_t startIndex = filePath.find_first_of("\\/") + 1;
    // знаходження першого входження символу '\' або '/' починаючи з startIndex та додавання 1, щоб пропустити його
    size_t endIndex = filePath.find_first_of("\\/", startIndex) + 1;

    if (endIndex != std::string::npos) { // якщо знайден символ '\', то видаляється підстрока між startIndex та endIndex
        filePath.erase(startIndex, endIndex - startIndex);
    } else { // якщо символ '\' не знайден, то додаємо ім'я файлу до кінця строки
        // знаходження останнього входження символу '\' або '/' та додавання 1, щоб пропустити його
        size_t lastSlashIndex = filePath.find_last_of("\\/") + 1;
        // отримання назви файлу та видалення його із строки
        std::string fileName = filePath.substr(lastSlashIndex);
        filePath.erase(lastSlashIndex); // видалення всіх символів із строки після lastSlashIndex
        filePath += fileName; // додавання ім'я файлу до кінця строки
    }

    return filePath; // повернення зміненого файлу
}

// функція для тестування правильного виконання завдання 2
bool test_remove_second_directory_name(std::string **test_cases, int cases_count) {
    for (int i = 0; i < cases_count; i++) {
        // отримання результату викоання функції на вхідних даних
        std::string func_result = remove_first_directory_name(test_cases[i][0]);
        // порівняння резільтату виконаня функції та очікуваного результату
        if (func_result != test_cases[i][1]) {
            std::cout << "Test case" << i + 1 << " failed." << std::endl;
            return false;
        }
    }
    std::cout << "All test cases passed." << std::endl;
    return true;
}