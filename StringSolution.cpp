#include "StringSolution.h"


StringSolution::StringSolution()
{
}


StringSolution::~StringSolution()
{
}

bool StringSolution::atoi_my(const char *pStr, int &intValue)
{
    // nullptr // flag // overflow // non digit character
    const char *pChar = pStr;
    int flag = 1;
    bool isValid = true;
    __int64_t s = 0;
    if (pStr == nullptr)
        return false;
    if (*pChar == '-')
    {
        flag = -1;
        pChar++;
    }
    else
    {
        if (*pChar == '+')
            pChar++;
    }
    while (*pChar != '\0')
    {
        if (*pChar <= '9' && *pChar >= '0') // bug
        {
            s = 10 * s + (*pChar - '0');
            if (s > std::numeric_limits<int>::max())
            {
                isValid = false;
                s = 0;
                break;
            }
        }
        else
        {
            isValid = false;
            s = 0;
            break;
        }
    }
    if (*pChar == '\0')
    {
        if (flag < 0)
            s = 0 - s;
        intValue = static_cast<int>(s);
    }
    return isValid;
}

vector<string> StringSolution::split1(const string &str, const string &pattern)
{
    // size_t = str.find(pattern), string = substr(pos, len)
    // 每次找到一个word以后，用substr来切割原字符串
    vector<string> res;
    if (str == "")
        return res;
    string strpat = str + pattern;
    size_t pos = strpat.find(pattern);
    
    while (pos != strpat.npos) {
        string temp = strpat.substr(0, pos);
        res.push_back(temp);
        strpat = strpat.substr(pos+1, strpat.size());
        pos = strpat.find(pattern);
    }
    
    return res;
}

vector<string> StringSolution::split2(const string &str, const char &pattern)
{
    vector<string> res;
    if (str == "") return res;
    stringstream input(str);
    string temp;
    while (getline(input, temp, pattern))
        res.push_back(temp);
    return res;
}

vector<string> StringSolution::split3(const char *str, const char &pattern)
{
    vector<string> res;
    if (strlen(str) == 0) return res;
    stringstream input(str);
    string temp;
    while (getline(input, temp, pattern))
        res.push_back(temp);
    return res;
}

void StringSolution::reverseString(char pStr[], size_t lo, size_t hi)
{
    while (lo < hi) {
        char tmp;
        tmp = pStr[lo];
        pStr[lo] = pStr[hi];
        pStr[hi] = tmp;
        
        //swap(pStr[lo], pStr[hi]);
        lo++; hi--;
    }
}

void StringSolution::reverseSentence(char pStr[])
{
    size_t len = strlen(pStr);
    if (len <= 1) return;
    
    reverseString(pStr, 0, len-1);
    const char pattern = ' ';
    size_t lo = 0;
    size_t hi = 0;
    while (pStr[hi] != '\0') {
        if (pStr[hi] == pattern) {
            reverseString(pStr, lo, hi-1);
            lo = hi + 1;
        }
        hi++;
    }
    reverseString(pStr, lo, hi-1);
}

size_t StringSolution::getFirstNoRepeatCh(char str[])
{
    size_t len = strlen(str);
    int count[len];
    for (int i = 0; i < len; i++)
        count[i] = 0;
    
    for (int i = 0; i < len; i++)
        count[str[i]]++;
    for (int i = 0; i < len; i++) {
        if (count[str[i]] == 1)
            return i;
    }
    
    return -1; // bug
}

char * StringSolution::delChar(char *pSource, char *pDel)
{
    bool hashT[256] = {false};
    for (int i = 0; pDel[i] != '\0'; i++) {
        hashT[pDel[i]] = true;
    }
    
    char *pChar=pDel;
    while(*pChar!='\0')
    {
        hashT[*pChar]=1;
        pChar++;
    }
    char *pFast=pSource,*pSlow=pSource;
    while(*pFast != '\0')
    {
        if(hashT[*pFast] != 1)
        {
            *pSlow=*pFast;
            pSlow++;
        }
        pFast++;
    }
    *pSlow='\0';
    return pSource;
}
