//Below is a C++ program that manages ATM system records:

#include <iostream>
#include <string>

using namespace std;

const int MAX_CLIENTS = 100; 
const int MAX_ADMINS = 10;  

struct Client {
    int accountNumber;
    string name;
    double balance;
};

struct Admin {
    string username;
    string password;
    bool canAddClients;
    bool canViewClients;
};

int main() {
    Client clients[MAX_CLIENTS];
    int clientCount = 0; 

    Admin admins[MAX_ADMINS] = {
        {"admin1", "pass1", true, true},
        {"admin2", "pass2", false, true}
    }; 

    string username, password;
    bool isAuthenticated = false;
    Admin* currentAdmin = nullptr;

    
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    for (int i = 0; i < MAX_ADMINS; i++) {
        if (admins[i].username == username && admins[i].password == password) {
            isAuthenticated = true;
            currentAdmin = &admins[i];
            break;
        }
    }

    if (!isAuthenticated) {
        cout << "Invalid credentials. Exiting program." << endl;
        return 0;
    }

    cout << "Welcome, " << currentAdmin->username << "!" << endl;

    int choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add Client" << endl;
        cout << "2. View Clients" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (currentAdmin->canAddClients) {
                if (clientCount < MAX_CLIENTS) {
                    cout << "Enter account number: ";
                    cin >> clients[clientCount].accountNumber;
                    cin.ignore(); 
                    cout << "Enter client name: ";
                    getline(cin, clients[clientCount].name);
                    cout << "Enter account balance: ";
                    cin >> clients[clientCount].balance;

                    clientCount++;
                    cout << "Client added successfully!" << endl;
                }
                else {
                    cout << "Client list is full!" << endl;
                }
            }
            else {
                cout << "You do not have permission to add clients." << endl;
            }
            break;

        case 2:
            if (currentAdmin->canViewClients) {
                if (clientCount == 0) {
                    cout << "No clients to display." << endl;
                }
                else {
                    cout << "Client List:" << endl;
                    for (int i = 0; i < clientCount; i++) {
                        cout << "Account Number: " << clients[i].accountNumber
                            << ", Name: " << clients[i].name
                            << ", Balance: " << clients[i].balance << endl;
                    }
                }
            }
            else {
                cout << "You do not have permission to view clients." << endl;
            }
            break;

        case 3:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 3);

    return 0;
}