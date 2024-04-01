#include <opencv2/opencv.hpp>
#include "yolov8_onnx.h"

#include <main.hpp>

//#define  VIDEO_OPENCV //if define, use opencv for video.

using namespace std;
using namespace cv;
using namespace dnn;

using std::this_thread::sleep_for;
using std::chrono::steady_clock;
using namespace std::literals;

template <typename _Tp>
int yolov8_onnx(_Tp &task, Mat &img, string &model_path) {

  if (task.ReadModel(model_path, false)) {
    cout << "read net ok!" << endl;
  } else {
    return -1;
  }
  //生成随机颜色
  vector<Scalar> color;
  srand(time(0));
  for (int i = 0; i < 80; i++) {
    int b = rand() % 256;
    int g = rand() % 256;
    int r = rand() % 256;
    color.push_back(Scalar(b, g, r));
  }
  vector<OutputParams> result;
  if (task.OnnxDetect(img, result)) {
    cout << "Detect sucessed!" << endl;
    DrawPred(img, result, task._className, color);
    cout << "Detect DrawPred!" << endl;
  } else {
    cout << "Detect Failed!" << endl;
  }
  system("pause");
  return 0;
}

template <typename _Tp> int video_demo(_Tp &task, string &model_path) {
  vector<Scalar> color;
  srand(time(0));
  for (int i = 0; i < 80; i++) {
    int b = rand() % 256;
    int g = rand() % 256;
    int r = rand() % 256;
    color.push_back(Scalar(b, g, r));
  }
  vector<OutputParams> result;
  cv::VideoCapture cap(0);
  if (!cap.isOpened()) {
    std::cout << "open capture failured!" << std::endl;
    return -1;
  }
  Mat frame;
#ifdef VIDEO_OPENCV
  Net net;
  if (task.ReadModel(net, model_path, true)) {
    cout << "read net ok!" << endl;
  } else {
    cout << "read net failured!" << endl;
    return -1;
  }

#else
  if (task.ReadModel(model_path, true)) {
    cout << "read net ok!" << endl;
  } else {
    cout << "read net failured!" << endl;
    return -1;
  }

#endif

  while (true) {

    cap.read(frame);
    if (frame.empty()) {
      std::cout << "read to end" << std::endl;
      break;
    }
    result.clear();
#ifdef VIDEO_OPENCV

    if (task.Detect(frame, net, result)) {
      DrawPred(frame, result, task._className, color, true);
    }
#else
    if (task.OnnxDetect(frame, result)) {
      DrawPred(frame, result, task._className, color, true);
    }
#endif
    int k = waitKey(10);
    if (k == 27) { // esc
      break;
    }
  }
  cap.release();

  system("pause");

  return 0;
}

 
int main() {

  quill_init();

const auto start = steady_clock::now();
sleep_for(10ms);
const auto end =  steady_clock::now();
int diff=(end - start)/1ms; 

  LOG_INFO(logger,"diff:{0} ms",diff);
  quill::flush();

  Yolov8Onnx task_detect_ort;

  std::filesystem::path current_path = std::filesystem::current_path();

  string img_path = current_path / "images/bus.jpg";

  string model_path_detect = current_path / "models/yolov8m.onnx";

  Mat src = imread(img_path.c_str());
  Mat img = src.clone();

  yolov8_onnx(task_detect_ort, img, model_path_detect);


#ifdef VIDEO_OPENCV
  video_demo(task_detect_ocv, model_path_detect);
  // video_demo(task_segment_ocv, model_path_seg);
#else
  // video_demo(task_detect_ort, model_path_detect);
  // video_demo(task_rtdetr_ort, model_path_rtdetr);
  // video_demo(task_segment_ort, model_path_seg);
#endif
  return 0;
}
