//задача 28.University, група комп'ютерна математика 2, Ільченко.
//тестовий файл


#include "28Universityy.h" // підключаємо заголовочний файл і бібліотеки
#include <iostream>
#include <fstream>

using namespace std; // підключаємо простір імен

int main(int argc, char *argv[]) {
    // Тест 1: Перевірка кількості аргументів командного рядка
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_mode>\n";
        cerr << "   <input_mode>: 1 for console input, 2 for file input\n";
        return 1;
    }

    // Тест 2: Перевірка, чи виводиться повідомлення про неправильне значення аргументу командного рядка
    int inputMode = std::atoi(argv[1]); // Перетворюємо рядок на ціле число.
    if (inputMode != 1 && inputMode != 2) {
        cerr << "Test 2 Failed: Invalid input_mode\n";
        cerr << "Usage: " << argv[0] << " <input_mode>\n";
        cerr << "   <input_mode>: 1 for console input, 2 for file input\n";
        return 1;// Помилка у використанні програми.
    }

    // Тест 3: Перевірка, чи програма працює правильно при коректному введенні аргументу.
    cout << "Test 3 Passed: Correct usage with input_mode = " << inputMode << "\n";


    // Отримання режиму введення з аргументів командного рядка
    inputMode = atoi(argv[1]);

    vector<Human*> universityMembers;

    if (inputMode == 1) {
        // Режим введення з консолі

        // дані працівника
        cout << "Enter worker data:\n";
        double baseRate;
        int experience;
        string name;
        int age;

        cout << "Name: ";
        cin >> name;

        cout << "Age: ";
        cin >> age;

        cout << "Base Rate: ";
        cin >> baseRate;

        cout << "Experience: ";
        cin >> experience;

        // дані викладача
        cout << "Enter teacher data:\n";
        int degree;
        cout << "Degree: ";
        cin >> degree;

        // дані студента
        cout << "Enter student data:\n";
        double averageGrade;
        cout << "averageGrade: ";
        cin >> averageGrade;

        // дані заліковки
        cout << "Enter transcript data:\n";
        string studentName;
        cout << "studentName: ";
        cin >> studentName;

        // дані професії
        cout << "Enter profession data:\n";
        string nameProfession;
        cout << "name of the profession: ";

        // Режим введення з текстового файлу
        ifstream inputFile("28University_test.txt.txt");

        // Тест 1: Перевірка, чи відбувається правильне відкриття файлу.
        if (!inputFile.is_open()) {
            cerr << "cannot open 28University_test.txt.txt for reading.\n";
            return 1;
        } else {
        cout << "Test 1 Passed: File opened successfully for reading.\n";
    }

        // зчитування даних з файлу
        // Worker
        while (inputFile >> name >> age >> baseRate >> experience) {
            universityMembers.push_back(Worker(name, age, baseRate, experience));
        }

        // Professor
        while (inputFile >> degree) {
            universityMembers.push_back(new Professor(degree));
        }

        // Student
        while (inputFile >> averageGrade) {
            universityMembers.push_back(new Student(averageGrade));
        }

        // Transcript
        while (inputFile >> studentName) {
            universityMembers.push_back(new Transcript(studentName));
        }

        // Profession
        while (inputFile >> nameProfession) {
            universityMembers.push_back(new Profession(nameProfession));
        }

        inputFile.close();

        // Тест 2: Перевірка, чи виводиться повідомлення про помилку, якщо файл не існує.
        ifstream nonExistentFile("non_existent_file.txt");

    if (!nonExistentFile.is_open()) {
        cout << "Test 2 Passed: Cannot open non_existent_file.txt for reading (as expected).\n";
    } else {
        cerr << "Test 2 Failed: File non_existent_file.txt opened unexpectedly.\n";
        return 1; // Помилка: файл, якого не повинно було відкривати, відкрито.
    }


        //Якщо режим введення не відповідає жодному із дозволених режимів
        // програма виводить повідомлення про невірний режим введення та завершується з кодом повернення 1
    } else {
        cerr << "Invalid input mode. Use 1 for console input or 2 for file input.\n";
        return 1;
    }
     //Якщо режим введення є правильним - вивід у форматі json
    cout << "University Members:\n";
    printJson(universityMembers);

    for (auto& member : universityMembers) {
        delete member;//очищення пам'яті
    }

    return 0;
}

