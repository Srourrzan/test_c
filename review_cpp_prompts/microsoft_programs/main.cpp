#include <iostream>
#include <vector>
#include "utils.h"

int main() {
    
    std::vector<Employee> employees = readEmployeeData("employee_data.csv");
    std::vector<Package> packages = readPackageData("package_data.csv");

    
    std::vector<std::string> cheapestPlans = findCheapestPlans(employees, packages);

    
    std::cout << "Cheapest Package Options:" << std::endl;
    for (const auto& result : cheapestPlans) {
        std::cout << result << std::endl;
    }

    return 0;
}