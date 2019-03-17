#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class StringSolution
{
public:
	StringSolution();
	~StringSolution();
	
    void reverseSentence(char pStr[]); // 1: 不花额外的空间
    size_t getFirstNoRepeatCh(char str[]); // 2
    char * leftConverseStr(char *pStr,int m); // 4 也是双重reverse
    char * delChar(char *pSource, char *pDel); // 5
    int getLongestSymmetricalLength(char *pStr); // 6
    
    bool atoi_my(const char *pStr, int &intValue);
    vector<string> split1(const string &str, const string &pattern);
    vector<string> split2(const string &str, const char &pattern);
    vector<string> split3(const char *str, const char &pattern);

private:
    void reverseString(char pStr[], size_t lo, size_t hi); // [lo, hi]
};

 
