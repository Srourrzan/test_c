#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define CHILD_DISCOUNT 0.5
#define SENIOR_DISCOUNT 0.3
#define CHILD_AGE 12
#define SENIOR_AGE 70
#define MAX_PASSENGERS 100
#define MAX_ROUTES 3 

typedef struct Passenger_s {
    char *name;
    int age;
    int routeIndex; 
    float ticketPrice;
}       passenger_t;

typedef struct Route_s {
    char name[50];
    float basePrice;
}       route_t;

int     ft_write_to_system(passenger_t *passenger, route_t *route, int num_passengers);
void    cleanup_passengers(passenger_t *passengers, int count);
float   calculateTicketPrice(int age, float basePrice);
void	ft_putchar(char ch, int fd);
void	ft_putstr(char *src, int fd);
void	ft_putnbr(int nbr, int fd);
char    *ft_strdup(const char *s);
int     ft_strlen(const char *s);

#endif