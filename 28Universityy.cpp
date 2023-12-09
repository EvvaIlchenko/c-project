//задача 28.University, група комп'ютерна математика 2, Ільченко.
//файл де описані всі функції та типи даних

// Файл 28University.cpp

#include "28Universityy.h" //ï³äêëþ÷àºìî çàãîëîâî÷íèé ôàéë ³ á³áë³îòåêè
#include <fstream>

using namespace std;//ï³äêëþ÷àºìî ïðîñò³ð ³ìåí

// Ðåàë³çàö³ÿ êëàñó Worker
Worker::Worker(const string& n, int a, double b, int e) //ïàðàìåòðè êîíñòðóåòîðà
    : baseRate(b), experience(e) { // ³í³ö³àë³çàö³þ ïîë³â êëàñó Worker
    name = n;
    age = a;
}
//ôóíêö³ÿ âèâîäó äàíèõ
void Worker::display() const {
    cout << "Worker: " << name << ", Age: " << age << ", Base Rate: $" << baseRate
              << ", Experience: " << experience << " years";
}
// òåñò1: ïåðåâ³ðêà. Ñòâîðåííÿ îá'ºêòà êëàñó Worker äëÿ òåñòóâàííÿ
    Worker worker("John Doe", 30, 50000.0, 5);

    // Âèêëèê ôóíêö³¿ display äëÿ âèâåäåííÿ ³íôîðìàö³¿ ïðî ïðàö³âíèêà
    cout << "Test 1: Display Worker Information\n";
    worker.display(); // âèâåäå ³íôîðìàö³þ ïðî ïðàö³âíèêà


double Worker::calculateSalary() const { //ôóíêö³ÿ, ùî ï³äðàõîâóº çàðîá³òíþ ïëàòó
    return baseRate * (1 + 0.1 * experience);
}
//òåñò 2
// Âèêëèê ôóíêö³¿ calculateSalary äëÿ ï³äðàõóíêó çàðîá³òíî¿ ïëàòè
    double expectedSalary = 50000.0 * (1 + 0.1 * 5); // Î÷³êóºòüñÿ, ùî öå áóäå ïðàâèëüíà çàðîá³òíà ïëàòà
    double actualSalary = worker.calculateSalary();

    // Ïîð³âíÿííÿ î÷³êóâàíî¿ òà îòðèìàíî¿ çàðîá³òíî¿ ïëàòè
    cout << "Test 1: Calculate Salary\n";
    if (expectedSalary == actualSalary) {
        cout << "  Passed: Salary calculation is correct.\n";
    } else {
        cout << "  Failed: Salary calculation is incorrect.\n";
        cout << "  Expected: $" << expectedSalary << ", Actual: $" << actualSalary << "\n";
    }


double Worker::calculateScholarship() const {
    return 0.0; // ðîá³òíèêè íå îòðèìóþòü ñòèïåíä³þ
}

// Ðåàë³çàö³ÿ êëàñó Professor
Professor::Professor(const string& n, int a, double b, int e, int d)
    : Worker(n, a, b, e), degree(d) {}
//ôóíêö³ÿ âèâîäó äàíèõ
void Professor::display() const {
    Worker::display();
    cout << ", Degree: " << degree << " degree\n";
}
//òóò òåñò áóäå àíàëîã³÷íèì äî òåñòó 1

// Ðåàë³çàö³ÿ êëàñó Student
Student::Student(const string& n, int a, double avg)
    : averageGrade(avg) {
    name = n;
    age = a;
}
//ôóíêö³ÿ âèâîäó äàíèõ
void Student::display() const {
    cout << "Student: " << name << ", Age: " << age << ", Average Grade: " << averageGrade;
}
//òåñò áóäå àíàëîã³÷íèì äî òåñòó 1

double Student::calculateSalary() const {
    return 0.0; // ñòóäåíòè íå îòðèìóþòü çàðïëàòè
}

//ôóíêö³ÿ, ùî ï³äðàõîâóº  ñòèïåíä³þ
double Student::calculateScholarship() const {
    return 500 + 100 * averageGrade; // ïðèêëàä ï³äðàõóíêó ñòèïåíä³¿
}
//òåñò 3
// Ñòâîðåííÿ îá'ºêòà êëàñó Student äëÿ òåñòóâàííÿ
    Student student("Alice", 20, 3.8);

    // Âèêëèê ôóíêö³¿ calculateScholarship äëÿ ï³äðàõóíêó ñòèïåíä³¿
    double expectedScholarship = 500 + 100 * 3.8; // Î÷³êóºòüñÿ, ùî öå áóäå ïðàâèëüíà ñòèïåíä³ÿ
    double actualScholarship = student.calculateScholarship();

    // Ïîð³âíÿííÿ î÷³êóâàíî¿ òà îòðèìàíî¿ ñòèïåíä³¿
    cout << "Test 1: Calculate Scholarship\n";
    if (abs(expectedScholarship - actualScholarship) < 1e-6) {
        cout << "  Passed: Scholarship calculation is correct.\n";
    } else {
        cout << "  Failed: Scholarship calculation is incorrect.\n";
        cout << "  Expected: $" << expectedScholarship << ", Actual: $" << actualScholarship << "\n";
    }

// Ðåàë³çàö³ÿ êëàñó Transcript
//ôóíêö³ÿ âèâîäó äàíèõ
void Transcript::display() const {
    cout << "Transcript: " << studentName << ", Average Grade: " << averageGrade << "\n";
}
//òåñò àíàëîã³÷íèé òåñòó 1

// Ðåàë³çàö³ÿ êëàñó Profession
//ôóíêö³ÿ âèâîäó äàíèõ
void Profession::display() const {
    cout << "Profession: " << nameProfession << ", Base Rate: $" << baseRate << "\n";
}
//òåñò àíàëîã³÷íèé òåñòó 1


// Ðåàë³çàö³ÿ ôóíêö³¿ printJson
template <typename T>
void printJson(const vector<T*>& vec) {
    for (const auto& obj : vec) {
        cout << "{ ";
        obj->display();
        cout << " },\n";
    }
}






