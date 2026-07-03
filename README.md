# Student Management System

A professional C++ project to manage student records with full CRUD operations, file persistence, and input validation.

## Features

✅ **Add Student** - Add new students with automatic duplicate ID detection  
✅ **Display Students** - View all student records in a formatted table  
✅ **Search Student** - Find student by ID  
✅ **Update Student** - Modify student name and marks  
✅ **Delete Student** - Remove student records  
✅ **Data Persistence** - Automatically save and load records from file  
✅ **Input Validation** - Validate IDs, marks range (0-100), and prevent duplicates  
✅ **Menu-Driven Interface** - User-friendly command-line interface  

## Technologies Used

- **Language:** C++11 and above
- **Standard Library:** iostream, vector, fstream, sstream, algorithm, iomanip
- **File Format:** Plain text (pipe-delimited)
- **Compilation:** G++ or any C++ compiler supporting C++11

## Project Structure

```
Student-Management-System/
├── student_management.cpp    # Main program (450+ lines)
├── README.md                 # Project documentation
└── student_data.txt          # Auto-generated data file (on first run)
```

## How to Compile and Run

### Prerequisites
- C++ compiler (G++, Clang, or MSVC)
- Linux/Mac/Windows terminal or IDE

### Compilation

**On Linux/Mac:**
```bash
g++ -std=c++11 student_management.cpp -o student_management
./student_management
```

**On Windows (Command Prompt):**
```bash
g++ -std=c++11 student_management.cpp -o student_management.exe
student_management.exe
```

**Using an IDE:**
- Open `student_management.cpp` in your IDE (Code::Blocks, Dev-C++, Visual Studio)
- Compile and run directly

## Sample Output

```
*** Welcome to Student Management System ***

===== Student Management System =====
1. Add Student
2. Display All Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit
======================================
Enter your choice (1-6): 1

========== Add New Student ==========
Enter Student ID: 101
Enter Student Name: Alice
Enter Marks (0-100): 89.5

[SUCCESS] Student added successfully!

===== Student Management System =====
1. Add Student
2. Display All Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit
======================================
Enter your choice (1-6): 2

========== Student Records ==========
ID        Name                Marks
-----------------------------------------
101       Alice               89.50

===== Student Management System =====
1. Add Student
2. Display All Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit
======================================
Enter your choice (1-6): 6

*** Thank you for using Student Management System ***
```

## Key Features Explained

### 1. **Duplicate ID Validation**
- Prevents adding students with duplicate IDs
- Uses `idExists()` function to check before insertion

### 2. **Marks Validation**
- Ensures marks are within 0-100 range
- Uses `isValidMarks()` function for validation
- Shows error message if invalid input provided

### 3. **File Persistence**
- Automatically saves records to `student_data.txt` after every operation
- Loads existing records when program starts
- Uses pipe (`|`) delimiter for data separation

### 4. **CRUD Operations**
| Operation | Function | Details |
|-----------|----------|---------|
| Create | `addStudent()` | Add new student with validation |
| Read | `displayStudents()` | Show all students in table format |
| Read | `searchStudent()` | Find student by ID |
| Update | `updateStudent()` | Modify name and/or marks |
| Delete | `deleteStudent()` | Remove student record |

### 5. **User-Friendly Interface**
- Clear menu with numbered options
- Formatted table output using `iomanip`
- Status messages ([SUCCESS], [ERROR], [INFO])
- Input buffer clearing to prevent issues

## Code Quality

- **Well-commented** - Every function and section explained
- **Modular Design** - Separate functions for each operation
- **Error Handling** - Validates all user inputs
- **Professional Output** - Formatted with colors/sections
- **Memory Efficient** - Uses vector for dynamic storage
- **File I/O** - Robust file handling with error checking

## Usage Instructions

1. **Start the program** - Run the executable
2. **Select an option** (1-6) from the menu
3. **Follow prompts** - Enter required information
4. **View results** - See success/error messages
5. **Data persists** - Records saved automatically to file
6. **Exit gracefully** - Choose option 6 to exit

## Future Improvements

- 🔄 **Sort & Filter** - Sort students by ID, name, or marks
- 🔐 **Authentication** - Add login system with password protection
- 📊 **Statistics** - Display average marks, highest/lowest scores
- 🎯 **Grades** - Assign letter grades based on marks
- 📅 **Date Tracking** - Track enrollment/update dates
- 🗂️ **Database Integration** - Use SQLite or MySQL instead of text files
- 🖥️ **GUI Interface** - Build desktop UI with Qt or wxWidgets
- 📱 **Web Version** - Create web application with Flask/Django
- 📄 **Export Reports** - Generate PDF/CSV reports
- 🔍 **Advanced Search** - Search by name, marks range, etc.

## Error Handling

The system handles:
- ✓ Duplicate student IDs
- ✓ Invalid marks (outside 0-100 range)
- ✓ Empty student names
- ✓ File I/O errors
- ✓ Invalid menu choices
- ✓ Non-existent student searches

## Testing

Test scenarios included:
```
✓ Add student with valid data
✓ Attempt duplicate ID (should fail)
✓ Add student with invalid marks > 100 (should fail)
✓ Search existing and non-existing students
✓ Update student information
✓ Delete student and verify
✓ Check data persistence after program restart
```

## Portfolio Value

This project demonstrates:
- ✅ Object-Oriented Programming (Classes, Constructors)
- ✅ Data Structures (Vectors, Dynamic Arrays)
- ✅ File Handling (Read/Write operations)
- ✅ Input Validation & Error Handling
- ✅ Standard Library Usage (iostream, fstream, algorithm)
- ✅ Clean Code & Professional Documentation
- ✅ CRUD Operations Implementation
- ✅ Memory Management
- ✅ User Interface Design

## License

This project is free to use and modify for educational purposes.

## Author

Created as a portfolio project for demonstrating C++ skills and software development practices.

---

**Ready to impress recruiters?** This is production-ready code with professional documentation! 🚀
