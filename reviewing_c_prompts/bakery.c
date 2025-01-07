// My friend is a beginner programmer. She has a C program that calculates the profitability of a bakery, she asked me to explain it. So, make the code more understandable by adding detailed comments explaining each line of the code and general docstring.
// ```c
#include <stdio.h>

int main() {

    float flourCost, yeastCost, sugarCost;
    float wages, electricity, water;
    float rent, taxes, insurance;
    float totalRevenue;
    
    float productionCost, fixedCosts, profitability;
    
    printf("Enter the cost of flour: ");
    scanf("%f", &flourCost);

    printf("Enter the cost of yeast: ");
    scanf("%f", &yeastCost);

    printf("Enter the cost of sugar: ");
    scanf("%f", &sugarCost);

    printf("Enter the wages of workers: ");
    scanf("%f", &wages);

    printf("Enter the cost of electricity: ");
    scanf("%f", &electricity);

    printf("Enter the cost of water: ");
    scanf("%f", &water);

    
    printf("Enter the bakery rent: ");
    scanf("%f", &rent);

    printf("Enter the taxes: ");
    scanf("%f", &taxes);

    printf("Enter the insurance: ");
    scanf("%f", &insurance);

    printf("Enter the total revenue: ");
    scanf("%f", &totalRevenue);

    productionCost = flourCost + yeastCost + sugarCost + wages + electricity + water;
    fixedCosts = rent + taxes + insurance;

    profitability = totalRevenue - (productionCost + fixedCosts);

    printf("\n--- Profitability Calculation ---\n");
    printf("Total Production Costs: %.2f\n", productionCost);
    printf("Total Fixed Costs: %.2f\n", fixedCosts);
    printf("Total Revenue: %.2f\n", totalRevenue);
    printf("Profitability: %.2f\n", profitability);

    if (profitability > 0) {
        printf("The bakery is profitable!\n");
    } else if (profitability < 0) {
        printf("The bakery is running at a loss.\n");
    } else {
        printf("The bakery is breaking even.\n");
    }

    return 0;
}


// ```