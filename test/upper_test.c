#include "./src/include/string_ptr.h"

int main(int argc, char const *argv[])
{
    char sentence[100] = {"0"};
    char * upper_str;

    puts("Enter a sentence:");
    
    while (scanf("%s", sentence))
    {
        upper_str = upper(sentence, upper_str);
        puts("--------------------------------------------------");
        printf("Original Sentence: %s\nUpper Sentence: %s\n", sentence, upper_str);

        puts("Enter sentence again (CTRL + C to quit):");
    }
    
    return EXIT_SUCCESS;
}
