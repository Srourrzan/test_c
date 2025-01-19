#include "utils.h"

float calculateTicketPrice(int age, float basePrice) 
{
    if (age < CHILD_AGE) {
        return basePrice * (1 - CHILD_DISCOUNT);  
    } else if (age > SENIOR_AGE) {
        return basePrice * (1 - SENIOR_DISCOUNT); 
    } else {
        return basePrice; 
    }
}

void cleanup_passengers(passenger_t *passengers, int count) 
{
    for (int i = 0; i < count; i++)
        free(passengers[i].name);
}

int ft_write_to_system(passenger_t *passenger, route_t *route, int num_passengers) {
    int fd;
    char buffer[256];

    fd = open("data.txt", O_CREAT | O_WRONLY | O_APPEND, 0777);
    if (fd < 0) 
    {
        perror("Failed to open data.txt");
        return -1;
    }
    printf("\nPassenger List:\n");
    for (int i = 0; i < num_passengers; i++) 
    {
        printf("Name: %s, Age: %d, Route: %s, Ticket Price: %.2f\n",
               passenger[i].name, passenger[i].age, 
               route[passenger[i].routeIndex].name, 
               passenger[i].ticketPrice);
        snprintf(buffer, sizeof(buffer), 
                "Name: %s, Age: %d, Route: %s, Ticket Price: %.2f\n",
                passenger[i].name, passenger[i].age,
                route[passenger[i].routeIndex].name,
                passenger[i].ticketPrice);
        write(fd, buffer, strlen(buffer));
    }
    close(fd);
    return 0;
}

int main() {
    passenger_t passengers[MAX_PASSENGERS];
    route_t routes[MAX_ROUTES] = {
        {"Route 1", 50.0},
        {"Route 2", 75.0},
        {"Route 3", 100.0}
    };
    int numPassengers = 0;
    float totalEarnings = 0;
    char choice;
    char name[50];
    char *temp_name;

    do {
        if (numPassengers >= MAX_PASSENGERS) 
        {
            printf("Maximum passenger limit reached.\n");
            break;
        }
        printf("\nEnter passenger name: ");
        if (scanf("%49s", name) != 1) 
        {
            printf("Invalid input for name.\n");
            while (getchar() != '\n');
            continue;
        }
        temp_name = strdup(name);
        if (!temp_name) 
        {
            perror("Memory allocation failed");
            cleanup_passengers(passengers, numPassengers);
            exit(1);
        }
        passengers[numPassengers].name = temp_name;
        printf("Enter passenger age (0-120): ");
        if (scanf("%d", &passengers[numPassengers].age) != 1 ||
            passengers[numPassengers].age < 0 || 
            passengers[numPassengers].age > 120) 
        {
            printf("Invalid age input.\n");
            free(temp_name);
            while (getchar() != '\n');
            continue;
        }
        printf("Available routes:\n");
        for (int i = 0; i < MAX_ROUTES; i++)
        {
            printf("%d. %s (Base Price: $%.2f)\n", 
                   i + 1, routes[i].name, routes[i].basePrice);
        }
        printf("Select the route number: ");
        if (scanf("%d", &passengers[numPassengers].routeIndex) != 1) 
        {
            printf("Invalid route input.\n");
            free(temp_name);
            while (getchar() != '\n');
            continue;
        }
        passengers[numPassengers].routeIndex--;
        if (passengers[numPassengers].routeIndex < 0 || 
            passengers[numPassengers].routeIndex >= MAX_ROUTES) 
        {
            printf("Invalid route selection. Try again.\n");
            free(temp_name);
            continue;
        }
        passengers[numPassengers].ticketPrice = calculateTicketPrice(
            passengers[numPassengers].age,
            routes[passengers[numPassengers].routeIndex].basePrice
        );
        totalEarnings += passengers[numPassengers].ticketPrice;
        printf("Ticket price for %s: %.2f\n", 
               passengers[numPassengers].name,
               passengers[numPassengers].ticketPrice);
        numPassengers++;
        printf("Do you want to add another passenger? (y/n): ");
        while (getchar() != '\n');
        scanf(" %c", &choice);
        
    } while (choice == 'y' || choice == 'Y');
    if (ft_write_to_system(passengers, routes, numPassengers) < 0) {
        printf("Failed to write passenger data to file.\n");
    }
    printf("\nTotal Daily Earnings: %.2f\n", totalEarnings);
    cleanup_passengers(passengers, numPassengers);
    return 0;
}