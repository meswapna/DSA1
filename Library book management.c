#include <stdio.h>
#include <stdlib.h>

// Structure
struct node {
    int data;
    struct node *left, *right;
};

// Create node
struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert
struct node* insert(struct node* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

// Find minimum
struct node* findMin(struct node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}


// Traversals
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Main
int main() {
    struct node* root = NULL;
    int choice, val;

    while (1) {
        printf("\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;

            case 2:
                printf("Inorder: ");
                inorder(root);
                break;

            case 3:
                printf("Preorder: ");
                preorder(root);
                break;

            case 4:
               printf("postorder:");
               postorder(root);
               break;
           case 5:
                exit(0);

            default:
                printf("Invalid choice");

        }
    }
}
