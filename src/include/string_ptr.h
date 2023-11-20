#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define IS_PALINDROME(str) ((Palindrome(str)) ? "true" : "false")   /*一个 macro，封装了 Palindrome 函数*/

/**
    题目 1：传入入任意字符，把所有小写字母换成大写字母，
    要严格考虑内存安全，需要以下操作：

    1.对入参进行检查

    2.使用 malloc 创建新字符串，并返回。不要修改并返回原字符串。

    @param _str 源字符串
    @param _upper_str 修改后大写后的字符串

    @return 指向修改成大写后的字符串的指针
*/
char *upper(const char *_str, char *_upper_str);

/**
    题目 2：传入任意字符串，去除该字符串的所有空格并返回。

    @param _str 源字符串
    @param _no_space_str 修改后的没有空格的字符串

    @return 指向修改后的没有空格的字符串的指针
*/
char *no_space(const char *_str, char *_no_space_str);

/**
    题目 3: 判断一个字符串是不是回文

    @param _str 源字符串

    @return 一个布尔类型，true 是回文，false 不是回文
*/
bool Palindrome(const char *_str);

/**
    题目 4：找出两个字符串的公共子串

    @param _str_a 源字符串 A
    @param _str_b 源字符串 B
    @param common_substring 字符串 A B 的公共子串

    @return 指向字符串 A B 的公共子串的指针
*/
char *find_common_substring(const char *_str_a, const char *_str_b, char *common_substring);

/**
    题目 5：不改变单词内部结构，倒置单词位置。

    如：传入 I am from China 返回：China from am I

    思路：拷贝原字符串后分割，形成的字串存入一个字符串数组，再倒序拼接。
    但是这个字符串数组的长度有限，暂时设置长度为 15，也就是存储了 15 个字符串的地址。
    以后可以考虑动态或链式存储这个字符串数组。

    @param _str 源字符串
    @param _invert_words_str 倒置单词位置后的字符串

    @return 指向倒置单词位置后的字符串的指针
*/
char *invert_word_position(const char *_str, char * _invert_words_str);