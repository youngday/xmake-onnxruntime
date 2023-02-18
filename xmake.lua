set_project("xmake-example")
set_languages("c++17")
add_rules("mode.debug", "mode.release")
add_requires("tbox master", {debug = true})
add_requires("onnxruntime 1.11.1")
-- cmake packages
add_requires("cmake::OpenCV", {alias = "opencv",system = true})
target("yolov5")
    set_kind("binary")
    add_files("src/yolo/*.cpp")
    add_includedirs("include")
    add_packages("tbox","yolo","opencv","onnxruntime")

