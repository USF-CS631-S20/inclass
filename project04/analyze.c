#include<stdio.h>

int add2_s(int a, int b);

void analyze_iw(unsigned int iw)
{
    unsigned int cond;
    unsigned int dp_op;
    unsigned int immediate;
    unsigned int opcode;
    unsigned int rn;
    unsigned int rd;
    unsigned int rm;
    unsigned int imm;

    cond = (iw >> 28) & 0b1111;
    dp_op = (iw >> 26) & 0b11;
    opcode = (iw >> 21) & 0b1111;
    rn = (iw >> 16) & 0b1111;
    rd = (iw >> 12) & 0b1111;
    rm = iw & 0b1111;
    imm = iw & 0b111111111;

    printf("cond = %X\n", cond);
    printf("dp_op = %X\n", dp_op);
    printf("opcode = %d\n", opcode);
    printf("rn = %d\n", rn);
    printf("rd = %d\n", rd);
    printf("rm = %d\n", rm);
    printf("imm = %d\n", imm);
}

int main(int argc, char **argv)
{
    unsigned int *pc;
    unsigned int iw;

    /* Get the address of the first instruction of add2_s */
    pc = (unsigned int *) add2_s;

    printf("pc = %X\n", pc);
    iw = *pc;
    printf("iw = %X\n", iw);
    analyze_iw(iw);
    printf("\n");


    /* Get the address of the second instructions of add2_s */
    pc = pc + 1;

    printf("pc = %X\n", pc);
    iw = *pc;
    printf("iw = %X\n", iw);
    analyze_iw(iw);
    
    return 0;
}
