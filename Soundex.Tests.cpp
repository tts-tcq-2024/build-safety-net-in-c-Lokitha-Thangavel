#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTestsuite, CombinedTestCases) {
    struct TestCase {
        const char* input;
        const char* expectedOutput;
    };

    TestCase testCases[] = {
        // Basic Soundex Functionality
        {"AX", "A200"},
        {"ABCDEFG", "A123"},

        // Edge Cases and Special Characters
        {"A1X", "A200"},
        {"", "0000"},
        {"A", "A000"},
        {"BFPV", "B000"},
        {"CGJKQSXZ", "C000"},
        {"AEIOUHWY", "A000"},
        {"TTTT", "T000"},

        // Complex Cases
        {"Broccoli", "B624"},
    };

    char soundex[5];
    for (const auto& testCase : testCases) {
        generateSoundex(testCase.input, soundex);
        ASSERT_STREQ(soundex, testCase.expectedOutput);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
