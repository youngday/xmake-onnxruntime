set_xmakever("2.8.5")
set_project("xmake-example")
set_languages("c++20")
add_rules("mode.debug", "mode.release")

add_requires("opencv", {system = true})
add_requires("openssl", {alias = "openssl", configs = { options = "OpenSSL:shared=True" }})
add_requires( "yaml-cpp 0.8.0",  "cppzmq 4.10.0", "toml++ 3.4.0","coost 3.0.2","quill 3.6.0","fmt 10.2.1",
"nlohmann_json 3.11.2","concurrentqueue 1.0.4")
-- add_requires("onnxruntime 1.17.0",{configs = {gpu = true}})
add_requires("onnxruntime 1.17.0")

add_packages("yaml-cpp", "coost","toml++","nlohmann_json","fmt","quill","concurrentqueue")
add_packages("opencv","onnxruntime")

add_includedirs("src/utils")
add_files("src/utils/*.cpp")
add_includedirs("src/")

target("yolov5_detect")
    set_kind("binary")
    add_files("src/yolov5/main.cpp")

target("yolov8_detect")
    set_kind("binary")
    add_files("src/yolov8/main_detect.cpp")
    
