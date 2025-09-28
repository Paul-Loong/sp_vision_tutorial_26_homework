#ifndef MY__CAMERA_HPP
#define MY__CAMERA_HPP

#include "hikrobot/include/MvCameraControl.h"
#include <opencv2/opencv.hpp>

namespace io
{

class myCamera
{
public:
    // 打开相机
    myCamera(float exposure_time = 10000, float gain = 20, float framee_rate = 20);
    // 关闭相机
    ~myCamera();
    // 读取一帧图像
    cv::Mat read();

private:
    // 转化格式为cv::Mat
    cv::Mat transfer(::MV_FRAME_OUT& raw);

    void * handle_;
    MV_CC_DEVICE_INFO_LIST device_list_;
};

} // namespace io

#endif // MY__CAMERA_HPP