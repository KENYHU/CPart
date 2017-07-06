//
// Created by dekai
//

#include "string.h"
#include "stdio.h"
#include "math.h"

/*
 * 将十六进制转换十进制
 *
 */
int Mhextodec(char *input) {
    if( input == NULL ) {
        return -1;
    }
    char *start = input;

    //获取字符串长度
    int strLen = strlen(input);

    int i=0;   //for的临时变量
    int res=0; //结果
    int m = 0; //位数

    for (i = strLen-1; i >= 0; --i) {
        int thisInt = (int)*(input+i);
        int thisMark = 0;
        if( thisInt >=48 && thisInt <=57 ) {
            thisMark = 48;
        } else if( thisInt >=65 &&  thisInt <=70 ) {
            thisMark = 55;
        } else if( thisInt >=97 &&  thisInt <=102 ) {
            thisMark = 87;
        } else {
            return -1;
        }

        res = res+(thisInt-thisMark)*pow(16,m);
        m++;
    }

    return res;
}

int main() {
    char hex[8] = "ffee";
    int dec = Mhextodec(hex);
    printf("%d\n",dec);  // 结果 16772812
}
