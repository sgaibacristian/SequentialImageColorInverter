#include <opencv2/opencv.hpp>
#include <iostream>
#include <ctime>

using namespace std;

void invertColors(cv::Mat& image) {
    // get img. dimensions
    int rows = image.rows;
    int cols = image.cols;

    // read pixels and invert colors
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cv::Vec3b& pixel = image.at<cv::Vec3b>(i, j);
            pixel[0] = 255 - pixel[0]; // blue
            pixel[1] = 255 - pixel[1]; // green
            pixel[2] = 255 - pixel[2]; // red
        }
    }
}

int main() {
    const clock_t start = clock();

    // Image read
    cv::Mat image = cv::imread("input.jpg");

    // Img not empty
    if (image.empty()) {
        cerr << "Could not read the image." << '\n';
        return -1;
    }

    cout << "Image read successfully." << '\n';

    // Invert Colors
    invertColors(image);
    
    const clock_t end = clock();
    const double elapsed_time = double(end - start) / CLOCKS_PER_SEC;
    cout << "Execution time: " << elapsed_time << " seconds." << '\n';

    // Save new inverted image
    cv::imwrite("inverted_image.jpg", image);
    cout << "Inverted image saved successfully." << '\n';

    // display new image
    cv::imshow("Inverted Image", image);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}