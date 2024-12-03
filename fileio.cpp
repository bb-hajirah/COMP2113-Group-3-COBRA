#include "fileio.h"
#include <iostream>
#include <fstream>

// save the high scores to a specified file
void FileIO::saveHighScores(int* scores, int size, const std::string& filename) {
    // open the file for writing
    std::ofstream outFile(filename); 
    if (outFile.is_open()) { // file successfully opened?
        for (int i = 0; i < size; ++i) {
            outFile << scores[i] << std::endl; // Save each score on a new line
        }
        outFile.close();
        std::cout << "High scores saved to " << filename << std::endl;
    } else {
        std::cerr << "Unable to open file for writing: " << filename << std::endl; // error msg
    }
}

// load the high scores from a specified file
int* FileIO::loadHighScores(const std::string& filename, int& size) {
    int* scores = nullptr; // initialise pointer for scores
    size = 0; // Initialize size

    // open file for reading
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        int score; // variable to hold each score readd from the file
        int capacity = 10; // Initial capacity for dynamic array
        scores = new int[capacity]; // Allocate initial memory for scores

        // read scores from the file
        while (inFile >> score) {
            if (size >= capacity) {
                // Resize the array if needed
                capacity *= 2;
                int* newScores = new int[capacity]; // allocate new larger array
                for (int i = 0; i < size; ++i) {
                    newScores[i] = scores[i]; // Copy old scores
                }
                delete[] scores; // Free old memory to prevent memory leak
                scores = newScores; // Point to new array
            }
            scores[size++] = score; // Store score and increment size
        }
        inFile.close();
        std::cout << "High scores loaded from " << filename << std::endl;
    } else {
        std::cerr << "Unable to open file for reading: " << filename << std::endl; // error msg
    }
    return scores;
}

// display high scores to the console
void FileIO::displayHighScores(int* scores, int size) {
    std::cout << "High Scores:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << scores[i] << std::endl; // Display each score
    }
}
