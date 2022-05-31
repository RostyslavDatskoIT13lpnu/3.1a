#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>

using namespace std;

enum Spec { CS, IT, ME, PhIT, TR };

string strSpec[] = { "Комп'ютернi науки", "Iнформатика", "Математика та економiка", "Фiзика та iнформатика", "Трудове навчання" };

struct Student {
    string lname;
    int kurs;
    Spec spec;
    int physics;
    int math;
    int progr;
};

void create(Student* s, int amSt);
void print(Student* s, int amSt);
bool check(Student s);
int amount(Student* s, int amSt);
void print_mod(Student* s, int amSt);

int main() {
    setlocale(LC_ALL, "Ukrainian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int n;
    cout << "Кiлькiсть студентiв: ";
    cin >> n;
    Student* stud = new Student[n];
    create(stud, n);
    print(stud, n);
    cout << "Відсоток відмінників:" << (double)amount(stud, n) / n * 100 << "%" << endl;

    print_mod(stud, n);

    return 0;

}

void create(Student* s, int amSt) {
    int sp;
    for (int i = 0; i < amSt; i++) {
        cout << "Прiзвище: ";
        cin >> s[i].lname;
        cout << "Курс: ";
        cin >> s[i].kurs;
        cout << "Спецiальнiсть (0 - Комп'ютернi науки, 1 - Iнформатика, 2 - Математика та економiка, 3 - Фiзика та iнформатика, 4 - Трудове навчання) ";
        cin >> sp;
        s[i].spec = (Spec)sp;
        cout << "Оцiнка з фiзики: ";
        cin >> s[i].physics;
        cout << "Оцiнка з математики: ";
        cin >> s[i].math;
        cout << "Оцiнка з програмування: ";
        cin >> s[i].progr;

    }
}

void print(Student* s, int amSt)
{
    cout << "==========================================================================================="
        << endl;
    cout << "| № |    Прiзвище   | Курс |      Спецiальнiсть     | Фiзика | Математика | Програмування |"
        << endl;
    cout << "-------------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < amSt; i++) {

        cout << "| " << setw(2) << right << i + 1 << "";
        cout << "| " << setw(14) << left << s[i].lname
            << "| " << setw(5) << right << s[i].kurs
            << "| " << setw(23) << left << strSpec[s[i].spec]
            << "| " << setw(7) << s[i].physics
            << "| " << setw(11) << right << s[i].math;
        cout << "| " << setw(14) << right << s[i].progr
            << "| " << setw(16) << right << " "
            << "| " << setw(11) << right << " " << "| ";
        cout << endl;
    }
    cout << "-------------------------------------------------------------------------------------------"
        << endl;
}


int amount(Student* s, int amSt)
{
    int k = 0;
    for (int i = 0; i < amSt; i++) {
        if (check(s[i])) {
            k++;
        }
    }
    return k;
}

void print_mod(Student* s, int amSt)
{
    cout << "==========================================================================================="
        << endl;
    cout << "| № |    Прiзвище   | Курс |      Спецiальнiсть     | Фiзика | Математика | Програмування |"
        << endl;
    cout << "-------------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < amSt; i++) {
        if (s[i].physics > 3) {
            cout << "| " << setw(2) << right << i + 1 << "";
            cout << "| " << setw(14) << left << s[i].lname
                << "| " << setw(5) << right << s[i].kurs
                << "| " << setw(23) << left << strSpec[s[i].spec]
                << "| " << setw(7) << s[i].physics
                << "| " << setw(11) << right << s[i].math;
            cout << "| " << setw(14) << right << s[i].progr
                << "| " << setw(16) << right << " "
                << "| " << setw(11) << right << " " << "| ";
            cout << endl;
        }
    }
    cout << "-------------------------------------------------------------------------------------------"
        << endl;
}

bool check(Student s) {
    if (s.math > 3 && s.physics > 3 && s.progr > 3) {
        return true;
    }
    else {
        return false;
    }
}
