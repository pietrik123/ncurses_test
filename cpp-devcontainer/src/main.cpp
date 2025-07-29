#include <ncurses.h>

int main() {
    initscr();            // Start ncurses mode
    printw("Hello, World!"); // Print Hello, World!
    refresh();           // Refresh the screen to show the output
    getch();            // Wait for user input
    endwin();           // End ncurses mode
    return 0;
}