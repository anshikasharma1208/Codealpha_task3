#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib> 

using namespace std;

void listDirectory() {
    system("dir /b");
}

// Contents of a file
void viewFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        cout << "Contents of " << filename << ":\n";
        string line;
        while (getline(file, line)) {
            cout << line << '\n';
        }
        file.close();
    } else {
        cout << "Unable to open file: " << filename << '\n';
    }
}

// Creating a new directory
void createDirectory(const string& dirname) {
    string command = "mkdir " + dirname;
    if (system(command.c_str()) == 0) {
        cout << "Directory created: " << dirname << '\n';
    } else {
        cout << "Failed to create directory: " << dirname << '\n';
    }
}

// Copy a file
void copyFile(const string& source, const string& destination) {
    string command = "copy " + source + " " + destination;
    if (system(command.c_str()) == 0) {
        cout << "File copied: " << source << " -> " << destination << '\n';
    } else {
        cout << "Failed to copy file: " << source << '\n';
    }
}

// Move a file
void moveFile(const string& source, const string& destination) {
    string command = "move " + source + " " + destination;
    if (system(command.c_str()) == 0) {
        cout << "File moved: " << source << " -> " << destination << '\n';
    } else {
        cout << "Failed to move file: " << source << '\n';
    }
}

int main() {
    cout << "Welcome to the Command-line File Manager!\n";

    while (true) {
        cout << "\nOptions:\n";
        cout << "1. List files and directories\n";
        cout << "2. View file contents\n";
        cout << "3. Create directory\n";
        cout << "4. Copy file\n";
        cout << "5. Move file\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                listDirectory();
                break;
            case 2: {
                cout << "Enter filename to view: ";
                string filename;
                cin >> filename;
                viewFile(filename);
                break;
            }
            case 3: {
                cout << "Enter directory name to create: ";
                string dirname;
                cin >> dirname;
                createDirectory(dirname);
                break;
            }
            case 4: {
                cout << "Enter source file name: ";
                string source;
                cin >> source;
                cout << "Enter destination file name: ";
                string destination;
                cin >> destination;
                copyFile(source, destination);
                break;
            }
            case 5: {
                cout << "Enter source file name: ";
                string source;
                cin >> source;
                cout << "Enter destination file name: ";
                string destination;
                cin >> destination;
                moveFile(source, destination);
                break;
            }
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 6.\n";
        }
    }

    return 0;
}
