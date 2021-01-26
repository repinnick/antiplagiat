#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isSeparator(char c);
string textWithoutSeparators(string text);

int findWords(string text, string textForFind);

int main()
{
    string text = "Children start school at the age of five, but there is some free nursery-school education before that age. The state nursery schools are not for all. They are for some families, for example for families with only one parent. In most areas there are private nursery schools. Parents who want their children to go to nursery school pay for their children under 5 years old to go to these private nursery schools";
    string redactText = textWithoutSeparators(text);

    string otherRedactText = textWithoutSeparators("Children are start school at the age of 5, but there are some free nursery-school education before that age. The state nursery school is not for all. Happy are for some families, for examples for family with only one parent.");

    string threeWordsForCheck;

    string word;
    int iw = 0;

    cout << findWords(redactText, "nursery schools");

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
            return j;
        else
            j = 0;
    }
    return -1;
}
