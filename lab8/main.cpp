#include <iostream>
#include <stdio.h>
#include "tuple"


void task1_65();
void task2_25();
void task3_30();
int* cocktail_sort(int* arr, int size);
void print_array(int* arr, int size);
std::tuple<int**, int, int> init_matrix();
int** read_matrix(const char* filename, int rows, int cols);
void show_matrix(int **matrix, int rows, int cols);
std::tuple<int, int> get_max_sum_at_row(int **matrix, int rows, int cols);
void init_file_with_numbers(const char* filename, int size);
void write_numbers_to_file(const char *filename, int *numbers, int count);
int* read_array_from_file(const char* filename, int num_elements);
int* increase_array_elements_by_index(int arr[], int arr_size, int index);

int main() {
    int choice;
    do {
        std::cout << "Choose task:\n";
        std::cout << "1. Task 1\n";
        std::cout << "2. Task 2\n";
        std::cout << "3. Task 3\n";
        std::cout << "0. Выход\n";
        std::cout << ">> ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                // виконання дії 1
                std::cout << "Task1 1\n";
                task1_65();
                break;
            case 2:
                // виконання дії 2
                std::cout << "Task 2\n";
                task2_25();
                break;
            case 3:
                // виконання дії 3
                std::cout << "Task 3\n";
                task3_30();
                break;
            case 0:
                // вихід з програми
                std::cout << "Exit\n";
                break;
            default:
                // повідомлення про помилку
                std::cout << "Invalid choice\n";
                break;
        }
    } while (choice != 0);

    return 0;
}

//Array65. Дано масив A розміру N і ціле число K (1 ≤ K ≤ N). Перетворити масив,
//збільшивши кожен його елемент на початкове значення елемента AK.
void task1_65() {
    //назва файлу із вхідними даними
    const char* input_filename = "array_in_65.txt";
    //назва файлу із вихідними даними
    const char* output_filename = "array_out_65.txt";
    //кількість чисел
    int size = 5;
    //індекс для зміни значення
    int index_to_change;

    std::cout << "Enter index to change array: ";
    std::cin >> index_to_change;//ввод індексу для зміни
    std::cout << std::endl;

    init_file_with_numbers(input_filename, size);//ініціалізація файлу із значеннями
    int* numbers_from_file = read_array_from_file(input_filename, size);//зчитування нових чисел з файлу
    //виконання змін у масиві
    int* changed_numbers = increase_array_elements_by_index(numbers_from_file, size, index_to_change);
    //запис нових значень до вихідного файлу
    write_numbers_to_file(output_filename, changed_numbers, size);

    //вивід нових значень у консоль
    std::cout << "Changed numbers:\n";
    print_array(changed_numbers, size);
}

// Matrix25. Дана матриця розміру M × N. Знайти номер її рядки з найбільшою сумою
// елементів і вивести даний номер, а також значення максимальної суми.
void task2_25() {
    const char* filename = "matr_in_15.txt";
    // виклик функції ініціалізації матриці
    auto [matrix, rows, cols] = init_matrix();
    //зчитування матриці із файлу
    matrix = read_matrix(filename, rows, cols);
    // виклик функції виведення матриці
    show_matrix(matrix, rows, cols);
    // виклик функції, яка знайде максимальну суму рядка
    auto [max_sum, max_sum_row_index] = get_max_sum_at_row(matrix, rows, cols);
    // виведення результату функції у консоль
    std::cout << "Max sum in row = " << max_sum << " in row #" << max_sum_row_index + 1 << std::endl;
}
// 30. Шейкерна, Зменшення, Цілий
void task3_30() {
    //назва файлу із вхідними числами
    const char* input_filename = "cocktail_sort.txt";
    //кількість чисел
    int size = 7;
    //зчитування чисел з файлу
    int* numbers_from_file = read_array_from_file(input_filename, size);
    //використання шейкерного методу для сортування
    int* cocktail_sorted_array = cocktail_sort(numbers_from_file, size);
    //друкування результату у консоль
    print_array(cocktail_sorted_array, size);
}
//функція шейкерного сортування
int* cocktail_sort(int* arr, int size) {
    bool swapped = true;
    int start = 0;
    int end = size - 1;

    while (swapped) {
        swapped = false;

        // цикл зліва до права
        for (int i = start; i < end; i++) {
            if (arr[i] < arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // якщо нічого не було змінено, то массив відсортован
        if (!swapped)
            break;

        swapped = false;

        // зміна кінця на один через його відсортованість
        end--;

        // цикл зправа до ліва
        for (int i = end - 1; i >= start; i--) {
            if (arr[i] < arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // зміна початку на один через його відсортованість
        start++;
    }

    return arr;
}
//функція яка друкує массив у консоль
void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// функції ініціалізації матриці
std::tuple<int**, int, int> init_matrix() {
    int rows, cols; // об'ява розмірів матриці
    int **matrix; // об'ява пустої матриці

    std::cout << "Enter M(rows) numbers of matrix: ";
    std::cin >> rows; // ввід кількості рядків

    std::cout << "Enter N(columns) numbers of matrix: ";
    std::cin >> cols; // ввід кількості колонок

    matrix = (int **) malloc(rows * sizeof(int*)); // виділення пам'яті під рядки матриці

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *) malloc(cols * sizeof(int)); // виділення пам'яті під кожну колонку матриці
        for (int j = 0; j < cols; j++) {
            std::cout << "Enter matrix[" << i << "][" << j << "] element: ";
            std::cin >> matrix[i][j]; // ввід кожного елементу матриці з консолі
        }
    }
    return {matrix, rows, cols}; // повернення матриці та її розмірів як кортеж
}

// функції ініціалізації матриці
int** read_matrix(const char* filename, int rows, int cols) {
    FILE* fp = fopen(filename, "r");
    int **matrix; // об'ява пустої матриці

    std::cout << "Enter M(rows) numbers of matrix: ";
    std::cin >> rows; // ввід кількості рядків

    std::cout << "Enter N(columns) numbers of matrix: ";
    std::cin >> cols; // ввід кількості колонок

    matrix = (int **) malloc(rows * sizeof(int*)); // виділення пам'яті під рядки матриці

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *) malloc(cols * sizeof(int)); // виділення пам'яті під кожну колонку матриці
        for (int j = 0; j < cols; j++) {
            std::cout << "Enter matrix[" << i << "][" << j << "] element: ";
            fscanf(fp, "%d", &matrix[i][j]);
        }
    }
    return matrix; // повернення матриці
}

// функція виведення масиву
void show_matrix(int **matrix, int rows, int cols) {
    std::cout << "\nMatrix: " << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << "\t"; // вивід кожного елементу матриці

        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// функція отримання максимальної суми рядка
std::tuple<int, int> get_max_sum_at_row(int **matrix, int rows, int cols) {
    int max_sum_row_index, max_sum = 0; // об'ява змінних
    for (int i = 0; i < rows; i++) {
        int row_sum = 0; // ініціалізація суми рядка
        for (int j = 0; j < cols; j++) {
            row_sum += matrix[i][j]; // підрахунок суми рядка
        }
        // якщо сума конкретного рядка більша за попередні суми, то записуємо цю суму та номер рядку
        if (row_sum > max_sum) {
            max_sum = row_sum;
            max_sum_row_index = i;
        }
    }
    return {max_sum, max_sum_row_index}; // повернення суми та індексу рядка де ця сума була як кортеж
}

void init_file_with_numbers(const char* filename, const int size) {
    int numbers[size];

    std::cout << "Введите " << size << " целых чисел:" << std::endl;

    for (int i = 0; i < size; i++) {
        numbers[i] = 0;
        std::cin >> numbers[i];
    }
    //запис ініціалізованих чисел у файл
    write_numbers_to_file(filename, numbers, size);
}

void write_numbers_to_file(const char *filename, int *numbers, int count) {
    FILE *fp = fopen(filename, "w+"); // Открываем файл на запись
    if (fp == NULL) { // Если не удалось открыть файл, выводим сообщение об ошибке и завершаем функцию
        printf("Ошибка при открытии файла\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d ", numbers[i]); // Записываем каждое число в файл, разделяя пробелом
    }
    fclose(fp); // Закрываем файл
}

int* read_array_from_file(const char* filename, int num_elements) {
    int* arr;
    int i = 0;
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }
    // кількість елементів у файлі
    while (fscanf(fp, "%d", &arr[i]) == 1) {
        i++;
    }
    num_elements = i;
    //виділення пам'яті для массиву
    if (arr == NULL) {
        fprintf(stderr, "Error allocating memory for array\n");
        exit(1);
    }
    //зчитування даних із файла у массив
    rewind(fp);
    for (i = 0; i < num_elements; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);
    return arr;
}

//функція збільщення усього масиву на число під конкретним індексом
int* increase_array_elements_by_index(int arr[], int arr_size, int index) {
    if (index < 0 || index >= arr_size) {
        fprintf(stderr, "Invalid index\n");
        exit(1);
    }
    int value_to_add = arr[index];
    for (int i = 0; i < arr_size; i++) {
        arr[i] += value_to_add;
    }
    return arr;
}