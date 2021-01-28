#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

bool isSeparator(char c);
string textWithoutSeparators(string text);
int findWords(string text, string textForFind);
int wordCounter(string userText);
void addWordsInArray(string userText, string words[]);
int checkWordsInText(int size, string words[], string documentText);
int plagiatDetector(int size, int coincidences);

int main()
{
    string documentText = textWithoutSeparators("test1 test2 test3 test4 test5 test6 test7 test8 test9");
    string userText = textWithoutSeparators("test2 teñt3 test4 test456 test4");

    const int arraySize = wordCounter(userText);
    string words[arraySize] = {};

    addWordsInArray(userText, words);

    int coincidences = checkWordsInText(arraySize, words, documentText);
    cout << "Plagiat is: " << plagiatDetector(arraySize, coincidences) << "%";

    return 0;
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
            return 3;
        else
            j = 0;
    }
    return 0;
}

int wordCounter(string userText)
{
    int counter = 0;

    for (int i = 0; i <= userText.size(); i++)
        if (userText[i] == ' ' or i + 1 == userText.size())
            counter++;

    return counter;
}

void addWordsInArray(string userText, string words[])
{
    string word = "";
    int wc = 0;
    for (int i = 0; i <= userText.size(); i++)
        if (userText[i] == ' ' or i == userText.size()){
            words[wc] = word;
            wc++;
            word = "";
        }
        else{
            word += userText[i];
        }
}

int checkWordsInText(int size, string words[], string documentText)
{
    string threeWordsForCheck = "";
    int counter = 0;
    for (int i = 0; i < size - 2; i++){
        threeWordsForCheck += (words[i] + " ");
        threeWordsForCheck += (words[i + 1] + " ");
        threeWordsForCheck += words[i + 2];
        counter += findWords(documentText, threeWordsForCheck);
        threeWordsForCheck = "";
    }
    return counter;
}

int plagiatDetector(int size, int coincidences)
{
    int common = size * 3 - 6;
    return (coincidences * 100) / common;
}
