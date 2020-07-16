#include <stdio.h>

//MrHaddis
//https://github.com/MrHaddis/PAT1029

int main() {
    char origin[100];
    char now[100];
    char result[100];
    int indexNow = 0;
    int indexResult = 0;
    int indexOrigin = 0;

    scanf("%s", &origin);
    scanf("%s", &now);
    while (origin[indexOrigin] != '\0') {
        indexOrigin++;
    }
    for (int i = 0; i < indexOrigin; i++) {
        //如果不相等就说明不相同
        if (origin[i] != now[indexNow]) {
            //如果是小写的就转行成大写
            if (origin[i] >= 'a' && origin[i] <= 'z') {
                origin[i] = origin[i] - ' ';
            }
            //不相同就加入到输出的数组里面
            result[indexResult++] = origin[i];
        } else {
            //相等则说明是相同的 则该键位没坏
            indexNow++;
        }
    }
    for (int j = 0; j < indexResult; ++j) {
        //加一个标记位
        int tag = 0;
        for (int i = 0; i < j; ++i) {
            //如果当前的字符 和之前的字符相同了，那么就不输出
            if (result[i] == result[j]) {
                tag = 1;
                break;
            }
        }
        if (tag) {
            //跳出当前循环
            continue;
        }
        //输出数字
        if (result[j] >= '0' && result[j] <= '9') {
            printf("%d", result[j] - '0');
        } else {
            //输出字符
            printf("%c", result[j]);
        }
    }
    return 0;
}
