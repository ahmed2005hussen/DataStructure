#include <iostream>
#include <stack>

using namespace std;

string bigInteger(stack<char> &sa, stack<char> &sb) {
    stack<char> res;
    string result;
    int carry = 0;
    while (!sa.empty() && !sb.empty()) {
        int n = sa.top() - '0';
        int m = sb.top() - '0';

        sa.pop();
        sb.pop();
        int value = n + m + carry;

        if (value > 9) {
            int element = value % 10;
            char e = element + '0';
            res.push(e);
            value /= 10;
            carry = value;
        } else {

            res.push(value + '0');

            carry = 0;
        }
    }

    while (!sa.empty()) {
        int n = sa.top() - '0';
        sa.pop();
        int value = n + carry;
        if (value > 9) {
            int element = value % 10;
            char e = element + '0';
            res.push(e);
            value /= 10;
            carry = value;
        }
        else {

            res.push(value + '0');

            carry = 0;
        }
    }

    while (!sb.empty()) {
        int n = sb.top() - '0';
        sb.pop();
        int value = n + carry;
        if (value > 9) {
            int element = value % 10;
            char e = element + '0';
            res.push(e);
            value /= 10;
            carry = value;
        }
        else {

            res.push(value + '0');

            carry = 0;
        }
    }

    while (!res.empty()) {
        result += res.top();
        res.pop();
    }
    return result;
}

int main() {
    string a = "592";
    string b = "3784";
    stack<char> sa;
    stack<char> sb;
    for (char i: a) {
        sa.push(i);
    }
    for (char i: b) {
        sb.push(i);
    }

    string result = bigInteger(sa, sb);
    cout << result;
}
