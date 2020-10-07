// TODO: remove and replace this file header comment
// This is a .cpp file you will edit and turn in.
// Remove starter comments and add your own
// comments on each function and on complex code sections.
#include "testing/SimpleTest.h"
#include "strlib.h"
#include "filelib.h"
#include <fstream>
#include <cctype>
#include <string>
#include <map>
using namespace std;

/* This function takes a string s and returns a version of
 * the string that has all non-letter characters removed
 * from it.
 *
 * WARNING: The provided code is buggy!
 *
 * Use unit tests to identify which inputs to this function
 * are incorrectly handled. Then, remove this comment and
 * replace it with a description of the bug you fixed.
 */
string removeNonLetters(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (!isalpha(s[i])) {
            // remove the character at index i
            s = s.substr(0,i) + s.substr(i+1);
        }
    }
    return s;
}


/* TODO: Replace this comment with a descriptive function
 * header comment.
 */
string soundex(string s) {
    /* TODO: Fill in this function. */
    char F;
    char temp;
    int i, j;

    //保存第一个字母，并将其转换成大写
    for(i = 0; i < s.length(); i++){
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] -= 32;
        }
    F = s[0];

    map<char, char> m;         //把字母和数字相对应

    m['A'] = m['E'] = m['I'] = m['O'] = m['U'] = m['H'] = m['W'] = m['Y'] = '0';
    m['B'] = m['F'] = m['P'] = m['V'] = '1';
    m['C'] = m['G'] = m['J'] = m['K'] = m['Q'] = m['S'] = m['X'] = m['Z'] = '2';
    m['D'] = m['T'] = '3';
    m['L'] = '4';
    m['M'] = m['N'] = '5';
    m['R'] = '6';

    for( i = 0; i < s.length(); i++){     //合并代码中的相邻重复数字
        s[i] = m[s[i]];
        for( j = 1; j < s.length(); j++)
        {
            s[j] = m[s[j]];
            if (s[j] == s[i])
                break;
        }
        if(j == s.length())
            s+=s[i];
    }
    s[0] = F;         //将第一个数字用保存的大写字母替换

    for (i = 1; i < s.length(); i++) {       //删除代码中的所有的数字0
        if (s[i] == '0') {
            s = s.substr(0,i) + s.substr(i+1);
        }
    }

    for (i = s.size(); i < 4; i++)   //用0补齐使代码长度为4
        s[i] = '0';

    return s;
}


/* TODO: Replace this comment with a descriptive function
 * header comment.
 */
void soundexSearch(string filepath) {
    // The proivded code opens the file with the given name 
    // and then reads the lines of that file into a vector.
    ifstream in;
    Vector<string> databaseNames;

    if (openFile(in, filepath)) {
        readEntireFile(in, databaseNames);
    }
    cout << "Read file " << filepath << ", "
         << databaseNames.size() << " names found." << endl;

    // The names in the database are now stored in the provided
    // vector named databaseNames

    /* TODO: Fill in the remainder of this function. */
}


/* * * * * * Test Cases * * * * * */


PROVIDED_TEST("Test removing puntuation, digits, and spaces") {
    string s = "O'Hara";
    string result = removeNonLetters(s);
    EXPECT_EQUAL(result, "OHara");
    s = "Planet9";
    result = removeNonLetters(s);
    EXPECT_EQUAL(result, "Planet");
    s = "tl dr";
    result = removeNonLetters(s);
    EXPECT_EQUAL(result, "tldr");
}


PROVIDED_TEST("Sample inputs from handout") {
    EXPECT_EQUAL(soundex("Master"), "M236");
    EXPECT_EQUAL(soundex("Jue"), "J000");
}

PROVIDED_TEST("hanrahan is in lowercase") {
    EXPECT_EQUAL(soundex("hanrahan"), "H565");
}

PROVIDED_TEST("DRELL is in uppercase") {
    EXPECT_EQUAL(soundex("DRELL"), "D640");
}

PROVIDED_TEST("Liu has to be padded with zeros") {
    EXPECT_EQUAL(soundex("Liu"), "L000");
}

PROVIDED_TEST("Tessier-Lavigne has a hyphen") {
    EXPECT_EQUAL(soundex("Tessier-Lavigne"), "T264");
}

PROVIDED_TEST("Au consists of only vowels") {
    EXPECT_EQUAL(soundex("Au"), "A000");
}

PROVIDED_TEST("Egilsdottir is long and starts with a vowel") {
    EXPECT_EQUAL(soundex("Egilsdottir"), "E242");
}

PROVIDED_TEST("Jackson has three adjcaent duplicate codes") {
    EXPECT_EQUAL(soundex("Jackson"), "J250");
}

PROVIDED_TEST("Schwarz begins with a pair of duplicate codes") {
    EXPECT_EQUAL(soundex("Schwarz"), "S620");
}

PROVIDED_TEST("Van Niekerk has a space between repeated n's") {
    EXPECT_EQUAL(soundex("Van Niekerk"), "V526");
}

PROVIDED_TEST("Wharton begins with Wh") {
    EXPECT_EQUAL(soundex("Wharton"), "W635");
}

PROVIDED_TEST("Ashcraft is not a special case") {
    // Some versions of Soundex make special case for consecutive codes split by hw
    // We do not make this special case, just treat same as codes split by vowel
    EXPECT_EQUAL(soundex("Ashcraft"), "A226");
}

// TODO: add your test cases here
STUDENT_TEST("Test removing puntuation, digits, and spaces") {
    string s;
    s = "O'Hara";
    EXPECT_EQUAL(removeNonLetters(s), "OHara");

    s = "Planet9";
    EXPECT_EQUAL(removeNonLetters(s), "Planet");

    s = "tl dr";
    EXPECT_EQUAL(removeNonLetters(s), "tldr");

    s = "_mls_";
    EXPECT_EQUAL(removeNonLetters(s), "mls");
}

STUDENT_TEST("soundex") {
    string s;
    s = "Zelenski";
    EXPECT_EQUAL(soundex(s), "Z452");
}

