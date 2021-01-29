#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

#define SELECTION_WORDS 3

using namespace std;

bool isSeparator(char c);
string textWithoutSeparators(string text);
int findWords(string text, string textForFind);
int wordCounter(string userText);
void addWordsInArray(string userText, string words[]);
int checkWordsInText(int size, string words[], string documentText);
int plagiatDetector(int size, int coincidences);
int sumOfNotSelection();

int main()
{
    string documentText = textWithoutSeparators("Baseball became popular in Japan after American soldiers introduced it during the occupation following World War II. In the 1990s a Japanese player, Hideo Nomo, became a star pitcher for the Los Angeles Dodgers. Baseball is also widely played in Cuba and other Caribbean nations. In the 1996 Olympics, it was a measure of baseball’s appeal outside the United States that the contest for the gold medal was down to Japan and Cuba (Cuba won).");
    string userText = textWithoutSeparators("Baseball become popular in Japan ofter American soldiers introduct it during the occupation following World War second. In the 1990s a Japanese player, Hideo Nomo, became a star pitcher for the Los Angeles Dodgers");

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
            return SELECTION_WORDS;
        else
            j = 0;
    }
    return 0;
}

int wordCounter(string userText)
{
    int counter = 0;

    for (int i = 0; i <= userText.size(); i++)
        if (userText[i] == ' ' or i == userText.size())
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
    int finish = SELECTION_WORDS - 1;

    for (int i = 0; i < size - finish; i++){
        int wCount = 0;
        while (wCount < SELECTION_WORDS){
            if (wCount == SELECTION_WORDS - 1)
                threeWordsForCheck += (words[i + wCount]);
            else threeWordsForCheck += (words[i + wCount] + " ");

            wCount++;
        }
        counter += findWords(documentText, threeWordsForCheck);
        threeWordsForCheck = "";
    }
    return counter;
}

int plagiatDetector(int size, int coincidences)
{
    int common = (size * SELECTION_WORDS) - (2 * sumOfNotSelection());
    return (coincidences * 100) / common;
}

int sumOfNotSelection(){
    int sum = 0;
    for (int i = 0; i < SELECTION_WORDS; i++){
        sum += i;
    }
    return sum;
}
