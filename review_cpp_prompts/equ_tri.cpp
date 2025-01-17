#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void displayTriangle(vector<vector<int>> &triangle, int currRow, set<pair<int, int>> currPath){
    size_t maxRow = triangle.back().size() * 2 - 1; // Use size_t for unsigned type
    maxRow /= 2;

    for (size_t i = 0; i < triangle.size(); i++) { // Use size_t for loop index
        size_t shift = maxRow - i * 2;
        while (shift--) {
            cout << " ";
        }
        for (size_t j = 0; j < triangle[i].size(); j++) { // Use size_t for loop index
            if ((i <= static_cast<size_t>(currRow) && currPath.count({static_cast<int>(i), static_cast<int>(j)})) || 
                i == static_cast<size_t>(currRow + 1)) {
                cout << triangle[i][j];
            } else {
                cout << "*";
            }
            if (j != triangle[i].size() - 1) {
                cout << "-";
            }
        }
        if (i == static_cast<size_t>(currRow)) {
            cout << "\t<-- You are Here";
        }
        cout << endl;
    }
}

int findLeastCost(vector<vector<int>>& triangle, vector<vector<int>>& memo, int row, int col) {
    if (static_cast<size_t>(row) >= triangle.size()) { // Cast row to size_t for comparison
        return 0;
    }
    if (memo[row][col] != -1) {
        return memo[row][col];
    }
    int first = findLeastCost(triangle, memo, row + 1, col);
    int second = findLeastCost(triangle, memo, row + 1, col + 1);
    int third = findLeastCost(triangle, memo, row + 1, col + 2);
    memo[row][col] = triangle[row][col] + min({first, second, third});
    return memo[row][col];
}

void runGame(vector<vector<int>>& triangle, int leastCost) {
    int currRow = 0, currCol = 0, totalCost = 0;
    set<pair<int, int>> currPath;

    while (static_cast<size_t>(currRow) < triangle.size()) { // Cast currRow to size_t for comparison
        currPath.insert({currRow, currCol});
        totalCost += triangle[currRow][currCol];

        cout << "\nCurrent Location:\nRow = " << currRow << ", Column = " << currCol << endl;
        displayTriangle(triangle, currRow, currPath);

        if (static_cast<size_t>(currRow) == triangle.size() - 1) break; // Cast currRow to size_t for comparison

        cout << "\nSelect the next location (type the index, 0-indexed)" << endl;

        int nextCol;
        cin >> nextCol;

        while (nextCol < currCol || nextCol > currCol + 2 || 
               static_cast<size_t>(nextCol) >= triangle[currRow + 1].size()) { // Cast nextCol to size_t
            cout << "Invalid move! Please select a valid location (0-indexed): " << endl;
            cin >> nextCol;
        }
        currCol = nextCol;
        currRow++;
    }

    displayTriangle(triangle, currRow, currPath);
    cout << "Total Cost: " << totalCost << endl;
    cout << "The least cost possible is: " << leastCost << endl;

    if (totalCost == leastCost) {
        cout << "Congratulations! You achieved the least cost possible!\nWell done!" << endl;
    } else {
        cout << "You did not achieve the least cost possible.\nBetter luck next time." << endl;
    }
}

int main() {
    vector<vector<int>> triangle = {
                      {1},
                   {1, 2, 1},
                 {3, 3, 4, 5, 2},
              {1, 6, 7, 6, 5, 3, 4},
           {1, 6, 7, 6, 5, 3, 4, 4, 3},
        {9, 6, 7, 6, 5, 3, 4, 4, 3, 2, 3}
    };
    vector<vector<int>> memo(triangle.size(), vector<int>(triangle.back().size(), -1));
    int leastCost = findLeastCost(triangle, memo, 0, 0);
    cout << "HINT: The least cost possible is: " << leastCost << endl;
    runGame(triangle, leastCost);
    return 0;
}
