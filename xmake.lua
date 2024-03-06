set_project("xmake-example")
set_languages("c++20")
add_rules("mode.debug", "mode.release")
-- add_requires("onnxruntime 1.17.0",{configs = {gpu = true}})
add_requires("onnxruntime 1.17.0")
-- cmake packages
add_requires("cmake::OpenCV", {alias = "opencv",system = true})
target("yolov5")
    set_kind("binary")
    add_files("src/yolo/*.cpp")
    add_includedirs("include")
    add_packages("opencv","onnxruntime")

