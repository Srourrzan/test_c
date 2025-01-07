// As a team manger, I have asked a friend of mine who is a software engineer to implement a program for football game simulation, and predictive analytics. I have little knowledge in coding, my friend sent me the full program but I need more clarification on specific parts of it. Can you help me with understanding the following points?

// • How the function ``` updateStats ``` in the ``` Player``` class  is updating the statistics of a player.

// • Why we are using the ``` totalGames``` variable in the ``` averageTeamPoints ``` methods instead of just using the player's total points.

// • How the game simulation works by the ``` simulateGame``` method in the ```Game``` class.

// • Is using average team points in the ``` predictOutcome``` a good strategy for predicting the outcome of a football game or should we consider other factors?  
 
// Here is the C++ program:-

// ```

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// -------------------- Player Class --------------------
class Player {
public:
    string name;
    string position;
    int points;
    int assists;
    int rebounds;
    int gamesPlayed;

    Player(string name, string position)
        : name(name), position(position), points(0), assists(0), rebounds(0), gamesPlayed(0) {}

    void updateStats(int p, int a, int r) {
        points += p;
        assists += a;
        rebounds += r;
        gamesPlayed++;
    }

    void displayStats() const {
        cout << left << setw(15) << name << setw(12) << position
             << "Points: " << points << ", Assists: " << assists
             << ", Rebounds: " << rebounds << ", Games Played: " << gamesPlayed << endl;
    }

    double averagePoints() const {
        return gamesPlayed > 0 ? static_cast<double>(points) / gamesPlayed : 0;
    }
};

// -------------------- Team Class --------------------
class Team {
public:
    string teamName;
    vector<Player> roster;
    int wins;
    int losses;

    Team(string teamName) : teamName(teamName), wins(0), losses(0) {}

    void addPlayer(const Player& player) {
        roster.push_back(player);
    }

    void displayRoster() const {
        cout << "Team: " << teamName << "\nRoster:\n";
        for (const auto& player : roster) {
            player.displayStats();
        }
    }

    double averageTeamPoints() const {
        double totalPoints = 0;
        int totalGames = 0;
        for (const auto& player : roster) {
            totalPoints += player.points; 
            totalGames += player.gamesPlayed;
        }
        return totalGames > 0 ? totalPoints / totalGames : 0;
    }

    void updateWinLoss(bool won) {
        if (won) wins++;
        else losses++;
    }
};

// -------------------- Game Class --------------------
class Game {
public:
    Team& team1;
    Team& team2;
    int score1;
    int score2;

    Game(Team& t1, Team& t2) : team1(t1), team2(t2), score1(0), score2(0) {}

    void simulateGame() {
        cout << "Simulating game between " << team1.teamName << " and " << team2.teamName << "...\n";

        for (auto& player : team1.roster) {
            int points, assists, rebounds;
            cout << "Enter stats for " << player.name << " (" << player.position << "):\n";
            cout << "Points: ";
            cin >> points;
            cout << "Assists: ";
            cin >> assists;
            cout << "Rebounds: ";
            cin >> rebounds;
            player.updateStats(points, assists, rebounds);
            score1 += points;
        }

        for (auto& player : team2.roster) {
            int points, assists, rebounds;
            cout << "Enter stats for " << player.name << " (" << player.position << "):\n";
            cout << "Points: ";
            cin >> points;
            cout << "Assists: ";
            cin >> assists;
            cout << "Rebounds: ";
            cin >> rebounds;
            player.updateStats(points, assists, rebounds);
            score2 += points;
        }

        cout << "Final Score: " << team1.teamName << " " << score1 << " - " << team2.teamName << " " << score2 << endl;

        if (score1 > score2) {
            cout << team1.teamName << " wins!\n";
            team1.updateWinLoss(true);
            team2.updateWinLoss(false);
        } else {
            cout << team2.teamName << " wins!\n";
            team2.updateWinLoss(true);
            team1.updateWinLoss(false);
        }
    }
};

// -------------------- Predictive Analytics --------------------
class Predictor {
public:
    static string predictOutcome(const Team& team1, const Team& team2) {
        double team1Performance = team1.averageTeamPoints();
        double team2Performance = team2.averageTeamPoints();
        cout << "Predicting game outcome...\n";
        cout << team1.teamName << " Avg Points: " << team1Performance << endl;
        cout << team2.teamName << " Avg Points: " << team2Performance << endl;
        if (team1Performance > team2Performance) {
            return team1.teamName + " is predicted to win!";
        } else if (team2Performance > team1Performance) {
            return team2.teamName + " is predicted to win!";
        } else {
            return "It's a toss-up!";
        }
    }
};

int main() {
    // Input Team Names
    string team1Name, team2Name;
    cout << "Enter name for Team 1: ";
    cin >> team1Name;
    cout << "Enter name for Team 2: ";
    cin >> team2Name;

    Team team1(team1Name);
    Team team2(team2Name);

    // Add Players
    int numPlayers;
    cout << "Enter number of players for each team: ";
    cin >> numPlayers;

    for (int i = 0; i < numPlayers; ++i) {
        string name, position;
        cout << "Enter name and position for player " << i + 1 << " of " << team1Name << ":\n";
        cin >> name >> position;
        team1.addPlayer(Player(name, position));

        cout << "Enter name and position for player " << i + 1 << " of " << team2Name << ":\n";
        cin >> name >> position;
        team2.addPlayer(Player(name, position));
    }

    // Display Rosters
    team1.displayRoster();
    team2.displayRoster();

    // Predict Outcome
    cout << "\n" << Predictor::predictOutcome(team1, team2) << endl;

    // Simulate Game
    Game game(team1, team2);
    game.simulateGame();

    // Display Updated Stats
    cout << "\nUpdated Rosters After Game:\n";
    team1.displayRoster();
    team2.displayRoster();

    return 0;
}


// ```