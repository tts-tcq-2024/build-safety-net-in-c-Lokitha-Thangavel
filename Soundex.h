#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) 
{
    static const char codeMap[26] = 
    {
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '0', '0', '2', '0', '2'
    };
    if (isalpha(c)) 
    {
        return codeMap[toupper(c) - 'A'];
    }
    return '0';
}

void padWithZeros(char *soundex, int startIndex) 
{
    while (startIndex < 4) 
    {
        soundex[startIndex++] = '0';
    }
    soundex[4] = '\0';
}

void generateSoundex(const char *name, char *soundex)
{
    if (name[0] == '\0')
    {
        strcpy(soundex, "0000");
        return;
    }
    
    soundex[0] = toupper(name[0]);
    int sIndex = 1;
    char prevCode = getSoundexCode(soundex[0]);

    for (int i = 1; name[i] != '\0' && sIndex < 4; i++) 
    {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != prevCode) 
        {
            soundex[sIndex++] = code;
            prevCode = code;
        }
    }
    padWithZeros(soundex, sIndex);    
}

#endif // SOUNDEX_H
