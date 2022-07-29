#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;
struct node
{
    int data;
    Node *left;
    Node *right;
};
Node *root = NULL;
Node *create_node(int item)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Error! Could Not Create A New Node\n");
    }

    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void add_left_child(Node *node, Node *child)
{
    node->left = child;
}
void add_right_child(Node *node, Node *child)
{
    node->right = child;
}
// 2 7 1 | 6 9 8
void print_tree(Node *node)
{
    printf("%d, ", node->data);
    if (node->left)
        print_tree(node->left);
    if (node->right)
        print_tree(node->right);
}

Node *create_tree()
{
    Node *two = create_node(2);
    Node *seven = create_node(7);
    Node *nine = create_node(9);
    add_left_child(two, seven);
    add_right_child(two, nine);

    Node *one = create_node(1);
    Node *six = create_node(6);
    add_left_child(seven, one);
    add_right_child(seven, six);

    Node *five = create_node(5);
    Node *ten = create_node(10);
    add_left_child(six, five);
    add_right_child(six, ten);

    Node *eight = create_node(8);
    add_right_child(nine, eight);

    Node *three = create_node(3);
    Node *four = create_node(4);
    add_left_child(eight, three);
    add_right_child(eight, four);
    return two;
}

int main()
{
    // root = create_node(2);
    // add_left_child(root, create_node(7));
    // add_right_child(root, create_node(9));

    // add_left_child(root->left, create_node(1));
    // add_right_child(root->left, create_node(6));

    // add_right_child(root->right, create_node(8));

    Node *x = create_tree();

    print_tree(x);

    return 0;
}