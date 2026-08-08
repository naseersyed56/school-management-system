# School Management System

A **C++ console-based School Management System** designed to manage school branches, student records, and teacher records. The project demonstrates practical use of **Object-Oriented Programming (OOP), STL vectors, file handling, CRUD operations, and input validation**.

## Features

### 🏫 Branch Management

* Add school branches
* View branch details
* Display all branches
* Remove branches
* Select a branch for student and teacher operations

### 👨‍🎓 Student Management

* Add student records
* Generate student IDs
* View individual student details
* Display all student records
* Update student information
* Remove student records
* Store student and parent information
* Store contact details and address

### 👨‍🏫 Teacher Management

* Add teacher records
* Generate teacher IDs
* View individual teacher details
* Display all teacher records
* Update teacher information
* Remove teacher records
* Store subject, age, salary, contact details, address, and joining date

### ✅ Input Validation

* Mobile number validation
* Email address validation
* Validation with limited retry attempts
* Basic input checking before storing records

### 💾 File Handling

The application uses C++ file handling for persistent storage.

```text
students.txt
teachers.txt
branches.txt
```

Student and teacher records are written to and read from text files using C++ file streams.

## OOP Concepts Used

The project is structured around multiple classes:

```text
students
    ↓
teachers
    ↓
branch
    ↓
schools
```

### Classes

**`students`**

Stores student-related information such as:

* Student ID
* Name
* Standard
* Parent details
* Phone numbers
* Email
* Address
* Gender

**`teachers`**

Stores teacher-related information such as:

* Teacher ID
* Name
* Age
* Subject
* Phone number
* Email
* Salary
* Address
* Joining date

**`branch`**

Manages:

* Students
* Teachers
* Branch information
* Student operations
* Teacher operations

The class uses STL vectors to maintain collections of students and teachers.

**`schools`**

Manages multiple school branches and provides operations to add, remove, display, and access branch-level student and teacher management.

## Technologies Used

| Technology       | Usage                        |
| ---------------- | ---------------------------- |
| C++              | Core programming language    |
| OOP              | Class-based system design    |
| STL Vector       | Dynamic record storage       |
| `ifstream`       | Reading data from files      |
| `ofstream`       | Writing data to files        |
| String Handling  | Managing user information    |
| Input Validation | Phone and email validation   |
| File Storage     | Persistent record management |

## CRUD Operations

The project implements the major CRUD operations:

* **Create** — Add students, teachers, and branches
* **Read** — Display and search records
* **Update** — Modify student and teacher information
* **Delete** — Remove students, teachers, and branches

## File Structure

```text
School-Management-System/
│
├── school_management.cpp
├── students.txt
├── teachers.txt
├── branches.txt
└── README.md
```

## How to Run

### 1. Clone the Repository

```bash
git clone <your-repository-url>
```

### 2. Navigate to the Project

```bash
cd School-Management-System
```

### 3. Compile the Program

Using `g++`:

```bash
g++ school_management.cpp -o school_management
```

### 4. Run the Program

Linux/macOS:

```bash
./school_management
```

Windows:

```bash
school_management.exe
```

## Project Workflow

```text
             School
                |
        +-------+-------+
        |       |       |
     Branch 1 Branch 2 Branch 3
        |
   +----+----+
   |         |
Students   Teachers
   |         |
 Add        Add
 View       View
 Update     Update
 Remove     Remove
```

## Learning Outcomes

This project helped me practice and implement:

* C++ Object-Oriented Programming
* Classes and objects
* Encapsulation
* Composition between classes
* STL `vector`
* File input/output
* CRUD operations
* Searching and record management
* String manipulation
* Input validation
* Menu-driven console application design

## Future Improvements

Possible improvements for future versions include:

* Add a complete interactive main menu
* Improve error handling
* Implement stronger input validation
* Improve ID generation and persistence
* Replace text-file storage with MySQL or another database
* Add administrator authentication
* Separate classes into header (`.h`) and implementation (`.cpp`) files
* Add exception handling
* Improve data storage using structured formats
* Develop a graphical or web-based interface

## Author

**Syed Naseer**

**Skills:** C++ | OOP | STL | Data Structures & Algorithms
