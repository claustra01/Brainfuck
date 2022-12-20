#include <stdio.h>
#define max_num 10000

int main() {

    int ptr = 0;
    int mem[max_num];
    for (int i=0; i<max_num; i++) mem[i] = 0;

    char in[max_num];
    int prg = 0;
    scanf("%s", in);

    while (1) {
        if (in[prg] == '>') ptr++;
        if (in[prg] == '<') ptr--;
        if (in[prg] == '+') mem[ptr]++;
        if (in[prg] == '-') mem[ptr]--;
        if (in[prg] == '.') printf("%c", mem[ptr]);
        if (in[prg] == ',') ; // Undefined
        if (in[prg] == '[') if (mem[ptr] == 0) while (in[prg] != ']') prg++;
        if (in[prg] == ']') if (mem[ptr] != 0) while (in[prg] != '[') prg--;
        if (in[prg] == '\0') break;
        prg++;
    }
    
}
