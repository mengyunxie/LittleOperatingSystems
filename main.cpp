#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    string name;
    int priority;
};

int main() {
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

    // Create and manipulate files
    string file_name = "sample.txt";
    ofstream file(file_name);
    if (file.is_open()) {
        // Write content to the file
        file << "This is a simple file created by a process.";
        file.close();
    }

    // Check if the file exists
    if (ifstream(file_name)) {
        cout << "\nFile '" << file_name << "' exists." << endl;

        // Read the file
        ifstream file_in(file_name);
        string content;
        getline(file_in, content);
        cout << "File Content: " << content << endl;
    }

    // Clean up by deleting the file
    if (remove(file_name.c_str()) == 0) {
        cout << "\nFile '" << file_name << "' has been deleted." << endl;
    }

    // Introduce the concept of system calls
    cout << "\nSystem Calls:" << endl;
    cout << "1. Process Creation: The operating system creates and manages processes." << endl;
    cout << "2. File Operations: OS provides APIs for file I/O." << endl;
    cout << "3. File Deletion: OS allows processes to delete files." << endl;
    cout << "4. System Calls: Processes make requests to the OS using system calls." << endl;

    // Explain how the OS abstracts hardware
    cout << "\nOperating System Abstraction:" << endl;
    cout << "The OS abstracts hardware details, providing a uniform interface to processes." << endl;
    cout << "Processes interact with the OS through system calls, which manage resources." << endl;

    // Conclude by summarizing the role of an OS
    cout << "\nIn summary, an operating system:" << endl;
    cout << "- Manages processes and scheduling." << endl;
    cout << "- Provides file management and I/O operations." << endl;
    cout << "- Abstracts hardware details for processes." << endl;
    cout << "- Ensures system stability and security." << endl;

    
    return 0;
}