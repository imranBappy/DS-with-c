#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;
struct node
{
    int data;
    Node *parent;
    Node *left;
    Node *right;
};
Node *create_node(int data);
void add_left_child(Node *node, Node *child);
void add_right_child(Node *node, Node *child);
Node *insert_node(Node *root, Node *node);
void insert_tree_node(Node *root, Node *node);

Node *min_node(Node *root);
Node *create_node(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void add_left_child(Node *node, Node *child)
{
    node->left = child;
    if (child != NULL)
        child->parent = node;
}
void add_right_child(Node *node, Node *child)
{
    node->right = child;
    if (child != NULL)
        child->parent = node;
}
Node *insert_node(Node *root, Node *node)
{
    if (root->data > node->data)
        add_left_child(root, node);
    else
        add_right_child(root, node);
    return root;
}
void insert_tree_node(Node *root, Node *node)
{
    if (root == NULL)
        return;
    if (root->data > node->data)
    {
        if (root->left == NULL)
        {
            add_left_child(root, node);
            return;
        }
        insert_tree_node(root->left, node);
    }
    else
    {
        if (root->right == NULL)
        {
            add_right_child(root, node);
            return;
        }
        insert_tree_node(root->right, node);
    }
}
void bst_insert(Node *root, Node *node)
{
    if (root == NULL)
        return;
    Node *parent = NULL;
    Node *current = root;
    while (current != NULL)
    {
        parent = current;
        if (parent->data > node->data)
            current = current->left;
        else
            current = current->right;
    }
    if (parent->data > node->data)
        add_left_child(parent, node);
    else
        add_right_child(parent, node);
}
void inOrder_print(Node *node)
{
    if (!node)
        return;
    inOrder_print(node->left);
    printf("%d -> ", node->data);
    inOrder_print(node->right);
}
void print_space(int count)
{
    for (int i = 0; i < count * 4; i++)
        printf(" ");
}
void print_tree(Node *node, int count)
{
    print_space(count);
    printf("Root : %d\n", node->data);
    if (!node->right || !node->left)
    {
        print_space(count);
        printf("Left : %d\n", node->left->data);
        return;
    }

    if (node->left->left)
    {
        print_space(count);
        printf("Left :\n");
        print_tree(node->left, count + 1);
    }
    else
    {
        print_space(count);
        printf("Left : %d\n", node->left->data);
        print_space(count);
        printf("Right : %d\n", node->right->data);
        return;
    }
    if (node->right->right)
    {
        print_space(count);
        printf("Right :\n");
        print_tree(node->right, count + 1);
    }
    else
    {
        print_space(count);
        printf("Right : %d\n", node->right->data);
        return;
    }
}
void bst_input(Node *root, int arr[])
{
    for (int i = 1; i <= arr[0]; i++)
        bst_insert(root, create_node(arr[i]));
}

Node *bst_search(Node *root, int data)
{
    Node *node = root;
    while (node != NULL)
    {
        if (data == node->data)
            return node;
        if (node->data > data)
            node = node->left;
        else
            node = node->right;
    }
    if (node == NULL)
        return node;
}
Node *min_node(Node *root)
{
    while (root->left)
        root = root->left;
    return root;
}
int max_node(Node *root)
{
    while (root->right)
        root = root->right;
    return root->data;
}
Node *bst_transplant(Node *root, Node *current_node, Node *new_node)
{
    if (current_node == root)
        root = new_node;
    else if (current_node == current_node->parent->left)
        add_left_child(current_node->parent, new_node);
    else
        add_right_child(current_node, new_node);

    return root;
}

Node *bst_delete(Node *root, Node *node)
{
    Node *smallest_node;
    if (node->left == NULL)
    {
        bst_transplant(root, node, node->right);
    }
    else if (node->right == NULL)
    {
        bst_transplant(root, node, node->left);
    }
    else
    {
        smallest_node = min_node(node->right);
        if (smallest_node->parent != node)
        {
            root = bst_transplant(root, smallest_node, smallest_node->right);
            add_right_child(smallest_node, node->right);
        }
        root = bst_transplant(root, node, smallest_node);
        add_left_child(smallest_node, node->left);
    }
    free(node);
    return root;
}
int main()
{
    Node *root = create_node(10);
    // int arr[] = {8, 5, 17, 3, 7, 12, 19, 1, 4};
    int arr[] = {9, 5, 17, 3, 7, 12, 19, 1, 4, 13};
    bst_input(root, arr);
    inOrder_print(root);
    printf("\n");
    print_tree(root, 0);

    printf("\n");

    Node *find = bst_search(root, 12);
    root = bst_delete(root, find);
    inOrder_print(root);
    print_tree(root, 0);

    return 0;
}
