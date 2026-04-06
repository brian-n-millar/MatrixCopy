#include <stdio.h>

int transfer(FILE *in, FILE *out) {
    if (in != NULL && out != NULL) {
        int c;
        int i = 1;
        puts("\x1b[32m");
        while ((c = fgetc(in)) != EOF) {
            if (i == 20) {
                puts("\n");
                fflush(stdout);
                i = 1;
            }
            fputc(c, out);
            printf("%2x ", c);
            i++;
        }
        putchar('\n');
        fclose(in);
        fclose(out);
    } else {
        perror("Error");
        return -1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argv[1] != NULL && argv[2] != NULL) {
        FILE *in  = fopen(argv[1], "r");
        FILE *out = fopen(argv[2], "w");
        return transfer(in, out);
    }
    puts("Invaild Arguments");
    return -1;
}
