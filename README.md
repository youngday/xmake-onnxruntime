# xmake onnxruntime  yolov5

## function
 
use xmake to build yolov5 inference function

## dependence
### xmake onnxruntime cpu version package
we use opencv lib by cmaking it,you can use xmake lib also.
others like onnxruntime ,from xrepo .
### office gpu version package
🎶
at source path,
```sh
cd 3rdparty
wegt -c -p https://github.com/microsoft/onnxruntime/releases/download/v1.12.1/onnxruntime-linux-x64-gpu-1.12.1.tgz
tar zxvf onnxruntime-linux-x64-gpu-1.12.1.tgz -C ./
```
🎶
    set_kind("binary")
after compiled,we need copy all shared files of onnxruntime-linux-x64-gpu-1.12.1 into the folder where  binary at.
## todo 
1 when debugging,
```sh
error while loading shared libraries: libonnxruntime.so.1.12.1: cannot open shared object file: No such file or directory
```
to fix it.

## References

https://github.com/itsnine/yolov5-onnxruntime

YOLO v5 repo: https://github.com/ultralytics/yolov5
YOLOv5 Runtime Stack repo: https://github.com/zhiqwang/yolov5-rt-stack
ONNXRuntime Inference examples: https://github.com/microsoft/onnxruntime-inference-examples
