#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

// File structure
struct File {
    string name;
    string content;
};

// Directory structure
struct Directory {
    string name;
    vector<File> files;
};

// Function prototypes
void addFile(Directory& dir);
void deleteFile(Directory& dir);
void moveFile(Directory& dir);
void copyFile(Directory& dir);
void findFile(Directory& dir);
void listFiles(Directory& dir);
void createDirectory(Directory& dir);
void deleteDirectory(Directory& dir);

int main() {
    Directory root{"root", {}};
    Directory currentDir = root;

    char choice;
    do {
        cout << "\nmyOS Menu\n";
        cout << "1. Add a file\n";
        cout << "2. Delete a file\n";
        cout << "3. Move a file\n";
        cout << "4. Copy a file\n";
        cout << "5. Find a file\n";
        cout << "6. List files (ls)\n";
        cout << "7. Create a directory\n";
        cout << "8. Delete a directory\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case '1':
                addFile(currentDir);
                break;
            case '2':
                deleteFile(currentDir);
                break;
            case '3':
                moveFile(currentDir);
                break;
            case '4':
                copyFile(currentDir);
                break;
            case '5':
                findFile(currentDir);
                break;
            case '6':
                listFiles(currentDir);
                break;
            case '7':
                createDirectory(currentDir);
                break;
            case '8':
                deleteDirectory(currentDir);
                break;
            case '9':
                cout << "Exiting myOS. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '9');

    return 0;
}

void addFile(Directory& dir) {
    string fileName, fileContent;
    cout << "Enter file name: ";
    getline(cin, fileName);
    cout << "Enter file content: ";
    getline(cin, fileContent);

    File newFile{fileName, fileContent};
    dir.files.push_back(newFile);
    cout << "File added successfully.\n";
}

void deleteFile(Directory& dir) {
    string fileName;
    cout << "Enter file name to delete: ";
    getline(cin, fileName);

    for (auto it = dir.files.begin(); it != dir.files.end(); ++it) {
        if (it->name == fileName) {
            dir.files.erase(it);
            cout << "File deleted successfully.\n";
            return;
        }
    }

    cout << "File not found.\n";
}

void moveFile(Directory& dir) {
    // Implementation left as an exercise
    cout << "Move file functionality not implemented yet.\n";
}

void copyFile(Directory& dir) {
    // Implementation left as an exercise
    cout << "Copy file functionality not implemented yet.\n";
}

void findFile(Directory& dir) {
    string fileName;
    cout << "Enter file name to find: ";
    getline(cin, fileName);

    for (const auto& file : dir.files) {
        if (file.name == fileName) {
            cout << "File found. Content: " << file.content << endl;
            return;
        }
    }

    cout << "File not found.\n";
}

void listFiles(Directory& dir) {
    cout << "Files in directory '" << dir.name << "':\n";
    for (const auto& file : dir.files) {
        cout << file.name << endl;
    }
}

void createDirectory(Directory& dir) {
    string dirName;
    cout << "Enter directory name: ";
    getline(cin, dirName);

    Directory newDir{dirName, {}};
    dir.files.push_back(newDir);
    cout << "Directory created successfully.\n";
}

void deleteDirectory(Directory& dir) {
    // Implementation left as an exercise
    cout << "Delete directory functionality not implemented yet.\n";
}
