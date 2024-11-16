#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

enum Specialty { COMPUTER_SCIENCE, INFORMATICS, MATH_ECON, PHYS_INF, LABOR_EDU };
string specialtyStr[] = { "ComScience", "IT", "Math&Econ", "Ph&IT", "Lab Edu" };

struct Student {
    string lastName;
    int course;
    Specialty specialty;
    int physics;
    int math;
    int informatics;
};

void CreateStudents(Student* students, int N) {
    for (int i = 0; i < N; i++) {
        cout << "Enter data for student #" << i + 1 << endl;
        cout << " Last name: "; cin >> students[i].lastName;
        cout << " Course (1-4): "; cin >> students[i].course;
        int spec;
        cout << " Specialty (0 - ComScience, 1 - IT, 2 - Math&Econ, 3 - Ph&IT, 4 - Lab Edu): ";
        cin >> spec;
        students[i].specialty = static_cast<Specialty>(spec);
        cout << " Physics grade: "; cin >> students[i].physics;
        cout << " Math grade: "; cin >> students[i].math;
        cout << " IT grade: "; cin >> students[i].informatics;
        cout << endl;
    }
}

void PrintStudents(const Student* students, int N) {
    cout << "===================================================================" << endl;
    cout << "| No | Last Name  | Course | Specialty | Physics | Math | IT |" << endl;
    cout << "---------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++) {
        cout << "| " << setw(2) << i + 1 << " | "
            << setw(11) << left << students[i].lastName
            << "| " << setw(7) << students[i].course
            << "| " << setw(10) << specialtyStr[students[i].specialty]
            << "| " << setw(8) << students[i].physics
            << "| " << setw(5) << students[i].math
            << "| " << setw(3) << students[i].informatics
            << "|" << endl;
    }

    cout << "===================================================================" << endl;
}
void CountSatisfactoryGrades(const Student* students, int N) {
    int satisfactoryPhysics = 0;
    int satisfactoryMath = 0;
    int satisfactoryIT = 0;

    for (int i = 0; i < N; i++) {
        if (students[i].physics >= 3 && students[i].physics <= 4)
            satisfactoryPhysics++;
        if (students[i].math >= 3 && students[i].math <= 4)
            satisfactoryMath++;
        if (students[i].informatics >= 3 && students[i].informatics <= 4)
            satisfactoryIT++;
    }
   

    cout << "Number of satisfactory grades (3 or 4):" << endl;
    cout << " Physics: " << satisfactoryPhysics << endl;
    cout << " Math: " << satisfactoryMath << endl;
    cout << " IT: " << satisfactoryIT << endl;
}

void PrintHighScoringStudents(const Student* students, int N) {
    cout << "Students with grades 4 or 5 in both Physics and Math:" << endl;
    bool found = false;

    for (int i = 0; i < N; i++) {
        if ((students[i].physics == 4 || students[i].physics == 5) &&
            (students[i].math == 4 || students[i].math == 5)) {
            cout << students[i].lastName << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No students meet this criteria." << endl;
    }
}

int main() {
    int N;
    cout << "Enter the number of students: ";
    cin >> N;

    Student* students = new Student[N];
    CreateStudents(students, N);
    PrintStudents(students, N);

    CountSatisfactoryGrades(students, N);
    PrintHighScoringStudents(students, N);

    delete[] students;
    return 0;
}
