#include "./include/string_ptr.h"

char *upper(const char *_str, char *_upper_str)
{
    /*��μ�飬ȷ�������Դ�ַ������ǿմ�*/
    if (!_str) { return NULL; }
    
    /*���ַ�������*/
    size_t length = strlen(_str);

    /*Ϊ����ַ��������ڴ�*/
    _upper_str = (char *)malloc(length + 1); if (!_upper_str) { return NULL; }

    /*�����ַ���*/
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
    /*��μ�飬ȷ�������Դ�ַ������ǿմ�*/
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
    /*��μ�飬ȷ�������Դ�ַ������ǿմ�*/
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
    /*��μ�飬ȷ�������Դ�ַ������ǿմ�*/
    if (!_str_a || !_str_b) { return NULL; }

    size_t len_a = strlen(_str_a);
    size_t len_b = strlen(_str_b);

    size_t max = 0;  // ������Ӵ��ĳ���
    size_t maxi = 0; // ��str1�е���ʼλ��

    for (register int i = 0; i < len_a; i++)
    {
        for (register int j = 0; j < len_b; j++)
        {
            // Ѱ�ҹ����Ӵ�
            int k = 0;
            while (_str_a[i + k] == _str_b[j + k] && i + k < len_a && j + k < len_b)
            {
                k++;
            }

            // ���������
            if (k > max)
            {
                max = k;
                maxi = i;
            }
        }
    }

    common_substring = (char *)malloc(max + 1);
    if (!max) { return NULL; }

    // ���������Ӵ�
    strncpy(common_substring, _str_a + maxi, max);
    common_substring[max] = '\0';

    return common_substring;
}

char *invert_word_position(const char *_str, char * _invert_words_str)
{
    /*��μ�飬ȷ�������Դ�ַ������ǿմ�*/
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