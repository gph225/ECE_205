#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

class Node {
public:
    string value;
    Node* left;
    Node* right;

    Node(string val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

bool isOperator(const string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool isNumber(const string& token) {
    if (token.empty()) return false;

    for (char c : token) {
        if (!isdigit(c)) return false;
    }

    return true;
}

int precedence(const string& op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    return 0;
}

vector<string> tokenize(const string& expression) {
    vector<string> tokens;
    string number = "";

    for (char c : expression) {
        if (isdigit(c)) {
            number += c;
        }
        else {
            if (!number.empty()) {
                tokens.push_back(number);
                number = "";
            }

            if (c == ' ') {
                continue;
            }

            string symbol(1, c);
            tokens.push_back(symbol);
        }
    }

    if (!number.empty()) {
        tokens.push_back(number);
    }

    return tokens;
}

vector<string> infixToPostfix(const vector<string>& tokens) {
    vector<string> postfix;
    stack<string> operators;

    for (string token : tokens) {
        if (isNumber(token)) {
            postfix.push_back(token);
        }
        else if (token == "(") {
            operators.push(token);
        }
        else if (token == ")") {
            while (!operators.empty() && operators.top() != "(") {
                postfix.push_back(operators.top());
                operators.pop();
            }

            if (!operators.empty()) {
                operators.pop();
            }
        }
        else if (isOperator(token)) {
            while (!operators.empty() &&
                   isOperator(operators.top()) &&
                   precedence(operators.top()) >= precedence(token)) {
                postfix.push_back(operators.top());
                operators.pop();
            }

            operators.push(token);
        }
    }

    while (!operators.empty()) {
        postfix.push_back(operators.top());
        operators.pop();
    }

    return postfix;
}

Node* buildExpressionTree(const vector<string>& postfix) {
    stack<Node*> treeStack;

    for (string token : postfix) {
        if (isNumber(token)) {
            treeStack.push(new Node(token));
        }
        else if (isOperator(token)) {
            Node* right = treeStack.top();
            treeStack.pop();

            Node* left = treeStack.top();
            treeStack.pop();

            Node* newNode = new Node(token);
            newNode->left = left;
            newNode->right = right;

            treeStack.push(newNode);
        }
    }

    return treeStack.top();
}

void postorderTraversal(Node* root, vector<string>& result) {
    if (root == nullptr) return;

    postorderTraversal(root->left, result);
    postorderTraversal(root->right, result);
    result.push_back(root->value);
}

int evaluatePostfix(const vector<string>& postfix) {
    stack<int> values;

    for (string token : postfix) {
        if (isNumber(token)) {
            values.push(stoi(token));
        }
        else if (isOperator(token)) {
            int right = values.top();
            values.pop();

            int left = values.top();
            values.pop();

            int answer;

            if (token == "+") {
                answer = left + right;
            }
            else if (token == "-") {
                answer = left - right;
            }
            else if (token == "*") {
                answer = left * right;
            }
            else {
                answer = left / right;
            }

            values.push(answer);
        }
    }

    return values.top();
}

void printExpression(const vector<string>& expression) {
    for (string token : expression) {
        cout << token << " ";
    }
    cout << endl;
}

void deleteTree(Node* root) {
    if (root == nullptr) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    string input;

    cout << "Enter an infix arithmetic expression: ";
    getline(cin, input);

    vector<string> tokens = tokenize(input);

    vector<string> postfix = infixToPostfix(tokens);

    Node* root = buildExpressionTree(postfix);

    vector<string> postorderResult;
    postorderTraversal(root, postorderResult);

    int answer = evaluatePostfix(postfix);

    cout << endl;
    cout << "Infix Expression: " << input << endl;

    cout << "Postfix Expression: ";
    printExpression(postfix);

    cout << "Postorder Traversal of Tree: ";
    printExpression(postorderResult);

    cout << "Evaluation Result: " << answer << endl;

    deleteTree(root);

    return 0;
}