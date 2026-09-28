#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

const string USER_FILE = "users.txt";

// Simple educational hash for storing passwords.
// For real applications, use a modern password-hashing algorithm
// such as Argon2, bcrypt, or scrypt with a unique salt.
string hashPassword(const string& password) {
    unsigned long long hash = 1469598103934665603ULL;

    for (unsigned char ch : password) {
        hash ^= ch;
        hash *= 1099511628211ULL;
    }

    return to_string(hash);
}

bool validUsername(const string& username) {
    if (username.length() < 3) return false;

    for (char ch : username) {
        if (!(isalnum(static_cast<unsigned char>(ch)) || ch == '_')) {
            return false;
        }
    }
    return true;
}

bool validPassword(const string& password) {
    return password.length() >= 6;
}

bool usernameExists(const string& username) {
    ifstream file(USER_FILE);
    string storedUsername, storedHash;

    while (file >> storedUsername >> storedHash) {
        if (storedUsername == username) {
            return true;
        }
    }

    return false;
}

void registerUser() {
    string username, password;

    cout << "\n===== REGISTRATION =====\n";
    cout << "Enter username: ";
    cin >> username;

    if (!validUsername(username)) {
        cout << "Invalid username. Use at least 3 characters with letters, numbers, or _.\n";
        return;
    }

    if (usernameExists(username)) {
        cout << "Username already exists. Please choose another username.\n";
        return;
    }

    cout << "Enter password (minimum 6 characters): ";
    cin >> password;

    if (!validPassword(password)) {
        cout << "Password must contain at least 6 characters.\n";
        return;
    }

    ofstream file(USER_FILE, ios::app);

    if (!file) {
        cout << "Error: Could not open user file.\n";
        return;
    }

    file << username << ' ' << hashPassword(password) << '\n';
    file.close();

    cout << "Registration successful!\n";
}

void loginUser() {
    string username, password;
    string storedUsername, storedHash;

    cout << "\n===== LOGIN =====\n";
    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file(USER_FILE);

    if (!file) {
        cout << "No registered users found. Please register first.\n";
        return;
    }

    string enteredHash = hashPassword(password);

    while (file >> storedUsername >> storedHash) {
        if (storedUsername == username && storedHash == enteredHash) {
            cout << "Login successful! Welcome, " << username << ".\n";
            return;
        }
    }

    cout << "Login failed. Invalid username or password.\n";
}

int main() {
    int choice;

    cout << "========================================\n";
    cout << "   CodeAlpha Login & Registration\n";
    cout << "========================================\n";

    do {
        cout << "\n1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter 1, 2, or 3.\n";
            continue;
        }

        switch (choice) {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "Thank you for using the system.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}
