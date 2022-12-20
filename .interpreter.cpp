#include <bits/stdc++.h>
using namespace std;

int main() {

    // Initialization
    int mem_size = 100000;
    unsigned int ptr = 0;
    vector<unsigned char> mem(mem_size, 0);
    stack<int> loops;

    // Load Source File
    ifstream file(".source.bf");
    stringstream buffer;
    buffer << file.rdbuf();
    string code = buffer.str();
    int prg = 0;

    // interpreter Body
    while (code[prg] != '\0') {

        // Modify Pointer
        if (code[prg] == '>') ptr = (ptr >= mem_size-1) ? 0 : ptr+1;
        if (code[prg] == '<') ptr = (ptr <= 0) ? mem_size-1 : ptr-1;

        // Modify Memory
        if (code[prg] == '+') mem[ptr]++;
        if (code[prg] == '-') mem[ptr]--;

        // Input and Output
        if (code[prg] == '.') putchar(mem[ptr]);
        if (code[prg] == ',') mem[ptr] = getchar();

        // Loop Start
        if (code[prg] == '[') {
            if (mem[ptr] != 0) loops.push(prg);
            else {
                int depth = 1;
                while (depth>0) {
                    prg++;
                    if (code[prg] == '[') depth++;
                    if (code[prg] == ']') depth--;
                }
            }
        }

        // Loop End
        if (code[prg] == ']') {
            prg = loops.top()-1;
            loops.pop();
        }

        prg++;

    }

}