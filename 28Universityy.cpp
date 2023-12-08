//������ 28.University, ����� ����'������ ���������� 2, ��������.
//���� �� ������ �� ������� �� ���� �����

// ���� 28University.cpp

#include "28Universityy.h" //��������� ������������ ���� � ��������
#include <fstream>

using namespace std;//��������� ������ ����

// ��������� ����� Worker
Worker::Worker(const string& n, int a, double b, int e) //��������� ������������
    : baseRate(b), experience(e) { // ����������� ���� ����� Worker
    name = n;
    age = a;
}
//������� ������ �����
void Worker::display() const {
    cout << "Worker: " << name << ", Age: " << age << ", Base Rate: $" << baseRate
              << ", Experience: " << experience << " years";
}
// ����1: ��������. ��������� ��'���� ����� Worker ��� ����������
    Worker worker("John Doe", 30, 50000.0, 5);

    // ������ ������� display ��� ��������� ���������� ��� ����������
    cout << "Test 1: Display Worker Information\n";
    worker.display(); // ������ ���������� ��� ����������


double Worker::calculateSalary() const { //�������, �� �������� �������� �����
    return baseRate * (1 + 0.1 * experience);
}
//���� 2
// ������ ������� calculateSalary ��� ��������� �������� �����
    double expectedSalary = 50000.0 * (1 + 0.1 * 5); // ���������, �� �� ���� ��������� �������� �����
    double actualSalary = worker.calculateSalary();

    // ��������� ��������� �� �������� �������� �����
    cout << "Test 1: Calculate Salary\n";
    if (expectedSalary == actualSalary) {
        cout << "  Passed: Salary calculation is correct.\n";
    } else {
        cout << "  Failed: Salary calculation is incorrect.\n";
        cout << "  Expected: $" << expectedSalary << ", Actual: $" << actualSalary << "\n";
    }


double Worker::calculateScholarship() const {
    return 0.0; // �������� �� ��������� ��������
}

// ��������� ����� Professor
Professor::Professor(const string& n, int a, double b, int e, int d)
    : Worker(n, a, b, e), degree(d) {}
//������� ������ �����
void Professor::display() const {
    Worker::display();
    cout << ", Degree: " << degree << " degree\n";
}
//��� ���� ���� ���������� �� ����� 1

// ��������� ����� Student
Student::Student(const string& n, int a, double avg)
    : averageGrade(avg) {
    name = n;
    age = a;
}
//������� ������ �����
void Student::display() const {
    cout << "Student: " << name << ", Age: " << age << ", Average Grade: " << averageGrade;
}
//���� ���� ���������� �� ����� 1

double Student::calculateSalary() const {
    return 0.0; // �������� �� ��������� ��������
}

//�������, �� ��������  ��������
double Student::calculateScholarship() const {
    return 500 + 100 * averageGrade; // ������� ��������� ������䳿
}
//���� 3
// ��������� ��'���� ����� Student ��� ����������
    Student student("Alice", 20, 3.8);

    // ������ ������� calculateScholarship ��� ��������� ������䳿
    double expectedScholarship = 500 + 100 * 3.8; // ���������, �� �� ���� ��������� ��������
    double actualScholarship = student.calculateScholarship();

    // ��������� ��������� �� �������� ������䳿
    cout << "Test 1: Calculate Scholarship\n";
    if (abs(expectedScholarship - actualScholarship) < 1e-6) {
        cout << "  Passed: Scholarship calculation is correct.\n";
    } else {
        cout << "  Failed: Scholarship calculation is incorrect.\n";
        cout << "  Expected: $" << expectedScholarship << ", Actual: $" << actualScholarship << "\n";
    }

// ��������� ����� Transcript
//������� ������ �����
void Transcript::display() const {
    cout << "Transcript: " << studentName << ", Average Grade: " << averageGrade << "\n";
}
//���� ���������� ����� 1

// ��������� ����� Profession
//������� ������ �����
void Profession::display() const {
    cout << "Profession: " << nameProfession << ", Base Rate: $" << baseRate << "\n";
}
//���� ���������� ����� 1


// ��������� ������� printJson
template <typename T>
void printJson(const vector<T*>& vec) {
    for (const auto& obj : vec) {
        cout << "{ ";
        obj->display();
        cout << " },\n";
    }
}






