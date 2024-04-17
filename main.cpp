#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

struct Process {
    string name;
    int priority;
};

// Function to delete a file
void deleteFile(const string& file_name) {
    if (fs::remove(file_name)) {
        cout << "File '" << file_name << "' has been deleted." << endl;
    } else {
        cerr << "Error: Unable to delete file." << endl;
    }
}

// Function to copy a file
void copyFile(const string& source_file, const string& dest_file) {
    if (fs::copy_file(source_file, dest_file, fs::copy_options::overwrite_existing)) {
        cout << "File '" << source_file << "' copied to '" << dest_file << "'." << endl;
    } else {
        cerr << "Error: Unable to copy file." << endl;
    }
}

// Function to update content of a file
void updateFile(const string& file_name, const string& new_content) {
    ofstream file(file_name); // Open the file in truncate mode
    if (file.is_open()) {
        file << new_content;
        cout << "File content updated." << endl;
        file.close();
    } else {
        cerr << "Error: Unable to open file for updating content." << endl;
    }
}

// Function to list files in a directory
void listFiles(const string& directory) {
    for (const auto& entry : fs::directory_iterator(directory)) {
        cout << entry.path() << endl;
    }
}

int main() {
    std::cout << "\n- - - - - -" << std::endl;

    // Define a vector of processes
    vector<Process> processes = {
        {"Process A", 2},
        {"Process B", 1},
        {"Process C", 3}
    };

    // Simulate process scheduling
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.priority < b.priority;
    });

    // Print the scheduled processes
    cout << "Process Scheduling:" << endl;
    for (const Process& process : processes) {
        cout << "Running " << process.name << " (Priority " << process.priority << ")" << endl;
    }

    std::cout << "\n- - - Create/Add File - - -" << std::endl;
    // Create and manipulate files
    string file_name = "input.txt";
    ofstream file(file_name);
    if (file.is_open()) {
        // Write content to the file
        file << "This is a simple file created by a process.";
        file.close();
    }

    // Check if the file exists
    if (fs::exists(file_name)) {
        cout << "File '" << file_name << "' exists." << endl;

        // Read the file
        ifstream file_in(file_name);
        string content;
        getline(file_in, content);
        cout << "File Content: " << content << endl;

        std::cout << "\n- - - Updated File - - -" << std::endl;
        // Update content of the file
        updateFile(file_name, "Updated content.");

        std::cout << "\n- - - Copy File - - -" << std::endl;
        // Copy the file
        copyFile(file_name, "input_copy.txt");

        std::cout << "\n- - - List File - - -" << std::endl;
        // List files in the directory
        cout << "Files in current directory:" << endl;
        listFiles(".");
    }

    std::cout << "\n- - - Delete File - - -" << std::endl;
    // Clean up by deleting the file
    deleteFile(file_name);

    std::cout << "\n- - - - - -" << std::endl;
    // Introduce the concept of system calls
    cout << "System Calls:" << endl;
    cout << "1. Process Creation: The operating system creates and manages processes." << endl;
    cout << "2. File Operations: OS provides APIs for file I/O." << endl;
    cout << "3. File Deletion: OS allows processes to delete files." << endl;
    cout << "4. System Calls: Processes make requests to the OS using system calls." << endl;

    std::cout << "\n- - - - - -" << std::endl;
    // Explain how the OS abstracts hardware
    cout << "Operating System Abstraction:" << endl;
    cout << "The OS abstracts hardware details, providing a uniform interface to processes." << endl;
    cout << "Processes interact with the OS through system calls, which manage resources." << endl;

    std::cout << "\n- - - - - -" << std::endl;
    // Conclude by summarizing the role of an OS
    cout << "In summary, an operating system:" << endl;
    cout << "- Manages processes and scheduling." << endl;
    cout << "- Provides file management and I/O operations." << endl;
    cout << "- Abstracts hardware details for processes." << endl;
    cout << "- Ensures system stability and security." << endl;

    return 0;
}
