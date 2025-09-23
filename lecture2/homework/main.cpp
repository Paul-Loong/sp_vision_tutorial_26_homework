#include "tools.hpp"


int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <input_image>\n";
        return 1;
    }
    std::string inPath = argv[1];
    fmt::print("Input image path: {}\n", inPath);

    // 读取图片
    cv::Mat bgr_img = cv::imread(inPath);
    if (bgr_img.empty())
    {
        std::cerr << "fail to load image" << std::endl;
        return 2;
    }

    cv::Mat img_640 = resizeImageTo640(bgr_img);

    cv::imshow("Original image", bgr_img);
    cv::imshow("Resized image", img_640);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}