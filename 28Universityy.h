//задача 28.University, група комп'ютерна математика 2, Ільченко.
//заголовочний файл
#pragma once // вказує компілятору, що файл, в якому вона розміщена, повинен бути зчитаний лише один раз в процесі компіляції

#include <iostream> /підключаємо потрібні бібліотеки
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include<json-c/json.h>

using namespace std;//підключаємо простір імен

//клас Людина
class Human {
public:
    //визначаємо змінні і'мя та вік
    string name;
    int age;
    //визначаємо функції виводу,підрахунку зарплати та стипенді
    //virtual void бо клас Людина - абстрактний
    virtual void display() const = 0;
    virtual double calculateSalary() const = 0;
    virtual double calculateScholarship() const = 0;
};

//клас Працівник.нащадок класу Human
class Worker : public Human {
public:
    //визначаємо змінні ставка та досвід роботи
    double baseRate;
    int experience;
    //конструктор для класу Worker
    Worker(const string& n, int a, double b, int e);
   //визначаємо функції виводу,підрахунку зарплати та стипендії
    void display() const override;
    double calculateSalary() const override;
    double calculateScholarship() const override;
};

//клас Викладач.нащадок класу Worker
class Professor : public Worker {
public:
    //визначаємо змінну
    int degree;
    //конструктор класу Professor
    Professor(const string& n, int a, double b, int e, int d);


    //визначаємо функцію виводу
    void display() const override;
};

//клас Студент.нащадок класу Human
class Student : public Human {
public:
    //визначаємо змінну середній бал
    double averageGrade;
    //конструктор класу Student
    Student(const string& n, int a, double avg);
    //визначаємо функції виводу,підрахунку зарплати та стипендії
    void display() const override;
    double calculateSalary() const override;
    double calculateScholarship() const override;
};


// Клас "Заліковка"
class Transcript : public Student {
public:
    string studentName;
    //визначаємо функцію виводу
    void display() const;
};

// Клас "Професія"
class Profession : public Professor{
public:
    string nameProfession;
    //визначаємо функцію виводу
    void display() const;
};

// Функція для виведення вектора об'єктів у форматі JSON
template <typename T>
void printJson(const vector<T*>& vec);
