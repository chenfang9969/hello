#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;

// 计算部分匹配表（lps数组）
void computeLPSArray(char* pattern, int M, int* lps) {
    int len = 0; // 已匹配的前缀长度
    lps[0] = 0; // 初始化第一个字符的部分匹配值为0
    int i = 1;
    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len; // 更新部分匹配值
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // 回溯到前一个字符的部分匹配值
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP搜索算法
void KMPSearch(char* pattern, char* text) {
    int M = strlen(pattern); // 模式串长度
    int N = strlen(text);    // 文本串长度

    int lps[M]; // 存储部分匹配表
    computeLPSArray(pattern, M, lps); // 计算部分匹配表

    int i = 0; // text中的索引
    int j = 0; // pattern中的索引
    while (i < N) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }
        if (j == M) { // 完全匹配pattern
            cout<<"匹配到的位置为"<<i - j; // 打印匹配的位置索引
            j = lps[j - 1]; // 回溯到前一个字符的部分匹配值
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1]; // 回溯到前一个字符的部分匹配值
            } else {
                i = i + 1;
            }
        }
    }
    cout<<"未匹配到字符";
}

int main() {
	char text[100];
	char pattern[100];
    cout<<"请输入文本字符：";
    	cin>>text;
	cout<<"请输入匹配字符：";
    	cin>>pattern;
    cout<<("Text: %s\n", text);
    cout<<("Pattern: %s\n", pattern);
    cout<<("Matching positions:\n");
    KMPSearch(pattern, text);
    return 0;
}

