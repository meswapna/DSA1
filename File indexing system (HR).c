#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Print without trailing space
void inorder(struct Node* root, int *first) {
    if (root != NULL) {
        inorder(root->left, first);

        if (*first) {
            printf("%d", root->data);
            *first = 0;
        } else {
            printf(" %d", root->data);
        }

        inorder(root->right, first);
    }
}

int main() {
    int n, i, val, insertVal, deleteVal;
    struct Node* root = NULL;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    scanf("%d", &insertVal);
    root = insert(root, insertVal);

    scanf("%d", &deleteVal);
    root = deleteNode(root, deleteVal);

    printf("Current File Index sorted in ascending order: ");

    int first = 1;
    inorder(root, &first);

    printf("\n");  // important!

    return 0;
}
