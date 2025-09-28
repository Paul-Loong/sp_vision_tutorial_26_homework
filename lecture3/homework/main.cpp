#include "io/my_camera.hpp"
#include "tasks/yolo.hpp"
#include "opencv2/opencv.hpp"
#include "tools/img_tools.hpp"


// 绘制可视化识别结果
inline void draw_armor(cv::Mat& img, auto_aim::Armor& armor)
{
    cv::Scalar color;
    switch (armor.color)
    {
    case auto_aim::red:
        color = cv::Scalar(0, 0, 255);
        break;
    case auto_aim::blue:
        color = cv::Scalar(255, 0, 0);
        break;
    case auto_aim::extinguish:
        color = cv::Scalar(128, 128, 128);
        break;
    case auto_aim::purple:
        color = cv::Scalar(0, 255, 255);
        break;
    default:
        color = cv::Scalar(255, 255, 255);
        break;
    }
    
    // 画框
    tools::draw_points(img, armor.points, color, 5);
    
    // 写字
    const std::string armor_text = auto_aim::COLORS[armor.color] + " " + auto_aim::ARMOR_NAMES[armor.name];
    const cv::Point2f text_point = armor.points[0] + cv::Point2f(0, -20);
    tools::draw_text(img, armor_text, text_point, color, 3.0, 5);
}


int main()
{
    // 初始化相机、yolo类
    const std::string yolo_config_path("./configs/yolo.yaml");
    io::myCamera camera(5000, 20, 20);
    auto_aim::YOLO yolo(yolo_config_path, true);
    
    while (1) {
        // 调用相机读取图像
        cv::Mat img = camera.read();
        if (img.empty()) continue;

        // 调用yolo识别装甲板
        std::list<auto_aim::Armor> armor_list = yolo.detect(img);
        for (auto_aim::Armor armor : armor_list) {
            draw_armor(img, armor);
        }

        // 显示图像
        cv::resize(img, img , cv::Size(640, 480));
        cv::imshow("img", img);
        if (cv::waitKey(1) == 'q') {
            break;
        }
    }

    return 0;
}