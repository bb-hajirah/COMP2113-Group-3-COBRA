#include "fileio.h"
#include <iostream>
#include <fstream>

void FileIO::saveHighScores(int* scores, int size, const std::string& filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (int i = 0; i < size; ++i) {
            outFile << scores[i] << std::endl; // Save each score on a new line
        }
        outFile.close();
        std::cout << "High scores saved to " << filename << std::endl;
    } else {
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
    }
}

int* FileIO::loadHighScores(const std::string& filename, int& size) {
    int* scores = nullptr;
    size = 0; // Initialize size

    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        int score;
        int capacity = 10; // Initial capacity for dynamic array
        scores = new int[capacity]; // Allocate initial memory

        while (inFile >> score) {
            if (size >= capacity) {
                // Resize the array if needed
                capacity *= 2;
                int* newScores = new int[capacity];
                for (int i = 0; i < size; ++i) {
                    newScores[i] = scores[i]; // Copy old scores
                }
                delete[] scores; // Free old memory
                scores = newScores; // Point to new array
            }
            scores[size++] = score; // Store score and increment size
        }
        inFile.close();
        std::cout << "High scores loaded from " << filename << std::endl;
    } else {
        std::cerr << "Unable to open file for reading: " << filename << std::endl;
    }
    return scores;
}

void FileIO::displayHighScores(int* scores, int size) {
    std::cout << "High Scores:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << scores[i] << std::endl; // Display each score
    }
}
