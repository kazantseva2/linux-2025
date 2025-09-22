#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


#define DX 3

int main(int argc, char *argv[]) {
        FILE *fp = fopen(argv[1], "r");
        if (!fp) {
            perror("fopen");
            return 1;
        }

        setlocale(LC_ALL, "");
        WINDOW *frame, *win;
        int c = 0;

        initscr();
        noecho();
        cbreak();

        frame = newwin(LINES - 2*DX, COLS - 2*DX, DX, DX);
        box(frame, 0, 0);
        mvwaddstr(frame, 0, (int)((COLS - 2*DX - 5) / 2), argv[1]);
        wrefresh(frame);

        win = newwin(LINES - 2*DX - 2, COLS - 2*DX-2, DX+1, DX+1);
        scrollok(win, TRUE);

        // вывод первых строк файла, те что поместятся
        char line[COLS - 2*DX];
        int row = 0;
        while (fgets(line, sizeof(line), fp)) {
            row++;
            if (row == LINES - 2*DX - 2) {
                break;
            }

            wprintw(win, "%s", line);
        }
        wrefresh(win);

        // ждем действий пользователя
        while ((c = wgetch(win)) != 27) {  // Esc для выхода
            if (c == ' ' && fgets(line, sizeof(line), fp)) {
                wprintw(win, "%s", line);
                // wscrl(win, 1); // прокрутка пробелом
                wrefresh(win);
            }
        }
        fclose(fp);


        delwin(win);
        delwin(frame);
        endwin();

        return 0;
}
