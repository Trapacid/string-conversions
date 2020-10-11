#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ConvertToHex(char *input, char *output) {
    int loop = 0;
    int i = 0;

    while(input[loop] != '\0') {
        sprintf((char*)(output+i), "%02x", input[loop]);
        loop+=1;
        i+=2;
    }
    output[i++] = '\0';
}

void ConvertToBinary(char *input) {
    int i;
    printf("binary string: ");
    for(; *input != 0; ++input) {
        for(i = 7; i >= 0; --i)
            (*input & 1 << i) ? putchar('1') : putchar('0');

        putchar(' ');
    }
    putchar('\n');
}

int main(int argc, char **argv) {
    int length = strlen(argv[1]);
    char hex_str[(length*2)+1];

    ConvertToHex(argv[1], hex_str);
    printf("hex string: %s\n", hex_str);
    
    ConvertToBinary(argv[1]);

    printf("original string: %s\n", argv[1]);
    return 0;
}