//задача 28.University, група комп'ютерна математика 2, Ільченко.
//файл де описані всі функції та типи даних

// Файл 28University.cpp

#include "28Universityy.h" //підключаємо заголовочний файл і бібліотеки
#include <fstream>

using namespace std;//підключаємо простір імен

// Реалізація класу Worker
Worker::Worker(const string& n, int a, double b, int e) //параметри конструетора
    : baseRate(b), experience(e) { // ініціалізацію полів класу Worker
    name = n;
    age = a;
}
//функція виводу даних
void Worker::display() const {
    cout << "Worker: " << name << ", Age: " << age << ", Base Rate: $" << baseRate
              << ", Experience: " << experience << " years";
}
// тест1: перевірка. Створення об'єкта класу Worker для тестування
    Worker worker("John Doe", 30, 50000.0, 5);

    // Виклик функції display для виведення інформації про працівника
    cout << "Test 1: Display Worker Information\n";
    worker.display(); // виведе інформацію про працівника


double Worker::calculateSalary() const { //функція, що підраховує заробітню плату
    return baseRate * (1 + 0.1 * experience);
}
//тест 2
// Виклик функції calculateSalary для підрахунку заробітної плати
    double expectedSalary = 50000.0 * (1 + 0.1 * 5); // Очікується, що це буде правильна заробітна плата
    double actualSalary = worker.calculateSalary();

    // Порівняння очікуваної та отриманої заробітної плати
    cout << "Test 1: Calculate Salary\n";
    if (expectedSalary == actualSalary) {
        cout << "  Passed: Salary calculation is correct.\n";
    } else {
        cout << "  Failed: Salary calculation is incorrect.\n";
        cout << "  Expected: $" << expectedSalary << ", Actual: $" << actualSalary << "\n";
    }


double Worker::calculateScholarship() const {
    return 0.0; // робітники не отримують стипендію
}

// Реалізація класу Professor
Professor::Professor(const string& n, int a, double b, int e, int d)
    : Worker(n, a, b, e), degree(d) {}
//функція виводу даних
void Professor::display() const {
    Worker::display();
    cout << ", Degree: " << degree << " degree\n";
}
//тут тест буде аналогічним до тесту 1

// Реалізація класу Student
Student::Student(const string& n, int a, double avg)
    : averageGrade(avg) {
    name = n;
    age = a;
}
//функція виводу даних
void Student::display() const {
    cout << "Student: " << name << ", Age: " << age << ", Average Grade: " << averageGrade;
}
//тест буде аналогічним до тесту 1

double Student::calculateSalary() const {
    return 0.0; // студенти не отримують зарплати
}

//функція, що підраховує  стипендію
double Student::calculateScholarship() const {
    return 500 + 100 * averageGrade; // приклад підрахунку стипендії
}
//тест 3
// Створення об'єкта класу Student для тестування
    Student student("Alice", 20, 3.8);

    // Виклик функції calculateScholarship для підрахунку стипендії
    double expectedScholarship = 500 + 100 * 3.8; // Очікується, що це буде правильна стипендія
    double actualScholarship = student.calculateScholarship();

    // Порівняння очікуваної та отриманої стипендії
    cout << "Test 1: Calculate Scholarship\n";
    if (abs(expectedScholarship - actualScholarship) < 1e-6) {
        cout << "  Passed: Scholarship calculation is correct.\n";
    } else {
        cout << "  Failed: Scholarship calculation is incorrect.\n";
        cout << "  Expected: $" << expectedScholarship << ", Actual: $" << actualScholarship << "\n";
    }

// Реалізація класу Transcript
//функція виводу даних
void Transcript::display() const {
    cout << "Transcript: " << studentName << ", Average Grade: " << averageGrade << "\n";
}
//тест аналогічний тесту 1

// Реалізація класу Profession
//функція виводу даних
void Profession::display() const {
    cout << "Profession: " << nameProfession << ", Base Rate: $" << baseRate << "\n";
}
//тест аналогічний тесту 1


// Реалізація функції printJson
template <typename T>
void printJson(const vector<T*>& vec) {
    for (const auto& obj : vec) {
        cout << "{ ";
        obj->display();
        cout << " },\n";
    }
}






