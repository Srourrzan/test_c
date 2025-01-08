#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <time.h>

#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    float value;
    float spent;
    char period[10]; // "weekly" or "monthly"
} BudgetCategory;

void display_calendar(WINDOW *win) {
    time_t now = time(NULL);
    struct tm *local = localtime(&now);

    int year = local->tm_year + 1900;
    int month = local->tm_mon;

    wprintw(win, "  %d/%d\n", month + 1, year);
    wprintw(win, "Su Mo Tu We Th Fr Sa\n");

    struct tm first_day = {0};
    first_day.tm_year = year - 1900;
    first_day.tm_mon = month;
    first_day.tm_mday = 1;
    mktime(&first_day);

    int start_day = first_day.tm_wday;
    int days_in_month = 31;

    
    for (int i = 0; i < start_day; i++) wprintw(win, "   "); 
    for (int i = 1; i <= days_in_month; i++) {
        wprintw(win, "%2d ", i);
        if ((start_day + i) % 7 == 0) wprintw(win, "\n");
    }
    wrefresh(win);
}

void draw_bar_chart(WINDOW *win, BudgetCategory *categories, int num_categories, int show_remaining) {
    wclear(win);
    wprintw(win, "Category        | Bar Chart\n");
    wprintw(win, "---------------------------\n");

    for (int i = 0; i < num_categories; i++) {
        float value = show_remaining ? categories[i].value - categories[i].spent : categories[i].spent;
        wprintw(win, "%-15s | ", categories[i].name);

        int bar_length = value / categories[i].value * 20; // Normalize to 20 chars
        for (int j = 0; j < bar_length; j++) wprintw(win, "#");
        wprintw(win, "\n");
    }
    wrefresh(win);
}

void save_progress(const char *filename, BudgetCategory *categories, int num_categories) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "%d\n", num_categories); // Save the number of categories
    for (int i = 0; i < num_categories; i++) {
        fprintf(file, "%s %.2f %.2f %s\n",
                categories[i].name,
                categories[i].value,
                categories[i].spent,
                categories[i].period);
    }

    fclose(file);
    printw("Progress saved to %s\n", filename);
}

int load_progress(const char *filename, BudgetCategory *categories, int *num_categories) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return 0; // Return 0 if the file doesn't exist
    }

    fscanf(file, "%d\n", num_categories);
    for (int i = 0; i < *num_categories; i++) {
        fscanf(file, "%s %f %f %s\n",
               categories[i].name,
               &categories[i].value,
               &categories[i].spent,
               categories[i].period);
    }

    fclose(file);
    return 1; // Return 1 on successful load
}

int main() {
    BudgetCategory categories[MAX_CATEGORIES];
    int num_categories = 0;
    char user_name[50];

    initscr();
    noecho();
    cbreak();

    // Load saved data
    if (!load_progress("budget_data.txt", categories, &num_categories)) {
        num_categories = 0; // Start fresh if load fails
    }

    // Get user name
    mvprintw(0, 0, "Enter your name: ");
    wgetnstr(stdscr, user_name, sizeof(user_name) - 1);

    // Title
    clear();
    mvprintw(0, 0, "Budget Tracker - %s", user_name);

    // Get categories
    do {
        mvprintw(2, 0, "Enter number of categories (1-%d): ", MAX_CATEGORIES);
        scanw("%d", &num_categories);
    } while (num_categories < 1 || num_categories > MAX_CATEGORIES);

    for (int i = 0; i < num_categories; i++) {
        do {
            mvprintw(3 + i, 0, "Category %d name: ", i + 1);
            wgetnstr(stdscr, categories[i].name, sizeof(categories[i].name) - 1);
        } while (strlen(categories[i].name) == 0);

        do {
            mvprintw(3 + i, 30, "Value: ");
            scanw("%f", &categories[i].value);
        } while (categories[i].value <= 0);
        categories[i].spent = 0; // Initialize spent to zero
    }

    // Save progress before exiting
    save_progress("budget_data.txt", categories, num_categories);

    endwin();
    return 0;
}