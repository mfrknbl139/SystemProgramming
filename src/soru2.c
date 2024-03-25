#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void search_unsafe_functions(FILE *file) {
    char line[MAX_LINE_LENGTH];
    int line_num = 0;

    while (fgets(line, sizeof(line), file)) {
        line_num++;
        if (strstr(line, "strcpy(")) {
            printf("Satır %d: strcpy() kullanılmış, yerine strncpy() kullanmalısınız.\n", line_num);
        }
        if (strstr(line, "gets(")) {
            printf("Satır %d: gets() kullanılmış, yerine fgets() kullanmalısınız.\n", line_num);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Kullanım: %s <dosya_adı>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Dosya açılırken hata oluştu");
        return 1;
    }

    search_unsafe_functions(file);

    fclose(file);

    return 0;
}
