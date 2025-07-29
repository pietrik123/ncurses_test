#include <ncurses.h>
#include <unistd.h>
#include <vector>
#include <utility>

const int getch_timeout_ms = 10;
const int delay_between_cycles_us = 30'000; // 100ms

// Function declarations
void init_ncurses();
void cleanup_ncurses();
void handle_key_input(int& pos_x, int& pos_y, bool& exit);
void limit_player_movement(int& pos_x, int& pos_y, int max_x, int max_y);
void display(int x_pos, int y_pos, const std::vector<std::pair<int, int>>& trees_positions,
             int score, int max_pos_x, int max_pos_y);

int main() {

    init_ncurses(); // Initialize ncurses

    bool exit = false; // Flag to control the main loop

    // player position
    int x_pos = 0;
    int y_pos = 0;
    getmaxyx(stdscr, y_pos, x_pos); // Get the size of the window
    
    // max screen coords
    const int max_pos_x = x_pos;
    const int max_pos_y = y_pos;

    // center player position
    y_pos /= 2;
    x_pos /= 2;

    std::vector<std::pair<int, int>> trees_positions
    {
        {max_pos_y / 4, max_pos_x / 4},
        {3*max_pos_y / 4, 3*max_pos_x / 4}
    };

    int score = 0;

    // main loop
    while (!exit)
    {
        handle_key_input(x_pos, y_pos, exit);
        limit_player_movement(x_pos, y_pos, max_pos_x, max_pos_y);

        display(x_pos, y_pos, trees_positions, score, max_pos_x, max_pos_y);
        
        usleep(delay_between_cycles_us);
    } 
    
    cleanup_ncurses();
    return 0;
}

// Function definitions
void init_ncurses()
{
    initscr(); // Initialize ncurses
    cbreak(); // Disable line buffering
    noecho(); // Don't echo input characters
    keypad(stdscr, TRUE); // Enable special keys
    timeout(getch_timeout_ms); // Set a timeout for getch
    curs_set(FALSE); // Hide the cursor

    start_color(); // Start color functionality

    // init color pairs
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
}

void cleanup_ncurses()
{
    endwin(); // End ncurses mode
}

void handle_key_input(int& pos_x, int& pos_y, bool& exit)
{
    int ch = getch(); // Get user input
    switch (ch)
    {
        case 'w':
            pos_y--;
            break;
        case 'a':
            pos_x--;
            break;
        case 's':
            pos_y++;
            break;
        case 'd':
            pos_x++;
            break;
        case 'q':
            exit = true;
            break;
    }
}

void limit_player_movement(int& pos_x, int& pos_y, int max_x, int max_y)
{
    // Prevent going out of bounds
    if (pos_x < 0) pos_x = 0; 
    if (pos_y < 0) pos_y = 0; 
    if (pos_x >= max_x) pos_x = max_x - 1;
    if (pos_y >= max_y) pos_y = max_y - 1;
}

void display(int x_pos, int y_pos, const std::vector<std::pair<int, int>>& trees_positions, int score, int max_pos_x, int max_pos_y)
{
    clear(); // clear the screen

    // display player
    attron(COLOR_PAIR(1));
    mvaddch(y_pos, x_pos, 'O');
    attroff(COLOR_PAIR(1));

    // display trees
    attron(COLOR_PAIR(3));
    for (const auto& tree : trees_positions) {
        mvaddch(tree.first, tree.second, 'T'); // Draw trees
    }
    attroff(COLOR_PAIR(3));

    // display instructions and score
    attron(COLOR_PAIR(2));
    mvprintw(max_pos_y-1, 1, "Use WASD to move and Q to quit");
    mvprintw(max_pos_y-1, max_pos_x/2, "Score: %d", score);
    attroff(COLOR_PAIR(2));

    refresh(); // Refresh the screen to show the output
}
