#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Student {
    int id;
    string name;
    float score;
};
vector<Student> students;
int nextId = 1;

void menu() {
    cout << "=======| Student Management |=======" << endl;
    cout << "1. Create Student" << endl;
    cout << "2. Update Student" << endl;
    cout << "3. List all Student" << endl;
    cout << "4. Find student by id" << endl;
    cout << "5. Delete student" << endl;
    cout << "6. Sort student by score" << endl;
    cout << "7. Show passed student(s)" << endl;
    cout << "8. Show failed student(s)" << endl;
    cout << "0. Exit" << endl;
}

void createStudent(){
    string name;
    float score;
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter score: ";
    cin >> score;
    
    Student newStudent = {nextId, name, score};
    students.push_back(newStudent);

    nextId++;
}
void updateStudent(){
    int id{};
    cout << "Enter student id to update: ";
    cin >> id;
    for (size_t i = 0; i < students.size(); i++) {
        if (students.at(i).id == id) {

            cin.ignore();
            cout << "Enter new name: ";
            getline(cin, students.at(i).name);
            cout << "Enter new score: "; 
            cin >> students.at(i).score;

            break;
        }
    }
}

void listAllStudents(){
    system("clear");
    cout << "============| Students |============" << endl;
    cout << left << setw(8) << "ID" << setw(25) << "Name" << setw(15) << "Score" << endl;
    for (const auto &stu : students) {
        cout << left << setw(8) << stu.id << setw(25) << stu.name << setw(15) << stu.score << endl;
    }
}
void findById(){
    system("clear");
    int id{};
    cout << "Enter Student Id: ";
    cin >> id;

    for (size_t i = 0; i < students.size(); i++) {
        if (students.at(i).id == id) {
            cout << "++++++ Student Info" << endl;
            cout << "Student ID: " << students.at(i).id << endl;
            cout << "Student Name: " << students.at(i).name << endl;
            cout << "Student Score: " << students.at(i).score << endl;
            break;
        }
    }
}

void deleteStudent(){
    int id{};
    cout << "Enter student id to delete: ";
    cin >> id;

    for (size_t i = 0; i < students.size(); i++) {
        if (students.at(i).id == id) {
            students.erase(students.begin() + i);
            break;
        }
    }
}

bool compareScoreHighToLow(const Student &stu1, const Student &stu2) {
    return stu1.score > stu2.score;
}
bool compareScoreLowToHigh(const Student &stu1, const Student &stu2) {
    return stu1.score < stu2.score;
}
void sortByScore(){
    char option;
    cout << "Enter 'h' for high to low" << endl;
    cout << "Enter 'l' for low to high" << endl;
    cout << "Choose your option: ";
    cin >> option;
    if (option == 'h') {
        sort(students.begin(), students.end(), compareScoreHighToLow);
        listAllStudents();
    }
    if (option == 'l') {
        sort(students.begin(), students.end(), compareScoreLowToHigh);
        listAllStudents();
    }
}
void showPassedStudents(){
    system("clear");
    cout << "============| Students |============" << endl;
    cout << left << setw(8) << "ID" << setw(25) << "Name" << setw(15) << "Score" << endl;
    for (const auto &stu : students) {
        if (stu.score > 50) {
            cout << left << setw(8) << stu.id << setw(25) << stu.name << setw(15) << stu.score << endl;
        }
    }
}
void showFailedStudents(){
    system("clear");
    cout << "============| Students |============" << endl;
    cout << left << setw(8) << "ID" << setw(25) << "Name" << setw(15) << "Score" << endl;
    for (const auto &stu : students) {
        if (stu.score < 50) {
            cout << left << setw(8) << stu.id << setw(25) << stu.name << setw(15) << stu.score << endl;
        }
    }
}

int main() {
    system("clear");

    while (true) {
        menu();
        int op{};
        cout << "Enter an option: ";
        cin >> op;

        if (op == 0) return 0;

        switch (op) {
            case 1:
                createStudent();
                break;
            case 2:
                updateStudent();
                break;
            case 3:
                listAllStudents();
                break;
            case 4:
                findById();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                sortByScore();
                break;
            case 7:
                showPassedStudents();
                break;
            case 8:
                showFailedStudents();
                break;
            default:
                cout << "Invalid option!" << endl;
                cout << "Try again...." << endl;
        }
    }

    return 0;
}