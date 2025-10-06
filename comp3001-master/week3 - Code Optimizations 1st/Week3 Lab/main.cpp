#include <iostream>
#include <string>

int main() {
    std::cout << "Select a file to run:\n";
    std::cout << "1. multiplication_division.c\n";
    std::cout << "2. pow.c\n";

    int choice;
    std::cin >> choice;

    std::string sourceFile, exeFile, compileCmd, runCmd;
    switch (choice) {
    case 1:
        sourceFile = "multiplication_division.c";
        exeFile = "multiplication_division.exe";
        break;
    case 2:
        sourceFile = "pow.c";
        exeFile = "pow.exe";
        break;
    default:
        std::cout << "Invalid choice.\n";
        return 1;
    }

    // Compile the C file
    compileCmd = "cl /nologo /EHsc " + sourceFile + " /Fe:" + exeFile;
    int compileResult = system(compileCmd.c_str());
    if (compileResult != 0) {
        std::cout << "Compilation failed.\n";
        return 1;
    }

    // Run the executable
    int runResult = system(exeFile.c_str());
    if (runResult != 0) {
        std::cout << "Failed to run " << exeFile << ".\n";
    }

    return 0;
}