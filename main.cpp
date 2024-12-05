main.cpp: “#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include <unistd.h>
#include "environment.h"
#include "game.h"
#include "board.h"

void DrawBorder();
void InitializeGame();
void DisplayMenu();
void printWithDelay(const std::string& message, int delayMs);

void InitializeGame() {
    // Color pairs
    init_pair(1, COLOR_YELLOW, COLOR_BLACK); // Border color
    init_pair(2, COLOR_GREEN, COLOR_BLACK);  // Snake color
    init_pair(3, COLOR_RED, COLOR_BLACK);    // Apple color
    init_pair(4, COLOR_YELLOW, COLOR_BLACK); // Banana color
    init_pair(5, COLOR_CYAN, COLOR_BLACK);   // Orange color
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK); // Chocolate color
    init_pair(7, COLOR_WHITE, COLOR_BLACK);   // Ice cream color
}

void DrawBorder() {
    int height, width;
    getmaxyx(stdscr, height, width); // Get screen dimensions
    attron(COLOR_PAIR(1)); // Set border color
    for (int i = 0; i < width; i++) {
        mvaddch(0, i, '*'); // Top border
        mvaddch(height - 1, i, '*'); // Bottom border
    }
    for (int i = 0; i < height; i++) {
        mvaddch(i, 0, '*'); // Left border
        mvaddch(i, width - 1, '*'); // Right border
    }
    attroff(COLOR_PAIR(1));
}

void printWithDelay(const std::string& message, int delayMs) {
    for (char ch : message) {
        printw("%c", ch);
        refresh();
        napms(delayMs); // Wait for specified milliseconds
    }
}

void DisplayMenu() {
    int choice;
    while (true) {
        clear();
        DrawBorder(); // Draw the border

        // Color for the title
        attron(COLOR_PAIR(5));
        mvprintw(1, 2, "*       * ** *      **   **   * *    * **      **   **          **   **   **   **    *       *        *");
        mvprintw(2, 2, "*       * *    *     *      *    *  *  * *  * *           *    *    *        *      *    *  *    *  *    *  *   *      *        *");
        mvprintw(3, 2, "*   *   * ** *    *      *      * *   *   * **        *   *      *      *      *      * **   **  ***  ***  ***");
        mvprintw(4, 2, "*  * *  * *    *     *      *    *  *       * *           *    *    *        *      *    *  *    *  *   *  *     *     *        *");
        mvprintw(5, 2, "* *   * * ** **  **   **   *       * **        *     **          **   **   **   *    * *     *     *        *");
        attroff(COLOR_PAIR(5));

        // Space
        printw("\n");

        // Menu colors
        attron(COLOR_PAIR(6));
        mvprintw(7, 2, "1. Start Game");
        mvprintw(8, 2, "2. Story");
        mvprintw(9, 2, "3. Instructions");
        mvprintw(10, 2, "4. Exit");
        attroff(COLOR_PAIR(6));

        mvprintw(12, 2, "Choose an option: ");
        refresh();

        choice = getch(); // Get user input

        switch (choice) {
            case '1':
                return; // Start the game
            case '2':
                clear();
                printWithDelay("Once upon a time in a colorful garden, a little snake named Cobra wanted to grow longer and stronger.\n", 50);
                printWithDelay("He discovered that by eating healthy fruits like apples, bananas, and oranges, he could grow bigger and faster.\n", 50);
                printWithDelay("Each fruit he ate made him feel energized and happy.\n", 50);
                printWithDelay("Cobra learned that healthy foods help him play better and feel great!\n", 50);
                printWithDelay("HOWEVER!!\n", 50); // Added delay
                printWithDelay("Once he eats junk food like chocolate or ice cream, he grows shorter and feels weaker.\n", 50);
                printWithDelay("So....\n", 50); // Added delay
                printWithDelay("he encouraged all his friends to munch on delicious fruits too, showing them that eating healthy is not just good for growing,\n", 50);
                printWithDelay("but also super fun!\n", 50);
                printWithDelay("Avoid hitting your own tail if you want to grow longer!\n", 50);
                printWithDelay("Press any key to return to the menu...\n", 50);
                getch();
                break;
            case '3':
                clear();
                printWithDelay("Instructions:\n", 50);
                printWithDelay("Use the arrow keys to move the snake.\n", 50);
                printWithDelay("Eat healthy fruits (A = Apple, B = Banana, O = Orange) to score points and increase your tail length.\n", 50);
                printWithDelay("DON'T eat junk food (C = Chocolate, I = Ice Cream).\n", 50);
                printWithDelay("Avoid colliding with yourself.\n", 50);
                printWithDelay("Press 'q' to quit the game at any time.\n", 50);
                printWithDelay("Press any key to return to the menu...\n", 50);
                getch();
                break;
            case '4':
                endwin(); // End ncurses mode
                exit(0); // Exit the program
            default:
                break;
        }
    }
}


int main() {
    initscr();          // Start ncurses mode
    noecho();           // Don't echo pressed keys
    cbreak();           // Disable line buffering
    curs_set(0);        // Hide the cursor
    start_color();      // Enable color functionality
    InitializeGame();
    DisplayMenu();

    init_color(COLOR_BLUE, 0, 0, 700);
    init_pair(1, COLOR_BLUE, COLOR_BLACK); // Border color
    init_pair(2, COLOR_GREEN, COLOR_GREEN);  // Snake color
    init_pair(3, COLOR_RED, COLOR_BLACK);    // Apple color
    init_pair(4, COLOR_YELLOW, COLOR_BLACK); // Banana color
    init_color(COLOR_CYAN, 700, 400, 0);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);   // Orange color
    #define COLOR_BROWN 8
    init_color(COLOR_BROWN, 400, 200, 0); // RGB values for brown
    init_pair(6, COLOR_BROWN, COLOR_BLACK);// Chocolate color
    init_pair(7, COLOR_MAGENTA, COLOR_BLACK);  // Ice cream color
    Board board(width, height);
    Setup();

    int baseDelay = 100000;  // Initial delay in microseconds
    int delay;
    double speedFactor = 1.0; // Initial speed factor

    while (!gameOver) {
        Draw(board.getWindow());  // Draw the game state
        board.draw();             // Draw the board
        board.drawScore(score);   // Draw the score

        Input();
        Logic();

        // Calculate the delay based on the score
        speedFactor = 1.0 + (score / 100) * 0.2; // Increase speed factor for every 100 points
        delay = baseDelay / speedFactor; // Adjust delay based on speed factor
        if (delay < 20000) delay = 20000; // Minimum delay to avoid too fast gameplay

        usleep(delay);  // Sleep to control speed of the game
    }

    // Clean up: free dynamically allocated memory
    delete[] tailX;
    delete[] tailY;

    endwin();  // End ncurses mode and clean up

    return 0;
}
"
