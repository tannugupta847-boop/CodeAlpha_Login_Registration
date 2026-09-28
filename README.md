# CodeAlpha Login and Registration System

## Internship
CodeAlpha C++ Programming Internship

## Task
Task 2 - Login and Registration System

## Description
This C++ console application provides a simple registration and login system.
New users can register with a username and password, and registered users
can log in using their credentials.

## Features
- User registration
- Username validation
- Password validation
- Duplicate username checking
- File-based user storage
- Login verification
- Success and error messages

## Concepts Used
- C++
- Functions
- File handling
- Loops
- Conditional statements
- Strings
- Input validation

## Files
- `main.cpp` - complete C++ source code
- `users.txt` - created automatically when a user registers

## How to Run in VS Code
1. Open this project folder in Visual Studio Code.
2. Open `main.cpp`.
3. Make sure a C++ compiler such as MinGW/g++ is installed.
4. Open the VS Code terminal.
5. Compile:
   `g++ main.cpp -o login`
6. Run on Windows:
   `.\login`

## Example
Choose `1` to register a new account.

Then choose `2` and enter the same username and password to test login.

## Security Note
This project is designed for internship/educational purposes. It stores a
deterministic password hash rather than the plain password. The hashing
function included here is not suitable for production authentication.
Real applications should use a dedicated password-hashing algorithm such
as Argon2, bcrypt, or scrypt with a unique salt.

## Author
Tannu
