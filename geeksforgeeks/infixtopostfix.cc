#include <bits/stdc++.h>
using namespace std;

string postfix(string& iexpr) {
	stack<char> evalstack;
	string pexpr;
	for (char x: iexpr) {
		switch(x) {
			case '+':
			case '-':
				while(evalstack.size() && (evalstack.top() == '*' || evalstack.top() == '/' || evalstack.top() == '^')) {
					pexpr += evalstack.top();
					evalstack.pop();
				}
				evalstack.push(x);
				break;
			case '*':
			case '/':
			case '(':
			case '^':
				evalstack.push(x);
				break;
			case ')':
				while(evalstack.top() != '(') {
					pexpr += evalstack.top();
					evalstack.pop();
				}
				evalstack.pop();
				break;
			default:
				pexpr += x;
				break;
		}
	}
	while(evalstack.size()) {
		pexpr += evalstack.top();
		evalstack.pop();
	}
	return pexpr;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string expr;
		cin >> expr;
		cout << postfix(expr) << endl;
	}
}