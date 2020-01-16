//
//  main.cpp
//  eval.cpp
//
//  Created by Ojas Bardiya on 5/1/19.
//  Copyright © 2019 Ojas bardiya. All rights reserved.

#include <iostream>
#include <string>
#include <cctype>
#include <stack>
#include <cassert>

using namespace std;

bool checkInfix(string infix);
string convertToPostfix(string infix, string& postfix);
int orderofPrecdence(char ch);

int evaluate(string infix, string& postfix, bool& result)
{
    if (checkInfix(infix) == false)
    {
        return 1;
    }
    postfix = convertToPostfix(infix, postfix);
    if (postfix.size() == 0)
    {
        return 1;
    }
    stack<bool> operandStack;
    for (int i = 0; i < postfix.size(); i++)
    {
        char ch = postfix.at(i);
        if (postfix.at(i) == 'T' || postfix.at(i) == 'F')
        {
            switch (ch)
            {
                case 'T':
                    operandStack.push(true);
                    break;
                case 'F':
                    operandStack.push(false);
                    break;
            }
        }
        else if (postfix.at(i) == '!')
        {
            if (operandStack.top() == true)
            {
                operandStack.pop();
                operandStack.push(false);
            }
            else
            {
                operandStack.pop();
                operandStack.push(true);
            }
        }
        else
        {
            bool operand2 = operandStack.top();
            operandStack.pop();
            bool operand1 = operandStack.top();
            operandStack.pop();
            if (postfix.at(i) == '^')
            {
                if ((operand1 == true && operand2 == false)|| (operand1 == false && operand2 == true))
                    {
                        operandStack.push(true);
                    }
                else
                    {
                        operandStack.push(false);
                    }
            }
            if (postfix.at(i) == '&')
            {
                if (operand1 == true && operand2 == true)
                {
                    operandStack.push(true);
                }
                else
                {
                    operandStack.push(false);
                }
            }
        }
    }
    result = operandStack.top();
    return 0;
}

int orderofPrecdence(char ch)
{
    switch(ch)
    {
        case '^':
            return 0;
        case '&':
            return 1;
        case '!':
            return 2;
        default:
            return -1;
    }
}

bool checkInfix(string infix)
{
    const char openBracket = '(';
    const char closeBracket = ')';
    int count1 = 0;
    int count2 = 0;
    bool value = true;
    string temp = "";
    for (int i = 0; i < infix.size(); i++) // removes all the whitespace
    {
        if (!isspace(infix.at(i)))
        {
            temp += infix.at(i);
        }
    }
    for (int j = 0; j < temp.size(); j++)
    {
        if (temp.size() == 0)    // returns the empty string as false
        {
            value = false;
            return (value);
        }
        if ((temp.at(j) == '^' || temp.at(j) == '&' || temp.at(j) == closeBracket) && (j == 0)) //makes sure the beginning of the string is valid
        {
            value = false;
            return (value);
        }
        if (temp.at(temp.size() - 1) == '&' || temp.at(temp.size() - 1) == '^' || temp.at(temp.size() - 1) == '!') //makes sure that the end isn't a character
        {
            value = false;
            return (value);
        }
        if (temp.at(j) == 'T' || temp.at(j) == 'F')  // makes sure any T or F is in valid syntax
        {
            if ( j < temp.size() - 1)
            {
                if ((temp.at(j + 1) == 'T') || (temp.at(j + 1) == 'F') || (temp.at(j+1) == '!') || temp.at(j + 1) == openBracket)
                {
                    value = false;
                    return (value);
                }
            }

        }
        if (temp.at(j) == '&' || temp.at(j) == '^') //makes sure & and ^ are in valid syntax
        {
            if ((temp.at(j - 1) != 'T') && temp.at(j - 1) != 'F' && temp.at(j - 1) != closeBracket)
            {
                value = false;
                return (value);
            }
            if (temp.at(j+1) != 'T' && temp.at(j + 1) != 'F' && temp.at(j + 1) != '!' && temp.at(j + 1) != openBracket)
            {
                value = false;
                return (value);
            }
        }
        if (temp.at(j) == openBracket)  // makes sure '(' is in valid syntax
        {
            count1++;                   //keeps count of open parentheses
            if (j == temp.size() - 1)
            {
                value = false;
                return (value);
            }
            if (temp.at(j + 1) == closeBracket)
            {
                value = false;
                return (value);
            }
        }
        if (temp.at(j) == closeBracket) //keeps count of closed parentheses
        {
            count2++;
        }
    }
    if (count1 != count2) //makes sure the number of open and closed parentheses are the same
    {
        value = false;
        return (value);
    }
    return (value);
}

string convertToPostfix(string infix, string& postfix)
{
    postfix = "";
    stack<char> operatorStack;
    for (int i = 0; i < infix.size(); i++)
    {
        char ch = infix.at(i);
        switch (ch)
        {
            case 'T':
            case 'F':
                postfix += ch;
                break;
            case '(':
                operatorStack.push(ch);
                break;
            case ')':
                while (operatorStack.top() != '(')
                {
                    postfix += operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.pop();
                break;
            case '!':
            case '&':
            case '^':
                while (operatorStack.empty() == false && operatorStack.top() != '(' && orderofPrecdence(ch) <= orderofPrecdence(operatorStack.top()))
                {
                    postfix += operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.push(ch);
                break;
            default:
                break;
        }
    }
    while (operatorStack.empty() == false)
    {
        postfix += operatorStack.top();
        operatorStack.pop();
    }
    return (postfix);
}

int main()
{
    string pf;
    bool answer;
    assert(evaluate("T^ F", pf, answer) == 0  &&  pf == "TF^"  &&  answer);
    assert(evaluate("T^", pf, answer) == 1);
    assert(evaluate("F F", pf, answer) == 1);
    assert(evaluate("TF", pf, answer) == 1);
    assert(evaluate("()", pf, answer) == 1);
    assert(evaluate("()T", pf, answer) == 1);
    assert(evaluate("T(F^T)", pf, answer) == 1);
    assert(evaluate("T(&T)", pf, answer) == 1);
    assert(evaluate("(T&(F^F)", pf, answer) == 1);
    //assert(evaluate("T|F", pf, answer) == 1);
    assert(evaluate("", pf, answer) == 1);
    assert(evaluate("F  ^  !F & (T&F) ", pf, answer) == 0
           &&  pf == "FF!TF&&^"  &&  !answer);
    assert(evaluate(" F  ", pf, answer) == 0 &&  pf == "F"  &&  !answer);
    assert(evaluate("((T))", pf, answer) == 0 &&  pf == "T"  &&  answer);
    assert(evaluate("T^F^T", pf, answer) == 0 && pf == "TF^T^" && !answer);
    assert(evaluate("T&!(F^T&T^F)^!!!(F&T&F)", pf, answer) == 0 && answer);
    assert(evaluate("T&((F&T)", pf, answer) == 1);
    assert(evaluate("F&(&T)", pf, answer) == 1);
    //assert(evaluate("T&(F&T))&((T&T)", pf, answer) == 1);
    assert(evaluate("F|T", pf, answer) == 0);
    assert(evaluate("TF", pf, answer) == 1);
    cout << "Passed all tests" << endl;
}
