# SCode-C-Environment

针对 Android 实验室成员 C 语言练习的 VSCode C 语言环境一键配置。

## 使用方法

1. 下载 msys64 环境[【从Github】]()[【从百度云】]()
2. 直接解压到 **C盘** （可能需要管理员权限）
3. 安装 Visual Studio Code[【下载地址】](https://code.visualstudio.com/docs/?dv=win64user)
4. 打开 Visual Studio Code，按下 Ctrl+Shift+X
5. 依次搜索、安装如下扩展：`C/C++` `Code Runner`
6. 下载并解压这个项目，右击 `C-Project` 这个文件夹，选择 `Open with Code` 可以看到下面的目录：

## C-Project

适用于 C 语言的项目目录。将你的C语言代码放到这里。每个文件是互相独立的，可以独立编译、运行、调试。

当你写代码时，在右侧面板的调试 🐞 按钮，点击 `▷ gdb` 即可开始调试项目

### build

项目生成在这个目录。如果没有这个目录，必须先手动创建才能编译。