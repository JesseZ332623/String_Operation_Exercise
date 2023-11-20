#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define IS_PALINDROME(str) ((Palindrome(str)) ? "true" : "false")   /*һ�� macro����װ�� Palindrome ����*/

/**
    ��Ŀ 1�������������ַ���������Сд��ĸ���ɴ�д��ĸ��
    Ҫ�ϸ����ڴ氲ȫ����Ҫ���²�����

    1.����ν��м��

    2.ʹ�� malloc �������ַ����������ء���Ҫ�޸Ĳ�����ԭ�ַ�����

    @param _str Դ�ַ���
    @param _upper_str �޸ĺ��д����ַ���

    @return ָ���޸ĳɴ�д����ַ�����ָ��
*/
char *upper(const char *_str, char *_upper_str);

/**
    ��Ŀ 2�����������ַ�����ȥ�����ַ��������пո񲢷��ء�

    @param _str Դ�ַ���
    @param _no_space_str �޸ĺ��û�пո���ַ���

    @return ָ���޸ĺ��û�пո���ַ�����ָ��
*/
char *no_space(const char *_str, char *_no_space_str);

/**
    ��Ŀ 3: �ж�һ���ַ����ǲ��ǻ���

    @param _str Դ�ַ���

    @return һ���������ͣ�true �ǻ��ģ�false ���ǻ���
*/
bool Palindrome(const char *_str);

/**
    ��Ŀ 4���ҳ������ַ����Ĺ����Ӵ�

    @param _str_a Դ�ַ��� A
    @param _str_b Դ�ַ��� B
    @param common_substring �ַ��� A B �Ĺ����Ӵ�

    @return ָ���ַ��� A B �Ĺ����Ӵ���ָ��
*/
char *find_common_substring(const char *_str_a, const char *_str_b, char *common_substring);

/**
    ��Ŀ 5�����ı䵥���ڲ��ṹ�����õ���λ�á�

    �磺���� I am from China ���أ�China from am I

    ˼·������ԭ�ַ�����ָ�γɵ��ִ�����һ���ַ������飬�ٵ���ƴ�ӡ�
    ��������ַ�������ĳ������ޣ���ʱ���ó���Ϊ 15��Ҳ���Ǵ洢�� 15 ���ַ����ĵ�ַ��
    �Ժ���Կ��Ƕ�̬����ʽ�洢����ַ������顣

    @param _str Դ�ַ���
    @param _invert_words_str ���õ���λ�ú���ַ���

    @return ָ���õ���λ�ú���ַ�����ָ��
*/
char *invert_word_position(const char *_str, char * _invert_words_str);