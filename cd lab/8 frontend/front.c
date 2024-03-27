#include <stdio.h>
#include <string.h>

int main() {
    char a[50], b[50];
    int i, j, k, len, ti = 0, count;
    FILE *fp;

    fp = fopen("out.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter the code: ");
    scanf("%s", a);
    strcpy(b, a);
    len = strlen(a);

    for (i = 0; i < len; i++) {
        if (b[i] == '*' || b[i] == '/') {
            for (j = i - 1; b[j] != '-' && b[j] != '+' && b[j] != '*' && b[j] != '/' && b[j] != '='; j--);
            k = j + 1;
            count = 0;
            fprintf(fp, "\nt%d=", ti++);
            for (j = j + 1; count < 2 && b[j] != '\0'; j++) {
                if (b[j + 1] == '+' || b[j + 1] == '-' || b[j + 1] == '*' || b[j + 1] == '/')
                    count++;
                fprintf(fp, "%c", b[j]);
            }
            b[k++] = 't';
            b[k++] = ti - 1 + '0';
            for (j = j, k = k; k < strlen(b); k++, j++)
                b[k] = b[j];
            i = 0;
        }
    }

    for (i = 0; i < len; i++) {
        if (b[i] == '+' || b[i] == '-') {
            for (j = i - 1; b[j] != '-' && b[j] != '+' && b[j] != '='; j--);
            k = j + 1;
            count = 0;
            fprintf(fp, "\nt%d=", ti++);
            for (j = j + 1; count < 2 && b[j] != '\0'; j++) {
                if (b[j + 1] == '+' || b[j + 1] == '-')
                    count++;
                fprintf(fp, "%c", b[j]);
            }
            b[k++] = 't';
            b[k++] = ti - 1 + '0';
            for (j = j, k = k; k < strlen(b); k++, j++)
                b[k] = b[j];
        }
    }

    fprintf(fp, "\n%s\n", b);
    fclose(fp);
    printf("Output written to out.txt\n");

    return 0;
}