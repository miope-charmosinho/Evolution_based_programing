#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    std::string imagePath = "/home/igor/codes/A1_python/coisas/carta_3.jpg";
    cv::Mat image = cv::imread(imagePath, cv::IMREAD_COLOR);
    cv::imshow("name", image);
    cv::waitKey(0);
    return 0;
}

