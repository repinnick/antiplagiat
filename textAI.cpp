#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

bool isSeparator(char c);
string textWithoutSeparators(string text);

int findWords(string text, string textForFind);
void splitToThree(string twfc, string txt);

int main()
{
    string text = "test1 test2 test3 test4 test5 test6 test7 test8 test9";
    string redactText = textWithoutSeparators(text);

    string otherRedactText = textWithoutSeparators("test2 test3 test4 test5 test6");

    string threeWordsForCheck;

    string word;
    
    int count = 0;
    
    
	splitToThree(threeWordsForCheck, otherRedactText);
	
	
	cout << findWords(redactText, otherRedactText);


    return 0;
}

void splitToThree(string twfc, string txt)
{
	int count = 0;
    
	for (int i = 0; i < txt.size(); i++){
		if (txt[i] == ' '){
			count++;
		}
	  	if (count < 3){
			twfc[i] = txt[i];
			//cout << threeWordsForCheck[i];
		}
		else{
			//cout << endl;
			count = 0;
		}
		
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
            return j;
        else
            j = 0;
    }
    return -1;
}
