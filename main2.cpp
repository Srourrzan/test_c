#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// وظيفة لقراءة ملف CSV و إرجاع البيانات كنقاط LiDAR
struct LiDARData {
    double x, y, z;
    int intensity;
    int classification;
    int r, g, b;
};

std::vector<LiDARData> read_csv_data(const std::string& filename) {
    std::vector<LiDARData> data;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return data;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        LiDARData point;
        char comma;
        ss >> point.x >> comma >> point.y >> comma >> point.z >> comma 
           >> point.intensity >> comma >> point.classification >> comma 
           >> point.r >> comma >> point.g >> comma >> point.b;

        data.push_back(point);
    }
    file.close();
    return data;
}

// حساب معدل نمو الغابات بناءً على الارتفاعات
double calculate_forest_growth(const std::vector<LiDARData>& data) {
    double growth_sum = 0.0;
    for (size_t i = 1; i < data.size(); ++i) {
        double growth = data[i].z - data[i-1].z;
        if (growth > 0) {
            growth_sum += growth;
        }
    }
    return growth_sum / data.size(); // معدل النمو
}

// حساب توافر المويه بناءً على الشدة
double calculate_water_availability(const std::vector<LiDARData>& data) {
    double intensity_sum = 0.0;
    for (const auto& point : data) {
        intensity_sum += point.intensity;
    }
    return intensity_sum / data.size(); // معدل الشدة والتي هي كمؤشر لتوافر الموية
}

int main() {
    std::string filename = "lidar_data.csv";
    std::vector<LiDARData> lidar_data = read_csv_data(filename);

    if (lidar_data.empty()) {
        std::cerr << "No data to process." << std::endl;
        return 1;
    }

    double forest_growth_rate = calculate_forest_growth(lidar_data);
    double water_availability = calculate_water_availability(lidar_data);

    std::cout << "Forest Growth Rate: " << forest_growth_rate << std::endl;
    std::cout << "Water Availability: " << water_availability << std::endl;

    return 0;
}