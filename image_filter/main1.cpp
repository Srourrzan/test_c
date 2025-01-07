#include <iostream>
#include <opencv4/opencv2.hpp>

using namespace cv;

void applyVintageFilter(Mat& image) {
    // Implement Vintage Filter
    // Sample implementation: Convert image to sepia tone
    cv::transform(image, image, cv::Matx33f(
        0.393f, 0.769f, 0.189f,
        0.349f, 0.686f, 0.168f,
        0.272f, 0.534f, 0.131f
    ));
}

void apply90sFilter(Mat& image) {
    // Implement 90s Photo Filter
    // Sample implementation: Increase contrast and add color cast
    cv::Mat contrastImage;
    cv::convertScaleAbs(image, contrastImage, 1.5, 0);
    cv::addWeighted(image, 0.7, contrastImage, 0.3, 0, image);
}

void applyRetroFilter(Mat& image) {
    // Implement Retro Filter
    // Sample implementation: Apply a warm color tone
    cv::Mat lookupTable(1, 256, CV_8U);
    for (int i = 0; i < 256; i++) {
        lookupTable.at<uchar>(i) = cv::saturate_cast<uchar>(1.5 * i);
    }
    cv::LUT(image, lookupTable, image);
}

int main() {
    std::string imagePath, outputPath, filterName;
    std::cout << "Enter the path to the source photo: ";
    std::cin >> imagePath;

    cv::Mat image = cv::imread(imagePath);
    if (image.empty()) {
        std::cerr << "Error: Unable to read the image file." << std::endl;
        return 1;
    }

    std::cout << "Enter the path where the output file should be saved: ";
    std::cin >> outputPath;

    std::cout << "Available filters: Vintage, 90s, Retro" << std::endl;
    std::cout << "Enter the name of the filter you want to apply: ";
    std::cin >> filterName;

    if (filterName == "Vintage") {
        applyVintageFilter(image);
    } else if (filterName == "90s") {
        apply90sFilter(image);
    } else if (filterName == "Retro") {
        applyRetroFilter(image);
    } else {
        std::cerr << "Error: Invalid filter name." << std::endl;
        return 1;
    }

    cv::imwrite(outputPath, image);
    std::cout << "Filter applied successfully. Output saved to: " << outputPath << std::endl;

    return 0;
}