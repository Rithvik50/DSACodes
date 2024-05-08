#include <stdio.h>
#include <stdlib.h>

struct node {
  char data;
  struct node *left;
  struct node *right;
};

struct node *new_node(char data) {
  struct node *node = malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

struct node *build_tree(char *postfix_expression) {
  struct node *stack[100];
  int top = -1;

  for (int i = 0; postfix_expression[i] != '\0'; i++) {
    char data = postfix_expression[i];

    if (data == '+' || data == '-' || data == '*' || data == '/') {
      struct node *right = stack[top--];
      struct node *left = stack[top--];

      struct node *root = new_node(data);
      root->left = left;
      root->right = right;

      stack[++top] = root;
    } else {
      struct node *node = new_node(data);
      stack[++top] = node;
    }
  }

  return stack[top];
}

int evaluate_tree(struct node *root) {
  if (root == NULL) {
    return 0;
  }

  if (root->data == '+') {
    return evaluate_tree(root->left) + evaluate_tree(root->right);
  } else if (root->data == '-') {
    return evaluate_tree(root->left) - evaluate_tree(root->right);
  } else if (root->data == '*') {
    return evaluate_tree(root->left) * evaluate_tree(root->right);
  } else if (root->data == '/') {
    return evaluate_tree(root->left) / evaluate_tree(root->right);
  } else {
    return root->data - '0';
  }
}

int main() {
  char postfix_expression[] = "52-3*";

  struct node *root = build_tree(postfix_expression);

  int result = evaluate_tree(root);

  printf("Result: %d\n", result);

  return 0;
}