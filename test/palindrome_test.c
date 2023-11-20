#include "./src/include/string_ptr.h"

char test_str_01[] = {"123321"};
char test_str_02[] = {"332233"};

char test_str_03[] = {"The Era Language Situation of Tragedy Consciousness in Chinese Modern Drama"};

int main(int argc, char const *argv[])
{
    printf("test_str_01: %s\n", IS_PALINDROME(test_str_01));
    printf("test_str_02: %s\n", IS_PALINDROME(test_str_02));
    printf("test_str_02: %s\n", IS_PALINDROME(test_str_03));
    
    return EXIT_SUCCESS;
}
