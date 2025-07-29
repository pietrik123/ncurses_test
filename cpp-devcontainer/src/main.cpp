#include <ncurses.h>
#include <unistd.h>

int main() {
    initscr();            // Start ncurses mode
    cbreak();
    timeout(0); // Set non-blocking input
    noecho();
    keypad(stdscr, TRUE);
    curs_set(FALSE);

    bool exit = false; // Flag to control the main loop

    int x_pos = 0;
    int y_pos = 0;
    getmaxyx(stdscr, y_pos, x_pos); // Get the size of the window
    y_pos /= 2; // Center the y position
    x_pos /= 2; // Center the x position
    
    // main loop

    int cnt=0;
    while (!exit)
    {
        int ch = getch(); // Get user input
        clear();
        mvaddch(y_pos, x_pos, 'O'); // Clear the previous character
        refresh(); // Refresh the screen to show the output
        usleep(100000); // Sleep for 100 milliseconds
        if (cnt++ % 1 == 0)
        {
            x_pos++;
        }
    } 

    // printw("Hello, World!"); // Print Hello, World!
    // refresh();           // Refresh the screen to show the output
    // timeout(2000);
    // getch();            // Wait for user input
    endwin();           // End ncurses mode
    return 0;
}
