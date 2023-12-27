#include <ncurses.h>
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

struct point {
    int x, y;
};

int main() {
    srand(time(0));

    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    timeout(100);

    int maxx, maxy;
    getmaxyx(stdscr, maxy, maxx);

    deque<point> snake;
    snake.push_front({maxx / 2, maxy / 2});

    point food = {rand() % maxx, rand() % maxy};

    int dir = 'd';

    while (true) {
        clear();

        for (auto &p : snake) {
            mvaddch(p.y, p.x, 'O');
        }

        mvaddch(food.y, food.x, 'X');

        int c = getch();

        if (c == 'q') break;
        if (c == ' ') {
            clear();
            mvprintw(maxy / 2, (maxx - 11) / 2, "GAME PAUSED");
            refresh();
            while (true) {
                if (getch() == ' ') break;
            }
            continue;
        }
        if (c == 'w' || c == 's' || c == 'a' || c == 'd') dir = c;

        point np = snake.front();

        switch (dir) {
            case 'w': np.y--; break;
            case 's': np.y++; break;
            case 'a': np.x--; break;
            case 'd': np.x++; break;
        }

        if (np.x < 0) np.x = maxx - 1;
        if (np.y < 0) np.y = maxy - 1;
        if (np.x >= maxx) np.x = 0;
        if (np.y >= maxy) np.y = 0;

        for (auto &p : snake) {
            if (np.x == p.x && np.y == p.y) {
                clear();
                mvprintw(maxy / 2, (maxx - 9) / 2, "GAME OVER"); // 9 is the length of "GAME OVER"
                refresh();
                getch(); // Wait for a key press
                usleep(1000000);
                endwin();
                return 0;
            }
        }

        snake.push_front(np);

        if (np.x == food.x && np.y == food.y) {
            food = {rand() % maxx, rand() % maxy};
        } else {
            snake.pop_back();
        }
    }

    endwin();

    return 0;
}
