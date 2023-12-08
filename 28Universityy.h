//������ 28.University, ����� ����'������ ���������� 2, ��������.
//������������ ����

#pragma once // ����� ����������, �� ����, � ����� ���� ��������, ������� ���� �������� ���� ���� ��� � ������ ���������

#include <iostream> //��������� ������ ��������
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include<json-c/json.h>

using namespace std; //��������� ������ ����

//���� ������
class Human {
public:
    //��������� ���� �'�� �� ��
    string name;
    int age;
    //��������� ������� ������,��������� �������� �� �������
    //virtual void �� ���� ������ - �����������
    virtual void display() const = 0;
    virtual double calculateSalary() const = 0;
    virtual double calculateScholarship() const = 0;
};

//���� ���������.������� ����� Human
class Worker : public Human {
public:
    //��������� ���� ������ �� ����� ������
    double baseRate;
    int experience;
    //����������� ��� ����� Worker
    Worker(const string& n, int a, double b, int e);
    //��������� ������� ������,��������� �������� �� ������䳿
    void display() const override;
    double calculateSalary() const override;
    double calculateScholarship() const override;
};

//���� ��������.������� ����� Worker
class Professor : public Worker {
public:
    //��������� �����
    int degree;
    //����������� ����� Professor
    Professor(const string& n, int a, double b, int e, int d);


    //������� ������
    void display() const override;
};

//���� �������.������� ����� Human
class Student : public Human {
public:
    //��������� ����� ������� ���
    double averageGrade;
    //����������� ����� Student
    Student(const string& n, int a, double avg);
    //��������� ������� ������,��������� �������� �� ������䳿
    void display() const override;
    double calculateSalary() const override;
    double calculateScholarship() const override;
};


// ���� "��������"
class Transcript : public Student {
public:
    string studentName;
    //��������� ������� ������
    void display() const;
};

// ���� "�������"
class Profession : public Professor{
public:
    string nameProfession;
    //��������� ������� ������
    void display() const;
};

// ������� ��� ��������� ������� ��'���� � ������ JSON
template <typename T>
void printJson(const vector<T*>& vec);
