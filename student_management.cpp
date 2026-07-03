#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
using namespace std;

// Student class to store student information
class Student {
public:
    int id;
    string name;
    float marks;

    // Constructor
    Student(int i, string n, float m) {
        id = i;
        name = n;
        marks = m;
    }

    // Default constructor for file operations
    Student() : id(0), name(""), marks(0.0) {}
};

// Global vector to store student records
vector<Student> students;
const string DATA_FILE = "student_data.txt";

// Function prototypes
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void saveToFile();
void loadFromFile();
void displayMenu();

// Validate if ID already exists
bool idExists(int id) {
    for (const auto &s : students) {
        if (s.id == id) {
            return true;
        }
    }
    return false;
}

// Validate marks range (0-100)
bool isValidMarks(float marks) {
    return marks >= 0.0 && marks <= 100.0;
}

// Function to add a new student
void addStudent() {
    cout << "\n========== Add New Student ==========\n";
    
    int id;
    cout << "Enter Student ID: ";
    cin >> id;

    // Check for duplicate ID
    if (idExists(id)) {
        cout << "\n[ERROR] Student with ID " << id << " already exists!\n";
        return;
    }

    cin.ignore(); // Clear input buffer
    string name;
    cout << "Enter Student Name: ";
    getline(cin, name);

    if (name.empty()) {
        cout << "\n[ERROR] Name cannot be empty!\n";
        return;
    }

    float marks;
    cout << "Enter Marks (0-100): ";
    cin >> marks;

    // Validate marks
    if (!isValidMarks(marks)) {
        cout << "\n[ERROR] Marks must be between 0 and 100!\n";
        return;
    }

    students.push_back(Student(id, name, marks));
    cout << "\n[SUCCESS] Student added successfully!\n";
    saveToFile();
}

// Function to display all students
void displayStudents() {
    cout << "\n========== Student Records ==========\n";
    
    if (students.empty()) {
        cout << "[INFO] No student records found!\n";
        return;
    }

    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Marks" << endl;
    cout << "-----------------------------------------\n";

    for (const auto &s : students) {
        cout << left << setw(10) << s.id << setw(20) << s.name << setw(10) << fixed << setprecision(2) << s.marks << endl;
    }
    cout << endl;
}

// Function to search for a student by ID
void searchStudent() {
    cout << "\n========== Search Student ==========\n";
    
    int id;
    cout << "Enter Student ID to search: ";
    cin >> id;

    for (const auto &s : students) {
        if (s.id == id) {
            cout << "\n[FOUND] Student Details:\n";
            cout << "ID: " << s.id << endl;
            cout << "Name: " << s.name << endl;
            cout << "Marks: " << fixed << setprecision(2) << s.marks << endl;
            return;
        }
    }

    cout << "\n[ERROR] Student with ID " << id << " not found!\n";
}

// Function to update student information
void updateStudent() {
    cout << "\n========== Update Student ==========\n";
    
    int id;
    cout << "Enter Student ID to update: ";
    cin >> id;

    for (auto &s : students) {
        if (s.id == id) {
            cout << "\nCurrent Details:\n";
            cout << "Name: " << s.name << endl;
            cout << "Marks: " << fixed << setprecision(2) << s.marks << endl;

            cin.ignore(); // Clear input buffer
            string newName;
            cout << "\nEnter new name (or press Enter to keep current): ";
            getline(cin, newName);

            if (!newName.empty()) {
                s.name = newName;
            }

            cout << "Enter new marks (0-100) (or enter -1 to keep current): ";
            float newMarks;
            cin >> newMarks;

            if (newMarks != -1) {
                if (!isValidMarks(newMarks)) {
                    cout << "\n[ERROR] Marks must be between 0 and 100!\n";
                    return;
                }
                s.marks = newMarks;
            }

            cout << "\n[SUCCESS] Student updated successfully!\n";
            saveToFile();
            return;
        }
    }

    cout << "\n[ERROR] Student with ID " << id << " not found!\n";
}

// Function to delete a student
void deleteStudent() {
    cout << "\n========== Delete Student ==========\n";
    
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            cout << "\n[CONFIRM] Deleting student: " << it->name << " (ID: " << id << ")\n";
            students.erase(it);
            cout << "[SUCCESS] Student deleted successfully!\n";
            saveToFile();
            return;
        }
    }

    cout << "\n[ERROR] Student with ID " << id << " not found!\n";
}

// Function to save records to file
void saveToFile() {
    ofstream file(DATA_FILE);

    if (!file.is_open()) {
        cout << "\n[ERROR] Could not open file for writing!\n";
        return;
    }

    for (const auto &s : students) {
        file << s.id << "|" << s.name << "|" << fixed << setprecision(2) << s.marks << "\n";
    }

    file.close();
}

// Function to load records from file
void loadFromFile() {
    ifstream file(DATA_FILE);

    if (!file.is_open()) {
        // File doesn't exist yet, which is fine for first run
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int id;
        string name;
        float marks;
        char delimiter;

        if (ss >> id >> delimiter && getline(ss, name, '|') && ss >> marks) {
            students.push_back(Student(id, name, marks));
        }
    }

    file.close();
}

// Function to display menu
void displayMenu() {
    cout << "\n===== Student Management System =====\n";
    cout << "1. Add Student\n";
    cout << "2. Display All Students\n";
    cout << "3. Search Student\n";
    cout << "4. Update Student\n";
    cout << "5. Delete Student\n";
    cout << "6. Exit\n";
    cout << "======================================\n";
    cout << "Enter your choice (1-6): ";
}

// Main function
int main() {
    loadFromFile(); // Load records from file at startup

    int choice;
    bool running = true;

    cout << "\n*** Welcome to Student Management System ***\n";

    while (running) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                cout << "\n*** Thank you for using Student Management System ***\n";
                running = false;
                break;
            default:
                cout << "\n[ERROR] Invalid choice! Please enter a number between 1 and 6.\n";
        }
    }

    return 0;
}
