#include "./src/include/string_ptr.h"

const char test_string[] = {"Finds the first token in the string."};

int main(int argc, char const *argv[])
{
    char *no_space_str = no_space(test_string, no_space_str);

    printf("Original Sentence: %s\nUpper Sentence: %s\n", test_string, no_space_str);

    return EXIT_SUCCESS;
}
