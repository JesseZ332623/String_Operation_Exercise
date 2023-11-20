#include "./src/include/string_ptr.h"

const char str_01[] = {"qwertyuiop"};
const char str_02[] = {"qswdefrgthyertye"};

int main(int argc, char const *argv[])
{
    char * common_substring = find_common_substring(str_01, str_02, common_substring);

    printf("%s\n", common_substring);

    return EXIT_SUCCESS;
}
