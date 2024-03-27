#include <stdio.h>
#include <string.h>

struct op {
    char l;
    char r[20];
} op[10], pr[10];

void main() {
    int a, i, k, j, n, z = 0, m, q;
    char *p, *l, *tem, temp, t;
    char nu[] = "\0";

    printf("\nEnter the number of values: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nLeft: ");
        scanf(" %c", &op[i].l);
        printf("Right: ");
        scanf("%s", op[i].r);
    }

    printf("\nIntermediate code\n");
    for (i = 0; i < n; i++) {
        printf("%c=%s\n", op[i].l, op[i].r);
    }

    for (i = 0; i < n; i++) {
        temp = op[i].l;
        p = NULL;
        for (j = 0; j < n; j++) {
            p = strchr(op[j].r, temp);
            if (p) {
                pr[z].l = op[i].l;
                strcpy(pr[z].r, op[i].r);
                z++;
                break;
            }
        }
    }

    printf("\nAfter dead code elimination\n");
    for (k = 0; k < z; k++) {
        printf("%c\t=%s\n", pr[k].l, pr[k].r);
    }

    for (m = 0; m < z; m++) {
        tem = pr[m].r;
        for (j = m + 1; j < z; j++) {
            p = strstr(tem, pr[j].r);
            if (p) {
                pr[j].l = pr[m].l;
                for (i = 0; i < z; i++) {
                    if (l) {
                        a = l - pr[i].r;
                        pr[i].r[a] = pr[m].l;
                    }
                }
            }
        }
    }

    printf("\nEliminate common expression\n");
    for (i = 0; i < z; i++) {
        printf("%c\t=%s\n", pr[i].l, pr[i].r);
    }

    for (i = 0; i < z; i++) {
        for (j = i + 1; j < z; j++) {
            q = strcmp(pr[i].r, pr[j].r);
            if ((pr[i].l == pr[j].l) && !q) {
                pr[i].l = '\0';
                strcpy(pr[i].r, nu);
            }
        }
    }

    printf("\nOptimized code\n");
    for (i = 0; i < z; i++) {
        if (pr[i].l != '\0') {
            printf("%c\t=%s\n", pr[i].l, pr[i].r);
        }
    }
}