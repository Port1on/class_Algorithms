/*
 * CS 106B/X Sample Project
 * last updated: 2018/09/19 by Marty Stepp
 *
 * This project helps test that your Qt Creator system is installed correctly.
 * Compile and run this program to see a console and a graphical window.
 * If you see these windows, your Qt Creator is installed correctly.
 */

#include <iostream>
#include "console.h"
#include "ginteractors.h" // for GWindow
#include "gwindow.h" // for GWindow
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
#include <fstream>
#include <filelib.h>

using namespace std;
bool parenAreBalancedIn(string text);
bool isOpens(char ch);
bool isCloses(char ch);
char isMatch(char ch);

int main() {
    ifstream in;
    string filePath = "./src/hello.cpp";
    Vector<string> lines;
    string line;
    if(openFile(in, filePath)) {
        readEntireFile(in, lines);
    }
    for (string l:lines) {
        line += l;
    }
    //string text = getLine("Enter a line:");

    if(parenAreBalancedIn(line)) {
        cout << "Yes!" <<endl;
    } else {
        cout << "No!" << endl;
    }

    return 0;
}


bool parenAreBalancedIn(string text)
{
    Stack<char> opens;
    for (char ch : text) {
        if(isOpens(ch))
        {
            opens.push(ch);
        }
        else if(isCloses(ch))
        {
            if(opens.isEmpty())
            {
                return false;
            }
            else if(isMatch(ch)==opens.top())
            {
                opens.pop();
            }
            else
            {
                return false;
            }
        }
    }


    return opens.isEmpty();
}

bool isOpens(char ch)
{
    return ch=='(' || ch=='[' || ch=='{';
}

bool isCloses(char ch)
{
    return ch==')' || ch==']' || ch=='}';
}

char isMatch(char ch)
{
    switch(ch)
    {
    case ')': return '('; break;
    case ']': return '['; break;
    case '}': return '{'; break;
    default : return 0; break;
    }

    return 0;
}
