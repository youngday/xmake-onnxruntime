#include <iostream>
#include <opencv2/opencv.hpp>

#include "cmdline.h"
#include "yolov5_utils.h"
#include "detector.h"


int main(int argc, char* argv[])
{
    const float confThreshold = 0.3f;
    const float iouThreshold = 0.4f;

    cmdline::parser cmd;
    cmd.add<std::string>("model_path", 'm', "Path to onnx model.", true, "models/yolov5m.onnx");
    cmd.add<std::string>("image", 'i', "Image source to be detected.", true, "images/bus.jpg");
    cmd.add<std::string>("class_names", 'c', "Path to class names file.", true, "models/coco.names");
    cmd.add("gpu", '\0', "Inference on cuda device.");

    cmd.parse_check(argc, argv);
    bool isGPU = cmd.exist("gpu");
    
    // bool isGPU =true;
    const std::string classNamesPath = cmd.get<std::string>("class_names");
    const std::vector<std::string> classNames = utils::loadNames(classNamesPath);
    const std::string imagePath = cmd.get<std::string>("image");
    const std::string modelPath = cmd.get<std::string>("model_path");
    // bool isGPU =false;
    // const std::string classNamesPath = "models/coco.names";
    // const std::vector<std::string> classNames = utils::loadNames(classNamesPath);
    // const std::string imagePath = "images/bus.jpg";
    // const std::string modelPath = "models/yolov5m.onnx";
    // ./build/linux/x86_64/debug/yolov5 --model_path models/yolov5m.onnx --image images/bus.jpg --class_names models/coco.names --gpu

    if (classNames.empty())
    {
        std::cerr << "Error: Empty class names file." << std::endl;
        return -1;
    }

    YOLODetector detector {nullptr};
    cv::Mat image;
    std::vector<Detection> result;

    try
    {
        detector = YOLODetector(modelPath, isGPU, cv::Size(640, 640));
        std::cout << "Model was initialized." << std::endl;

        image = cv::imread(imagePath);
        result = detector.detect(image, confThreshold, iouThreshold);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    utils::visualizeDetection(image, result, classNames);

    cv::imshow("result", image);
    // cv::imwrite("result.jpg", image);
    cv::waitKey(0);

    return 0;
}