#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

struct Employee {
    std::string name;
    std::vector<std::string> programs;
};

struct Package {
    std::string package;
    std::vector<std::string> programs_included;
    double price;
    std::string duration;
};


std::vector<Employee> readEmployeeData(const std::string& file_name);
std::vector<Package> readPackageData(const std::string& file_name);
std::vector<std::string> findCheapestPlans(const std::vector<Employee>& employees, const std::vector<Package>& packages);

#endif