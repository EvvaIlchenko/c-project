//������ 28.University, ����� ����'������ ���������� 2, ��������.
//�������� ����


#include "28Universityy.h" // ��������� ������������ ���� � ��������
#include <iostream>
#include <fstream>

using namespace std; // ��������� ������ ����

int main(int argc, char *argv[]) {
    // ���� 1: �������� ������� ��������� ���������� �����
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_mode>\n";
        cerr << "   <input_mode>: 1 for console input, 2 for file input\n";
        return 1;
    }

    // ���� 2: ��������, �� ���������� ����������� ��� ����������� �������� ��������� ���������� �����.
    int inputMode = std::atoi(argv[1]); // ������������ ����� �� ���� �����.
    if (inputMode != 1 && inputMode != 2) {
        std::cerr << "Test 2 Failed: Invalid input_mode\n";
        std::cerr << "Usage: " << argv[0] << " <input_mode>\n";
        std::cerr << "   <input_mode>: 1 for console input, 2 for file input\n";
        return 1; // ������� � ����������� ��������.
    }

    // ���� 3: ��������, �� �������� ������ ��������� ��� ���������� ������� ���������.
    std::cout << "Test 3 Passed: Correct usage with input_mode = " << inputMode << "\n";


    // ��������� ������ �������� � ��������� ���������� �����
    int inputMode = atoi(argv[1]);

    vector<Human*> universityMembers;

    if (inputMode == 1) {
        // ����� �������� � ������

        // ��� ����������
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

        // ��� ���������
        cout << "Enter teacher data:\n";
        int degree;
        cout << "Degree: ";
        cin >> degree;

        // ��� ��������
        cout << "Enter student data:\n";
        double averageGrade;
        cout << "averageGrade: ";
        cin >> averageGrade;

        // ��� ��������
        cout << "Enter transcript data:\n";
        string studentName;
        cout << "studentName: ";
        cin >> studentName;

        // ��� ������
        cout << "Enter profession data:\n";
        string nameProfession;
        cout << "name of the profession: ";

        // ����� �������� � ���������� �����
        ifstream inputFile("28University_test.txt.txt");

        // ���� 1: ��������, �� ���������� ��������� �������� �����.
        if (!inputFile.is_open()) {
            cerr << "cannot open 28University_test.txt.txt for reading.\n";
            return 1;
        } else {
        std::cout << "Test 1 Passed: File opened successfully for reading.\n";
    }

        // ���������� ����� � �����
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

        // ���� 2: ��������, �� ���������� ����������� ��� �������, ���� ���� �� ����.
        std::ifstream nonExistentFile("non_existent_file.txt");

    if (!nonExistentFile.is_open()) {
        std::cout << "Test 2 Passed: Cannot open non_existent_file.txt for reading (as expected).\n";
    } else {
        std::cerr << "Test 2 Failed: File non_existent_file.txt opened unexpectedly.\n";
        return 1; // �������: ����, ����� �� ������� ���� ���������, �������.
    }


        //���� ����� �������� �� ������� ������� �� ���������� ������
        // �������� �������� ����������� ��� ������� ����� �������� �� ����������� � ����� ���������� 1
    } else {
        cerr << "Invalid input mode. Use 1 for console input or 2 for file input.\n";
        return 1;
    }
    //���� ����� �������� � ���������� - ���� � ������ json
    cout << "University Members:\n";
    printJson(universityMembers);

    for (auto& member : universityMembers) {
        delete member;//�������� ���'��
    }

    return 0;
}

