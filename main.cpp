#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>
#include <filesystem>

namespace fs = std::filesystem;

struct File {
    std::string name;
    std::string content;
};

std::vector<File> files;

void addFile(const std::string& name, const std::string& content) {
    files.push_back({name, content});
    std::cout << "File " << name << " added successfully." << std::endl;
}

void deleteFile(const std::string& name) {
    auto it = std::find_if(files.begin(), files.end(), [&](const File& f) {
        return f.name == name;
    });

    if (it != files.end()) {
        files.erase(it);
        std::cout << "File " << name << " deleted successfully." << std::endl;
    } else {
        std::cout << "File " << name << " not found." << std::endl;
    }
}

void moveFile(const std::string& name, const std::string& destination) {
    auto it = std::find_if(files.begin(), files.end(), [&](const File& f) {
        return f.name == name;
    });

    if (it != files.end()) {
        it->name = destination;
        std::cout << "File " << name << " moved to " << destination << " successfully." << std::endl;
    } else {
        std::cout << "File " << name << " not found." << std::endl;
    }
}

void copyFile(const std::string& name, const std::string& destination) {
    auto it = std::find_if(files.begin(), files.end(), [&](const File& f) {
        return f.name == name;
    });

    if (it != files.end()) {
        files.push_back({destination, it->content});
        std::cout << "File " << name << " copied to " << destination << " successfully." << std::endl;
    } else {
        std::cout << "File " << name << " not found." << std::endl;
    }
}

void findFile(const std::string& name) {
    auto it = std::find_if(files.begin(), files.end(), [&](const File& f) {
        return f.name == name;
    });

    if (it != files.end()) {
        std::cout << "File " << name << " found." << std::endl;
    } else {
        std::cout << "File " << name << " not found." << std::endl;
    }
}

void listFiles() {
    std::cout << "Listing files:" << std::endl;
    for (const auto& file : files) {
        std::cout << "- " << file.name << std::endl;
    }
}

void createDirectory(const std::string& name) {
    if (fs::create_directory(name)) {
        std::cout << "Directory " << name << " created successfully." << std::endl;
    } else {
        std::cout << "Failed to create directory " << name << "." << std::endl;
    }
}

void deleteDirectory(const std::string& name) {
    if (fs::remove(name)) {
        std::cout << "Directory " << name << " deleted successfully." << std::endl;
    } else {
        std::cout << "Failed to delete directory " << name << "." << std::endl;
    }
}

int main() {
    while (true) {
        std::cout << "Choose an operation:\n"
                  << "1. Add a file\n"
                  << "2. Delete a file\n"
                  << "3. Move a file\n"
                  << "4. Copy a file\n"
                  << "5. Find a file\n"
                  << "6. List files\n"
                  << "7. Create directory\n"
                  << "8. Delete directory\n"
                  << "9. Exit\n";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::string name, content;
            std::cout << "Enter file name: ";
            std::cin >> name;
            std::cout << "Enter file content: ";
            std::cin.ignore(); // Ignore newline character left by previous input
            std::getline(std::cin, content);
            addFile(name, content);
        } else if (choice == 2) {
            std::string name;
            std::cout << "Enter file name to delete: ";
            std::cin >> name;
            deleteFile(name);
        } else if (choice == 3) {
            std::string name, destination;
            std::cout << "Enter file name to move: ";
            std::cin >> name;
            std::cout << "Enter destination: ";
            std::cin >> destination;
            moveFile(name, destination);
        } else if (choice == 4) {
            std::string name, destination;
            std::cout << "Enter file name to copy: ";
            std::cin >> name;
            std::cout << "Enter destination: ";
            std::cin >> destination;
            copyFile(name, destination);
        } else if (choice == 5) {
            std::string name;
            std::cout << "Enter file name to find: ";
            std::cin >> name;
            findFile(name);
        } else if (choice == 6) {
            listFiles();
        } else if (choice == 7) {
            std::string name;
            std::cout << "Enter directory name to create: ";
            std::cin >> name;
            createDirectory(name);
        } else if (choice == 8) {
            std::string name;
            std::cout << "Enter directory name to delete: ";
            std::cin >> name;
            deleteDirectory(name);
        } else if (choice == 9) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
