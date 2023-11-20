#include "./src/include/string_ptr.h"

const char str_01[] = {"I'm From China."};
const char str_02[] = {"You should send these data continuously until the server response."};

int main(int argc, char const *argv[])
{
    char * invert_str_01, * invert_str_02;
    invert_str_01 = invert_word_position(str_01, invert_str_01);
    invert_str_02 = invert_word_position(str_02, invert_str_02);

    printf("%s\n", invert_str_01);
    printf("%s\n", invert_str_02);

    free(invert_str_01);
    free(invert_str_02);

    return 0;
}
