#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>

using namespace std;

int prec(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isOperator(char c) {
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}

// ^ is right associative
bool isRightAssociative(char op) {
    return op == '^';
}

string stackToString(stack<char> s) {
    // show from bottom -> top
    if (s.empty()) return "EMPTY";
    string tmp;
    // move to array to reverse
    vector<char> v;
    while (!s.empty()) { v.push_back(s.top()); s.pop(); }
    // v has top->bottom, we want bottom->top
    for (int i = (int)v.size()-1; i >= 0; --i) {
        tmp.push_back(v[i]);
    }
    return tmp;
}

int main() {
    string infix;
    cout << "Enter infix expression (example: a-b*c-d/e+f): ";
    getline(cin, infix);
    // If user just presses enter, use example
    if (infix.size() == 0) infix = "a-b*c-d/e+f";

    cout << "\nConverting infix: " << infix << "\n\n";

    stack<char> st;
    string output;

    // Print header
    cout << left << setw(6) << "Step" 
         << setw(10) << "Read" 
         << setw(30) << "Action" 
         << setw(18) << "Stack(bottom->top)" 
         << "Postfix\n";
    cout << string(80, '-') << "\n";

    int step = 0;
    for (size_t i = 0; i < infix.size(); ++i) {
        char c = infix[i];
        if (isspace((unsigned char)c)) continue; // ignore spaces

        step++;
        string action;

        if (isalnum((unsigned char)c)) { // operand (letter/digit)
            output.push_back(c);
            action = "Operand -> append to output";
        } 
        else if (c == '(') {
            st.push(c);
            action = "Push '(' onto stack";
        }
        else if (c == ')') {
            // pop until '('
            if (st.empty()) {
                action = "Error: unmatched ')'";
            } else {
                while (!st.empty() && st.top() != '(') {
                    output.push_back(st.top());
                    st.pop();
                }
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                    action = "Pop until '(' removed";
                } else {
                    action = "Error: '(' not found";
                }
            }
        }
        else if (isOperator(c)) {
            // pop while top has higher precedence OR equal precedence and left associative
            string details;
            while (!st.empty() && isOperator(st.top())) {
                char topOp = st.top();
                int pTop = prec(topOp);
                int pCur = prec(c);

                if ( (pTop > pCur) || (pTop == pCur && !isRightAssociative(c)) ) {
                    // pop topOp
                    st.pop();
                    output.push_back(topOp);
                    details += string(" pop ") + topOp;
                } else {
                    break;
                }
            }
            st.push(c);
            action = string("Push operator '") + c + "'" + (details.empty() ? "" : ("," + details));
        } 
        else {
            action = string("Ignored/Unknown char '") + c + "'";
        }

        cout << setw(6) << step 
             << setw(10) << c 
             << setw(30) << action 
             << setw(18) << stackToString(st) 
             << output << "\n";
    }

    // End of input: pop remaining ops
    step++;
    string action = "End -> pop remaining operators";
    while (!st.empty()) {
        if (st.top() == '(' || st.top() == ')') {
            // mismatched parentheses
            st.pop(); // discard
        } else {
            output.push_back(st.top());
            st.pop();
        }
    }
    cout << setw(6) << step 
         << setw(10) << "END" 
         << setw(30) << action 
         << setw(18) << stackToString(st) 
         << output << "\n";

    cout << "\nFinal Postfix expression: " << output << "\n";
    return 0;
}
