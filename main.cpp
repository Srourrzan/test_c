#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct PointData {
    double x, y, z;
    double intensity;
    int classification;
    int red, green, blue;
};

std::vector<PointData> loadCSVData(const std::string& filename) {
    std::vector<PointData> points;
    std::ifstream file(filename);
    std::string line;
    std::getline(file, line); // تجاوز عنوان الأعمدة

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        PointData point;
        std::string temp;
        
        std::getline(ss, temp, ','); point.x = std::stod(temp);
        std::getline(ss, temp, ','); point.y = std::stod(temp);
        std::getline(ss, temp, ','); point.z = std::stod(temp);
        std::getline(ss, temp, ','); point.intensity = std::stod(temp);
        std::getline(ss, temp, ','); point.classification = std::stoi(temp);
        std::getline(ss, temp, ','); point.red = std::stoi(temp);
        std::getline(ss, temp, ','); point.green = std::stoi(temp);
        std::getline(ss, temp, ','); point.blue = std::stoi(temp);

        points.push_back(point);
    }

    return points;
}

void calculateGrowthRate(const std::vector<PointData>& points) {
    if (points.empty()) return;
    
    double initialZ = points.front().z;
    double finalZ = points.back().z;
    double growthRate = (finalZ - initialZ) / points.size();
    
    std::cout << "Average Growth Rate: " << growthRate << " meters per point" << std::endl;
}

void calculateWaterAvailability(const std::vector<PointData>& points) {
    double totalIntensity = 0.0;
    for (const auto& point : points) {
        totalIntensity += point.intensity;
    }
    double averageIntensity = totalIntensity / points.size();
    
    std::cout << "Average Water Availability Intensity: " << averageIntensity << std::endl;
}

int main() {
    std::vector<PointData> points = loadCSVData("lidar_data.csv");

    calculateGrowthRate(points);
    calculateWaterAvailability(points);

    return 0;
}