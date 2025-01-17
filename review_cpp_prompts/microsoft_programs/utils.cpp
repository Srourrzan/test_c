#include "utils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>


std::vector<Employee> readEmployeeData(const std::string& file_name) {
    std::vector<Employee> employees;
    std::ifstream file(file_name);
    std::string line;

    
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Employee emp;
        std::getline(ss, emp.name, ',');
        std::string programs;
        std::getline(ss, programs);

        std::stringstream progStream(programs);
        std::string program;
        while (std::getline(progStream, program, '/')) {
            emp.programs.push_back(program);
        }

        employees.push_back(emp);
    }

    return employees;
}


std::vector<Package> readPackageData(const std::string& file_name) {
    std::vector<Package> packages;
    std::ifstream file(file_name);
    std::string line;

    
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Package pkg;
        std::getline(ss, pkg.package, ',');
        std::string programs;
        std::getline(ss, programs, ',');
        std::getline(ss, programs, ','); // skip price column
        std::getline(ss, programs, ','); // get duration

        std::stringstream progStream(programs);
        std::string program;
        while (std::getline(progStream, program, '/')) {
            pkg.programs_included.push_back(program);
        }

        pkg.price = std::stod(programs); // Get the price as double
        pkg.duration = programs;

        packages.push_back(pkg);
    }

    return packages;
}


std::vector<std::string> findCheapestPlans(const std::vector<Employee>& employees, const std::vector<Package>& packages) {
    std::vector<std::string> results;

    
    for (const auto& employee : employees) {
        double min_cost = std::numeric_limits<double>::infinity();
        std::string best_package;

        
        for (const auto& package : packages) {
            // If all programs the employee needs are included in the package
            bool is_valid = true;
            for (const auto& program : employee.programs) {
                if (std::find(package.programs_included.begin(), package.programs_included.end(), program) == package.programs_included.end()) {
                    is_valid = false;
                    break;
                }
            }

            if (is_valid && package.price < min_cost) {
                min_cost = package.price;
                best_package = package.package;
            }
        }

        if (!best_package.empty()) {
            results.push_back(employee.name + ": " + best_package + " ($" + std::to_string(min_cost) + ")");
        } else {
            results.push_back(employee.name + ": No matching package found.");
        }
    }

    return results;
}