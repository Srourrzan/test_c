import curses
import calendar
import datetime
import json

def main(stdscr):
    curses.curs_set(0);  # Hide the cursor
    stdscr.clear();
    
    #Get screen dimensions
    max_y, max_x = stdscr.getmaxyx();
    #Check if the terminal is large enough
    if max_y < 20 or max_x < 40:
        stdscr.addstr(0, 0, "Please resize your terminal to al least 20x40.", curses.A_BOLD);
        stdscr.refresh();
        stdscr.getch();
    # Initial Data
    user_data = {
        "name": "User",
        "full_budget": 0,
        "categories": [],
    };

    # Load saved data if available
    try:
        with open("user_data.json", "r") as f:
            user_data = json.load(f);
    except FileNotFoundError:
        pass;

    # Main UI Loop
    while True:
        stdscr.clear();

        # Display Title
        title = f"{user_data['name']}'s Budget Tracker";
        stdscr.addstr(0, (curses.COLS - len(title)) // 2, title, curses.A_BOLD);

        # Display Full Budget
        stdscr.addstr(2, 2, f"Full Budget: ${user_data['full_budget']:.2f}");

        # Display Categories
        stdscr.addstr(4, 2, "Categories:")
        for idx, cat in enumerate(user_data["categories"], start=1):
            name = cat["name"];
            value = cat["value"];
            spent = cat.get("spent", 0);
            period = cat["period"];
            remaining = value - spent;
            stdscr.addstr(5 + idx, 4, f"{idx}. {name} (${value:.2f} - {period}, Spent: ${spent:.2f}, Remaining: ${remaining:.2f})");

        # Display Calendar
        right_col_start = curses.COLS - 20;
        today = datetime.date.today();
        cal = calendar.TextCalendar();
        cal_str = cal.formatmonth(today.year, today.month);
        for i, line in enumerate(cal_str.splitlines()):
            stdscr.addstr(2 + i, right_col_start, line);

        # Options
        try:
            stdscr.addstr(16, 2, "Options:");
            stdscr.addstr(17, 4, "1. Set Full Budget");
            stdscr.addstr(18, 4, "2. Add/Edit Categories");
            stdscr.addstr(19, 4, "3. Show Bar Chart");
            stdscr.addstr(20, 4, "4. Save and Exit");
        except curses.error:
            raise RuntimeError(f"Failed to write. Terminal size: {max_y}x{max_x}");
            

        # User Input
        stdscr.addstr(22, 2, "Select an option: ");
        stdscr.refresh();
        try:
            choice = stdscr.getkey();
        except Exception:
            continue;

        if choice == "1":
            # Set Full Budget
            try:
                stdscr.addstr(24, 2, "Enter new full budget value: ");
            except curses.error:
                raise RuntimeError(f"Failed to write at (24, 2). Terminal size: {max_y}x{max_x}");
            curses.echo();
            try:
                user_data["full_budget"] = float(stdscr.getstr().decode("utf-8"));
            except ValueError:
                pass
            curses.noecho();

        elif choice == "2":
            # Add/Edit Categories
            stdscr.addstr(24, 2, "Enter number of categories: ")
            curses.echo()
            try:
                num_categories = int(stdscr.getstr().decode("utf-8"));
                user_data["categories"] = [];
                for i in range(num_categories):
                    stdscr.addstr(26 + i * 4, 2, f"Category {i + 1} Name: ");
                    name = stdscr.getstr().decode("utf-8");

                    stdscr.addstr(27 + i * 4, 2, f"Category {i + 1} Value: ");
                    value = float(stdscr.getstr().decode("utf-8"));

                    stdscr.addstr(28 + i * 4, 2, f"Category {i + 1} Period (weekly/monthly): ");
                    period = stdscr.getstr().decode("utf-8");

                    user_data["categories"].append({"name": name, "value": value, "period": period, "spent": 0});
            except ValueError:
                pass
            curses.noecho();

        elif choice == "3":
            # Show Bar Chart
            show_bar_chart(stdscr, user_data);

        elif choice == "4":
            # Save and Exit
            with open("user_data.json", "w") as f:
                json.dump(user_data, f);
            break

        stdscr.refresh();

def show_bar_chart(stdscr, user_data):
    stdscr.clear();
    stdscr.addstr(0, 2, "Bar Chart (Spent vs Remaining)", curses.A_BOLD);

    max_bar_width = curses.COLS - 20;
    for idx, cat in enumerate(user_data["categories"], start=1):
        name = cat["name"];
        value = cat["value"];
        spent = cat.get("spent", 0);
        remaining = value - spent;

        # Spent Bar
        spent_width = int((spent / value) * max_bar_width) if value > 0 else 0;
        spent_bar = "#" * spent_width;
        
        # Remaining Bar
        remaining_width = max_bar_width - spent_width;
        remaining_bar = "-" * remaining_width;

        # Display Bar
        stdscr.addstr(2 + idx, 2, f"{name}: [{spent_bar}{remaining_bar}] {spent:.2f}/{value:.2f}");

    stdscr.addstr(15, 2, "Press any key to return.");
    stdscr.getkey();

if __name__ == "__main__":
    curses.wrapper(main);
