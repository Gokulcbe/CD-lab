#include<stdio.h>
#include<ctype.h>
#include<string.h>

void main() {
    char a[50], id[50], mov[] = "MOVF", mul[] = "MULF", div[] = "DIVF", add[] = "ADDF", sub[] = "SUBF";
    int i = 0, j = 0, len = 0, s = 0, e = 0, r = 1;
    FILE *fp;
    
    fp = fopen("out.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter the code: ");
    gets(a);  // Note: gets() is not recommended, consider using fgets()

    len = strlen(a);

    for (i = 0; i < len; i++) {
        if (a[i] == '=') {
            for (j = i; j < len; j++) {
                if (a[j] == 'i') {
                    fprintf(fp, "\n%s ", mov);
                    fprintf(fp, "%c%c%c,R%d", a[j], a[j + 1], a[j + 2], r++);
                }
            }
        } else if (isdigit(a[i])) {
            if (isdigit(a[i + 1])) {
                fprintf(fp, "\n%s #%c%c,R%d", mov, a[i], a[i + 1], r++);
            }
        }
    }

    for (i = len - 1; i >= 0; i--) {
        if (a[i] == '+') {
            fprintf(fp, "\n%s ", add);
            e = a[i - 1] - '0';
            e--;
            s = e;
            if (a[i + 1] == 'i') {
                fprintf(fp, "R%d,R%d", e, r - 1);
            }
        } else if (a[i] == '-') {
            fprintf(fp, "\n%s ", sub);
            e = a[i - 1] - '0';
            e--;
            s = e;
            if (a[i + 1] == 'i') {
                fprintf(fp, "R%d,R%d", e, s);
            } else {
                fprintf(fp, "R%d,R%d", e, r - 1);
            }
        } else if (a[i] == '*') {
            fprintf(fp, "\n%s ", mul);
            e = a[i - 1] - '0';
            e--;
            s = e;
            if (a[i + 1] == 'i') {
                fprintf(fp, "R%d,R%d", e, s);
            } else {
                fprintf(fp, "R%d,R%d", e, r - 1);
            }
        } else if (a[i] == '/') {
            fprintf(fp, "\n%s ", div);
            e = a[i - 1] - '0';
            e--;
            s = e;
            if (a[i + 1] == 'i') {
                fprintf(fp, "R%d,R%d", e, s);
            } else {
                fprintf(fp, "R%d,R%d", e, r - 1);
            }
        }
    }

    fprintf(fp, "\n%s R1,id1", mov);
    fclose(fp);
    printf("Output written to out.txt\n");
}