#include<iostream>
#include<stack>
#include<string>
#include<list>
#include<map>
#include <utility>

using namespace std;

class Expression {
  map<string, int> precedence;
  list<string> infix_tokens;
  list<string> postfix_tokens;
  string exp;

  public:
    Expression() {
      precedence.insert(pair<string, int>("^", 4));
      precedence.insert(pair<string, int>("/", 3));
      precedence.insert(pair<string, int>("*", 3));
      precedence.insert(pair<string, int>("+", 2));
      precedence.insert(pair<string, int>("-", 2));
      precedence.insert(pair<string, int>("(", 1));
    }
    void Evaluate(string str);
    void Tokenize();
    void InfixToPostfix();
};

void Expression::Evaluate(string str) {
  exp = std::move(str);
  cout << "Expression : " << exp << endl;
  Tokenize();
  InfixToPostfix();
}

// Tokenize individual characters into operators and operands
void Expression::Tokenize() {
  int sz = exp.size();
  string token("");

  int i;
  for (i = 0; i < sz - 1; i++) {
    char p = exp.at(i);
    // If the current character is an operator or a bracket we store it in the
    // token list and flush the token.
    if (p == '+' || p == '-' || p == '/' || p == '*' || p == '^' || p == '(' or p == ')') {
      token = p;
      infix_tokens.push_back(token);
      token = "";
    } else {
      token += p;
      // If the next character is not a digit, it means the number is done
      // so we push it to the token list and flush the token.
      if (!(exp.at(i + 1) >= '0' && exp.at(i + 1) <= '9')) {
        infix_tokens.push_back(token);
        token = "";
      }
    }
  }

  // If the last character is a number, it means the token still contains a part of the number.
  // So we append the last character to the previously stored number in the token and thus
  // we have the complete number.
  if (exp.at(i) >= '0' && exp.at(i) <= '9') {
    token += exp.at(sz - 1);
  } else {
    token = exp.at(sz - 1);
  }
  infix_tokens.push_back(token);
}

void Expression::InfixToPostfix() {
  stack<string> stk;
  stk.push("("); // The extra "(" is necessary so that the popping operation doesn't go on forever.
  infix_tokens.push_back(")");

  while (!infix_tokens.empty()) {
    string token = infix_tokens.front();
    infix_tokens.pop_front();

    if (token == "(") {
      stk.push(token);
    } else if (token == ")") {
      // Pop out all the operators and append them to postfix expression till an opening bracket is found
      while (stk.top() != "(") {
        postfix_tokens.push_back(stk.top());
        stk.pop();
      }
      stk.pop();
    } else if (token == "*" || token == "/" || token == "+" || token == "-" || token == "^") {
      // Pop out operators with higher precedence at the top of the stack and append them to
      // the postfix expression, before pushing the current operator to the stack.
      while (!stk.empty() && precedence[stk.top()] >= precedence[token]) {
        postfix_tokens.push_back(stk.top());
        stk.pop();
      }
      stk.push(token);
    } else {
      // Positions of the operands do not change in the postfix expression so append
      // an operand as it is.
      postfix_tokens.push_back(token);
    }
  }

  cout << "Postfix Expression :";
  for (auto &i: postfix_tokens)
    cout << i << ",";
  cout << endl << endl;

  postfix_tokens.clear();
}

int main() {
  string str("110+50");
  string str2("110+50+(4-2*5)-10+40");
  string str3("(110+50)*(2-4)");
  string str4("2^5*(3-4)");
  string str5("2^5");
  string str6("0-8-0-5^3");

  Expression e;
  e.Evaluate(str);
  e.Evaluate(str2);
  e.Evaluate(str3);
  e.Evaluate(str4);
  e.Evaluate(str5);
  e.Evaluate(str6);

  return 0;
}
