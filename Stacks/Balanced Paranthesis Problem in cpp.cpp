// Time Complexity: O(n) Auxiliary Space: O(n) for stack.

#include <bits/stdc++.h>
using namespace std;

bool checkPair(char val1, char val2) {
    return (( val1 == '(' && val2 == ')' ) || ( val1 == '[' && val2 == ']' ) || ( val1 == '{' && val2 == '}' ));
}

bool checkBalanced(string expr) {

    stack<char> s;

    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
            s.push(expr[i]);
        }
        else
        {
            // exp = {{}}}{}
            // if you look closely above {{}} will be matched with pair, Thus, stack "Empty"
            //but an extra closing parenthesis like } will never be matched
            //so there is no point looking forward
            if (s.empty())
                return false;
            else if (checkPair(s.top(), expr[i]))
            {
                s.pop();
                continue;
            }
            // will only come here if stack is not empty
            // pair wasn't found and it's some closing parenthesis
            //Example : {{}}(]
            return false;
        }
    }
    return s.empty();
}

int main()
{
    string expr = "({})[]";

    checkBalanced(expr) ? cout << "Balanced" : cout << "Not Balanced";

    return 0;
}