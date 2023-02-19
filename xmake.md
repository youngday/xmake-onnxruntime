# xmake and xrepo
* https://xmake.io/#/
* https://xrepo.xmake.io/#/
## xmake install 
```sh
bash <(wget https://xmake.io/shget.text -O -)
```
## ide
vscode + xmake + gcc
## packages

https://xrepo.xmake.io/#/packages

xrepo ,apt ,conan,vcpkg,cmake,and make install 

```sh
# make install at "/usr/local/lib"
xmake l find_package fmt 
xmake l find_package cmake::fmt
xmake l find_package conan::fmt
xmake l find_package apt::fmt
```
## xmake project compile and install
```sh
xmake
xmake install --admin
```
## xmake cli

xmake f --menu    xmake gui

## config

https://xmake.io/mirror/zh-cn/guide/configuration.html

### repo

### gitee

```sh
export XMAKE_MAIN_REPO=https://gitee.com/xmake-io/xmake-repo.git
export XMAKE_BINARY_REPO=https://gitee.com/xmake-mirror/build-artifacts.git
```

### ssl issues

curl：(60) SSL

curl -k https://github.com

## update

xrepo update-repo
xmake f -c
xmake

``
## search package
```sh
xrepo search onnxruntime  
```

## usr local lib path
```sh
xmake g --pkg_searchdirs=/xxx
xmake g --pkg_searchdirs=/home/youngday/prj-yolo/xmake-onnxruntime-yolov5/3rdparty/onnxruntime-linux-x64-gpu-1.12.1
```
## end

🐞
