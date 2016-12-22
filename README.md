# SBC-7112S-Backlight-Qt4.8.5 Example

## 一、说明

* 在阅读该源代码之前，请确保您已经阅读了以下两篇文档：
 * [《SBC-7112S-Linux3.0.35-Qt4.8.5 Quick Start Guide》](https://github.com/AplexOS/zh-cmn-Hans/blob/SBC-7112S-Linux3.0.35-Qt4.8.5-BSP/Quick_Start_Guide.md)
 * [《SBC-7112S-Linux3.0.35-Qt4.8.5 User's Guide》](https://github.com/AplexOS/zh-cmn-Hans/blob/SBC-7112S-Linux3.0.35-Qt4.8.5-BSP/User's_Guide.md)
* 您作为本文档的阅读者，我们将假定您已经具备如下技能：
 * 了解[Linux文件系统架构](http://www.tldp.org/LDP/intro-linux/html/sect_03_01.html)；
 * 熟悉并掌握[Qt 4.8.5编码规范](http://doc.qt.io/qt-4.8/)；
 * 对Linux ARM交叉编译开发流程熟悉；
 * 能够使用[Qt Creator](http://doc.qt.io/qtcreator/)；

## 二、原理

* 背光设备节点：`/sys/class/backlight/pwm-backlight.1/brightness`。
* 背光值范围`0~248`，这里是字符串。
* 将`0~248`范围内的字符串写入上面的背光设备节点内，就会设置背光亮度。

## 三、源代码说明

* 源代码在[`src`](src)目录；
* 源代码Qt版本是`4.8.5`；

## 四、版权说明

以上所有内容最终解释权归[aplex](http://www.aplextec.com/cn/home.php)公司所有。

