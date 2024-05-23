#include <iostream>
#include <fstream>
#include <string>

void setFileSize(const std::string& filename, size_t sizeInKB) {
    std::ofstream file(filename, std::ios::binary | std::ios::trunc);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }


    size_t sizeInBytes = sizeInKB * 1024;


    file.seekp(sizeInBytes - 1);
    file.write("", 1);

    if (file.good()) {
        std::cout << "Successfully set the file size to " << sizeInKB << " KB (" << sizeInBytes << " bytes)." << std::endl;
    }
    else {
        std::cerr << "Failed to write to the file: " << filename << std::endl;
    }
}

int main() {
    std::string filename;
    size_t sizeInKB;

    std::cout << "Enter the file: ";
    std::cin >> filename;

    std::cout << "Enter the size in KB: ";
    std::cin >> sizeInKB;

    setFileSize(filename, sizeInKB);

    return 0;
}
