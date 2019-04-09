# KoreaIME
这是一个简单的基于Qt5.4开发的韩语输入法的demo，可以正常输入韩语


hangulime.h,hangulime.cpp，纯C++语言实现韩语输入法库，只包含两个接口：

//判断键盘按键字符是否韩语的基本拼写字根
int isJamo(const unsigned short keycode);
//输入2个字符，输出最多2个字符，且看demo中是如何使用此API的
int hangulIME(unsigned short *in, unsigned short *out);

使用非常简单，代码里面也有一些注释。非常适合在设备上要求添加韩语输入法，但是自己又不懂韩语，不会开发输入法的同学。
