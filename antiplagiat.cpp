#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

bool isSeparator(char c);
string textWithoutSeparators(string text);

int findWords(string text, string textForFind);
void splitToThree(string &twfc, string &delWord, string txt);

int main()
{
    string text = "test1 test2 test3 test4 test5 test6 test7 test8 test9";
    string documentText = textWithoutSeparators(text);

    string userText = textWithoutSeparators("test2 test3 test4 test5 test6");

    string threeWordsForCheck = "";
    string delWord = "";


    splitToThree(threeWordsForCheck, delWord, userText);
    int size = findWords(userText, delWord);
    userText.replace(0, size + 1, "");
    cout << userText << endl;


    return 0;
}

void splitToThree(string &twfc, string &delWord, string txt)
{
    twfc = "";
    delWord = "";
    int count = 0;

    for (int i = 0; i < txt.size() - txt.size() % 3; i++){
        if (txt[i] == ' ')
            count++;
        if (count < 1)
            delWord += txt[i];
        if (count < 3)
            twfc += txt[i];
        else
            break;
    }
}

bool isSeparator(char c)
{
    char s[] = ",.!;?:-+";
    for (int i = 0; s[i] != '\0'; i++)
        if (c == s[i])
            return true;

    return false;
}

string textWithoutSeparators(string text)
{
    string newText;
    for (int i = 0; i < text.size(); i++) {
        if (isSeparator(text[i])) continue;
        newText += tolower(text[i]);
    }
    return newText;
}

int findWords(string text, string textForFind)
{
    int j = 0;
    for (int i = 0; i < text.size(); i++){
        if (text[i] == textForFind[j])
            j++;
        else if (j == textForFind.size())
            return i;
        else
            j = 0;
    }
    return -1;
}
