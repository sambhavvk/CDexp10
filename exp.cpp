#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct op {
    int pos;
    char op;
} k[100];

char str[100], left[50], right[50], tmpch = 't';
int i, j, no = 0;

void findopr();
void explore();
void fleft(int x);
void fright(int x);

void findopr() {
    j = 0;
    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] == ':') {
            k[j].pos = i;
            k[j++].op = ':';
        }
        else if(str[i] == '/') {
            k[j].pos = i;
            k[j++].op = '/';
        }
        else if(str[i] == '*') {
            k[j].pos = i;
            k[j++].op = '*';
        }
        else if(str[i] == '+') {
            k[j].pos = i;
            k[j++].op = '+';
        }
        else if(str[i] == '-') {
            k[j].pos = i;
            k[j++].op = '-';
        }
        else if(str[i] == '(') {
            k[j].pos = i;
            k[j++].op = '(';
        }
        else if(str[i] == ')') {
            k[j].pos = i;
            k[j++].op = ')';
        }
    }
}

void explore() {
    i = 1;
    while(k[i].op != '\0') {
        fleft(k[i-1].pos);
        fright(k[i].pos);
        str[k[i].pos] = tmpch--;
        printf("\t%c := %s %c %s\t\t", str[k[i].pos], left, k[i].op, right);
        for(j = 0; j < strlen(str); j++)
            if(str[j] != '$')
                printf("%c", str[j]);
        printf("\n");
        i++;
    }
    fright(strlen(str));
    if(no == 0) {
        fleft(strlen(str));
        printf("\t%s := %s", right, left);
    }
    printf("\t%s := %c\n", right, str[k[--i].pos]);
}

void fleft(int x) {
    int w = 0, flag = 0;
    x--;
    while(x != -1 && str[x] != '+' && str[x] != '*' && str[x] != '=' && str[x] != '\0' && str[x] != '-' && str[x] != '/' && str[x] != ':' && str[x] != '(' && str[x] != ')') {
        if(str[x] != '$' && flag == 0) {
            left[w++] = str[x];
            left[w] = '\0';
            str[x] = '$';
            flag = 1;
        }
        x--;
    }
}

void fright(int x) {
    int w = 0, flag = 0;
    x++;
    while(x != strlen(str) && str[x] != '+' && str[x] != '*' && str[x] != '\0' && str[x] != '=' && str[x] != ':' && str[x] != '-' && str[x] != '/' && str[x] != '(' && str[x] != ')') {
        if(str[x] != '$' && flag == 0) {
            right[w++] = str[x];
            right[w] = '\0';
            str[x] = '$';
            flag = 1;
        }
        x++;
    }
}

int main() {
    printf("\t\tINTERMEDIATE CODE GENERATION OF DAG\n\n");
    scanf("%s", str);
    printf("The intermediate code:\t\tExpression\n");
    findopr();
    explore();
    return 0;
}
