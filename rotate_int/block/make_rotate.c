#include <stdio.h>
#include <stdlib.h>

void write_main(int N, FILE* rotate_c);

int main(int argc, char *argv[]) {
    if(argc != 2) {
        perror("[Usage] Input block size\n");
        return 1;
    }
    int B = atoi(argv[1]);
    FILE * rotate_c = fopen("block/rotate.c", "w");
    write_main(B, rotate_c);
    fclose(rotate_c);
    return 0;
}

void write_main(int B, FILE* rotate_c) {
    fprintf(rotate_c, "#define B %d\n", B);
    fprintf(rotate_c, "int s = 0;\n");
    fprintf(rotate_c, "void rotate(int n, int src[n][n], int dst[n][n]) {\n");
    fprintf(rotate_c, "    int i, j, i_b, j_b;\n");
    fprintf(rotate_c, "    for(i = 0; i < n; i+=B) \n");
    fprintf(rotate_c, "        for(j = 0; j < n; j+=B) {\n");
    fprintf(rotate_c, "            int i_e = i+B;\n");
    fprintf(rotate_c, "            int j_e = j+B;\n");
    fprintf(rotate_c, "            for(i_b = i; i_b < i_e; i_b++)\n");
    fprintf(rotate_c, "                for(j_b = j; j_b < j_e; j_b++)\n");
    fprintf(rotate_c, "                    dst[n-1-j_b][i_b] = src[i_b][j_b];\n");
    fprintf(rotate_c, "        }\n");
    fprintf(rotate_c, "    s++;\n");
    fprintf(rotate_c, "}\n");
}
