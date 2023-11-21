# 学益得智能硬件的 5 道指针字符串笔试题

## 题目出处：[作为嵌入式工程师，指针应该掌握到什么程度？](https://www.bilibili.com/video/BV1oC4y1A7Bn/)

无意间刷到这个视频，自己也看这个 UP 主很久了，今天就来练练手，巩固一下对指针和字符串操作的熟练度。

一共是五个问题，如下：

|题目|描述|
|----|---------------------------------------|
|1.  |传入任意字符，把所有小写字母换成大写字母。|
|2.  |传入任意字符串，去除该字符串的所有空格并返回。|
|3.  |判断一个字符串是不是回文。|
|4.  |找出两个字符串的公共子串。|
|5.  |不改变单词内部结构，倒置单词位置。|

这几个问题的具体实现源码，在 src\string_ptr.c 文件。

```C

char *upper(const char *_str, char *_upper_str)
{
    /*入参检查，确保传入的源字符串不是空串*/
    if (!_str) { return NULL; }
    
    /*求字符串长度*/
    size_t length = strlen(_str);

    /*为结果字符串开辟内存*/
    _upper_str = (char *)malloc(length + 1); if (!_upper_str) { return NULL; }

    /*遍历字符串*/
    for (register int index = 0; index < length; ++index)
    {
        if (isalpha(_str[index]))
        {
            _upper_str[index] = toupper(_str[index]);
        }
        else
        {
            _upper_str[index] = _str[index];
        }
    }

    _upper_str[length] = '\0';

    return _upper_str;
}

char *no_space(const char *_str, char *_no_space_str)
{
    /*入参检查，确保传入的源字符串不是空串*/
    if (!_str) { return NULL; }

    size_t length = strlen(_str);

    if (!(_no_space_str = (char *)malloc(length + 1)))
    {
        return NULL;
    }

    char *temp = _no_space_str;

    for (register int index = 0; index < length; ++index)
    {
        if (_str[index] != ' ')
        {
            *temp++ = _str[index];
        }
    }

    *temp = '\0';

    return _no_space_str;
}

bool Palindrome(const char *_str)
{
    /*入参检查，确保传入的源字符串不是空串*/
    if (!_str) { return NULL; }

    size_t length = strlen(_str);

    char *palindrome_str = (char *)malloc(length + 1);

    for (register int index = 0; index < length; ++index)
    {
        palindrome_str[length - index - 1] = _str[index];
    }

    palindrome_str[length] = '\0';

    bool is_palindrome = (strcmp(_str, palindrome_str) == 0);

    free(palindrome_str);

    return is_palindrome;
}

char *find_common_substring(const char *_str_a, const char *_str_b, char *common_substring)
{
    /*入参检查，确保传入的源字符串不是空串*/
    if (!_str_a || !_str_b) { return NULL; }

    size_t len_a = strlen(_str_a);
    size_t len_b = strlen(_str_b);

    size_t max = 0;  // 最长公共子串的长度
    size_t maxi = 0; // 在str1中的起始位置

    for (register int i = 0; i < len_a; i++)
    {
        for (register int j = 0; j < len_b; j++)
        {
            // 寻找公共子串
            int k = 0;
            while (_str_a[i + k] == _str_b[j + k] && i + k < len_a && j + k < len_b)
            {
                k++;
            }

            // 更新最长长度
            if (k > max)
            {
                max = k;
                maxi = i;
            }
        }
    }

    common_substring = (char *)malloc(max + 1);
    if (!max) { return NULL; }

    // 拷贝公共子串
    strncpy(common_substring, _str_a + maxi, max);
    common_substring[max] = '\0';

    return common_substring;
}

char *invert_word_position(const char *_str, char * _invert_words_str)
{
    /*入参检查，确保传入的源字符串不是空串*/
    if (!_str) { return NULL; }

    size_t length = strlen(_str);

    char *_temp_str = (char *)malloc(length + 1);
    _invert_words_str = (char *)malloc(length + 1);
    memset(_invert_words_str, 0, length + 1);
    memset(_temp_str, 0, length + 1);

    char * words_set[15];
    memset(words_set, 0, 15 * 8);

    strcpy(_temp_str, _str); _temp_str[length] = '\0';

    char * temp_tok = strtok(_temp_str, " ");
    int index = 1;
    words_set[0] = temp_tok;

    while (temp_tok)
    {
        temp_tok = strtok(NULL, " ");
        words_set[index++] = temp_tok;
    }

    int token_index = index - 2;

    for (register int token = token_index; token >= 0; --token)
    {
        if (token > 0)
        {
            strcat(words_set[token], " ");
        }

        strcat(_invert_words_str, words_set[token]);
    }
    
    _invert_words_str[length] = '\0';

    free(_temp_str);

    return _invert_words_str;
}
```

然后 test 文件夹是测试用例的源代码，bin 文件夹是测试用例的可执行文件。

Author: [JesseZ332623](https://github.com/JesseZ332623)

Modification Date: 2023.11.21
