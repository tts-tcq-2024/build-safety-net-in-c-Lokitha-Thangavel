#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
    char soundex[5];
    generateSoundex("AX", soundex);
    ASSERT_STREQ(soundex, "A200");
}

TEST(SoundexTestsuite, IgnoresNonAlphabeticCharacters) {
    char soundex[5];
    generateSoundex("A1X", soundex);
    ASSERT_STREQ(soundex, "A200");
}

TEST(SoundexTestsuite, HandlesEmptyString) {
    char soundex[5];
    generateSoundex("", soundex);
    ASSERT_STREQ(soundex, "0000");
}

TEST(SoundexTestsuite, HandlesSingleCharacterString) {
    char soundex[5];
    generateSoundex("A", soundex);
    ASSERT_STREQ(soundex, "A000");
}

TEST(SoundexTestsuite, HandlesAlreadyCodedString) {
    char soundex[5];
    generateSoundex("BFPV", soundex);
    ASSERT_STREQ(soundex, "B000");
}

TEST(SoundexTestsuite, HandlesDifferentSoundexCodesForSameChar) {
    char soundex[5];
    generateSoundex("CGJKQSXZ", soundex);
    ASSERT_STREQ(soundex, "C000");
}

TEST(SoundexTestsuite, HandlesVowelCharacters) {
    char soundex[5];
    generateSoundex("AEIOUHWY", soundex);
    ASSERT_STREQ(soundex, "A000");
}

TEST(SoundexTestsuite, HandlesMultipleSameSoundexCodeCharacters) {
    char soundex[5];
    generateSoundex("TTTT", soundex);
    ASSERT_STREQ(soundex, "T000");
}

TEST(SoundexTestsuite, HandlesDifferentSoundexCodes) {
    char soundex[5];
    generateSoundex("ABCDEFG", soundex);
    ASSERT_STREQ(soundex, "A123");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
