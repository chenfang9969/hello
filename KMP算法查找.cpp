#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;

// ���㲿��ƥ���lps���飩
void computeLPSArray(char* pattern, int M, int* lps) {
    int len = 0; // ��ƥ���ǰ׺����
    lps[0] = 0; // ��ʼ����һ���ַ��Ĳ���ƥ��ֵΪ0
    int i = 1;
    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len; // ���²���ƥ��ֵ
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // ���ݵ�ǰһ���ַ��Ĳ���ƥ��ֵ
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP�����㷨
void KMPSearch(char* pattern, char* text) {
    int M = strlen(pattern); // ģʽ������
    int N = strlen(text);    // �ı�������

    int lps[M]; // �洢����ƥ���
    computeLPSArray(pattern, M, lps); // ���㲿��ƥ���

    int i = 0; // text�е�����
    int j = 0; // pattern�е�����
    while (i < N) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }
        if (j == M) { // ��ȫƥ��pattern
            cout<<"ƥ�䵽��λ��Ϊ"<<i - j; // ��ӡƥ���λ������
            j = lps[j - 1]; // ���ݵ�ǰһ���ַ��Ĳ���ƥ��ֵ
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1]; // ���ݵ�ǰһ���ַ��Ĳ���ƥ��ֵ
            } else {
                i = i + 1;
            }
        }
    }
    cout<<"δƥ�䵽�ַ�";
}

int main() {
	char text[100];
	char pattern[100];
    cout<<"�������ı��ַ���";
    	cin>>text;
	cout<<"������ƥ���ַ���";
    	cin>>pattern;
    cout<<("Text: %s\n", text);
    cout<<("Pattern: %s\n", pattern);
    cout<<("Matching positions:\n");
    KMPSearch(pattern, text);
    return 0;
}

