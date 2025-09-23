#include "tools.hpp"

cv::Mat resizeImageTo640(cv::Mat img)
{
    // 计算缩放系数
    double index;
    if (img.rows >= img.cols)
    {
        index = 640.0 / img.rows;
    }
    else
    {
        index = 640.0 / img.cols;
    }

    // 缩放原图片
    int new_col = img.cols * index;
    int new_row = img.rows * index;
    cv::Mat img_resize;
    cv::resize(img, img_resize, cv::Size(new_col, new_row));

    // 将缩放后的图片放置在背景图上
    int pos_col = (640 - new_col) / 2;
    int pos_row = (640 - new_row) / 2;
    cv::Mat img_640 = cv::Mat::zeros(640, 640, img.type());
    cv::Mat roi(img_640, cv::Rect(pos_col, pos_row, new_col, new_row));
    img_resize.copyTo(roi);

    fmt::print("缩放比例：{}\n", index);
    fmt::print("图像偏移：dx={},  dy={}\n", pos_col, pos_row);

    return img_640;
}