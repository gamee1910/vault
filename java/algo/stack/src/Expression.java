import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Stack;

class Expression {

  Map<String, Integer> precedence;
  List<String> infixTokens;
  List<String> postfixTokens;
  String expression;

  Expression() {

    precedence = new HashMap<>();
    precedence.put("^", 4);
    precedence.put("/", 3);
    precedence.put("*", 3);
    precedence.put("+", 2);
    precedence.put("-", 2);
    precedence.put("(", 1);

    infixTokens = new ArrayList<>();
    postfixTokens = new ArrayList<>();
  }

  void evaluate(String strexp) {
    expression = strexp;
    System.out.println("Main : " + expression);
    tokenize();
    infixToPostfix();
  }

  // Tokenize individual characters into operators and operands
  void tokenize() {

    StringBuilder token = new StringBuilder();
    int sz = expression.length();

    int i;
    for (i = 0; i < sz - 1; i++) {
      String pointer = String.valueOf(expression.charAt(i));

      if (List.of("+", "-", "/", "*", "^", "(", ")").contains(pointer)) {
        infixTokens.add(pointer);
      } else { // Character is a number

        token.append(pointer);
        // If the next character is not a digit, it means the number is done
        // so we push it to the token list and flush the token.
        if (!(expression.charAt(i + 1) >= '0' && expression.charAt(i + 1) <= '9')) {
          infixTokens.add(token.toString());
          token.setLength(0); // reset token
        }
      }
    }

    // If the last character is a number, it means the token still contains a part of the number.
    // So we append the last character to the previously stored number in the token and thus
    // we have the complete number.

    if (expression.charAt(i) >= '0' && expression.charAt(i) <= '9') {
      token.append(expression.charAt(sz - 1));
    } else {
      token.setLength(0); // reset token
      token.append(expression.charAt(sz - 1));
    }
    infixTokens.add(token.toString());
  }

  void infixToPostfix() {

    Stack<String> stack = new Stack<>();

    stack.push("(");
    infixTokens.add(")");

    while (!infixTokens.isEmpty()) {
      String token = infixTokens.removeFirst();
      if (token.equals("(")) {
        stack.push(token);
      } else if (token.equals(")")) {

        // Pop out all the operators and append them to postfix expression till an opening bracket
        // is found
        while (!stack.peek().equals("(")) {
          postfixTokens.add(stack.pop());
        }
        stack.pop();
      } else if (List.of("*", "/", "+", "-", "^").contains(token)) {

        // Pop out operators with higher precedence at the top of the stack and append them to
        // the postfix expression, before pushing the current operator to the stack.
        while (!stack.empty() && precedence.get(stack.peek()) >= precedence.get(token)) {
          postfixTokens.add(stack.pop());
        }
        stack.push(token);
      } else {

        // Positions of the operands do not change in the postfix expression so append
        // an operand as it is.
        postfixTokens.add(token);
      }
    }
    System.out.print("Postfix Main :");
    for (String tok : postfixTokens) System.out.print(tok + ", ");
    System.out.println("\n");
    postfixTokens.clear();
  }

  void main() {
    IO.println(" Algorithm : Infix To Postfix Conversion ");
    String strexp1 = "110+50";
    String strexp2 = "110+50+(4-2*5)-10+40";
    String strexp3 = "(110+50)*(2-4)";
    String strexp4 = "2^5*(3-4)";
    String strexp5 = "2^5";
    String strexp6 = "0-8-0-5^3";

    Expression expression = new Expression();
    expression.evaluate(strexp1);
    expression.evaluate(strexp2);
    expression.evaluate(strexp3);
    expression.evaluate(strexp4);
    expression.evaluate(strexp5);
    expression.evaluate(strexp6);
  }
}
