#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
    static const char codeMap[26] = {
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '0', '0', '2', '0', '2'
    };
    if (isalpha(c)) {
        return codeMap[toupper(c) - 'A'];
    }
    return '0';
}

void generateSoundex(const char *name, char *soundex) {
    if (name[0] == '\0') {
        strcpy(soundex, "0000");
        return;
    }

    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != soundex[sIndex - 1]) {
            soundex[sIndex++] = code;
        }
    }

    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H
