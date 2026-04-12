import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Stack {

  static Map<String, Integer> precedence = new HashMap<>();
  static List<String> infixTokens = new ArrayList<>();
  static List<String> postfixTokens = new ArrayList<>();

  static {
    precedence.put("^", 4);
    precedence.put("/", 3);
    precedence.put("*", 3);
    precedence.put("+", 2);
    precedence.put("-", 2);
    precedence.put("(", 1);
  }

  static void main() {
    System.out.println("--- Infix To Postfix Conversion ---");

    evaluate("110+50");
    evaluate("110+50+(4-2*5)-10+40");
    evaluate("(110+50)*(2-4)");
    evaluate("2^5*(3-4)");
  }

  static void evaluate(String expression) {
    infixTokens.clear();
    postfixTokens.clear();

    System.out.println("Input: " + expression);

    tokenize(expression);
    infixToPostfix();
  }

  static void tokenize(String expression) {
    StringBuilder token = new StringBuilder();
    int sz = expression.length();
    if (sz == 0) return;

    int i;
    for (i = 0; i < sz - 1; i++) {
      String pointer = String.valueOf(expression.charAt(i));
      if (List.of("+", "-", "/", "*", "^", "(", ")").contains(pointer)) {
        infixTokens.add(pointer);
      } else {
        token.append(pointer);
        char next = expression.charAt(i + 1);
        if (!(next >= '0' && next <= '9')) {
          infixTokens.add(token.toString());
          token.setLength(0);
        }
      }
    }

    char last = expression.charAt(sz - 1);
    if (last >= '0' && last <= '9') {
      token.append(last);
      infixTokens.add(token.toString());
    } else {
      if (!token.isEmpty()) infixTokens.add(token.toString());
      infixTokens.add(String.valueOf(last));
    }
  }

  static void infixToPostfix() {
    java.util.Stack<String> s = new java.util.Stack<>();

    s.push("(");
    infixTokens.add(")");

    while (!infixTokens.isEmpty()) {
      String token = infixTokens.removeFirst();
      if (token.equals("(")) {
        s.push(token);
      } else if (token.equals(")")) {
        while (!s.isEmpty() && !s.peek().equals("(")) {
          postfixTokens.add(s.pop());
        }
        if (!s.isEmpty()) s.pop();
      } else if (List.of("*", "/", "+", "-", "^").contains(token)) {
        while (!s.empty() && precedence.get(s.peek()) >= precedence.get(token)) {
          postfixTokens.add(s.pop());
        }
        s.push(token);
      } else {
        postfixTokens.add(token);
      }
    }

    System.out.print("Postfix: ");
    for (String t : postfixTokens) {
      System.out.print(t + " ");
    }
    System.out.println("\n---");
  }
}
