#include <iostream>
#include <stack>
using namespace std;

// This function uses a stack to match opening and closing brackets. bool isBalanced(string expr) {
stack<char> s;
for (char ch : expr) {
if (ch == '(' || ch == '[' || ch == '{') { s.push(ch);
}
else if (ch == ')' || ch == ']' || ch == '}') {

if (s.empty()) return false;

char top = s.top(); s.pop();

if ((ch == ')' && top != '(') ||
(ch == ']' && top != '[') ||
 
(ch == '}' && top != '{')) { return false;
}
}
}

return s.empty();
}

int main() {
cout << isBalanced("(a + [b * {c + d}])") << endl; cout << isBalanced("{a + (b - [c]}") << endl;

return 0;
}
