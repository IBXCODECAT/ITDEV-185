#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>


/// <summary>
/// Sources students from the console input
/// </summary>f
/// <param name="names"></param>
void fromConsole(std::vector<std::string>& names) {
    int numStudents;
    std::cout << "Enter the number of students (between 1 and 20): ";
    std::cin >> numStudents;

    if (numStudents < 1 || numStudents > 20) {
        std::cout << "Invalid number of students. Exiting.\n";
        return;
    }

    std::cout << "Enter the names of the students:\n";
    names.resize(numStudents);
    for (int i = 0; i < numStudents; ++i) {
        std::cout << "Enter student " << i + 1 << ":";
        std::cin >> names[i];
    }
}

/// <summary>
/// Sources students from input file "students.txt"
/// </summary>
/// <param name="names"></param>
void fromFile(std::vector<std::string>& names) {
    std::ifstream inputFile("students.txt");

    if (!inputFile.is_open()) {
        std::cout << "Unable to open file. Exiting.\n";
        return;
    }

    std::string name;
    while (inputFile >> name) {
        names.push_back(name);
    }

    inputFile.close();
}

/// <summary>
/// Assignment 2
/// Nathan Schmitt
/// ITDEV-185-900
/// </summary>
/// <returns>0</returns>

int main() {
    std::vector<std::string> studentNames;

    char choice;
    std::cout << "Choose input method (C for console, F for file): ";
    std::cin >> choice;

    if (toupper(choice) == 'C') {
        fromConsole(studentNames);
    }
    else if (toupper(choice) == 'F') {
        fromFile(studentNames);
    }
    else {
        std::cout << "Invalid choice. Exiting.\n";
        return 1;
    }

    if (studentNames.empty()) {
        std::cout << "No student names available. Exiting.\n";
        return 1;
    }

    // Display all names from the input
    std::cout << "All student names:\n";
    for (const auto& name : studentNames) {
        std::cout << name << '\n';
    }

    // Sort names and display front and end of the line
    std::sort(studentNames.begin(), studentNames.end());
    std::cout << "Front of the line: " << studentNames.front() << '\n';
    std::cout << "End of the line: " << studentNames.back() << '\n';

    return 0;
}