#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    struct node *left;
    int data;
    struct node *right;
};

typedef struct node NODE;
NODE *root = NULL;

// Function declarations
void create(int);
void insert(NODE*, NODE*);
void inorder(NODE*);
void preorder(NODE*);
void postorder(NODE*);
// Function to create and insert a new node
void create(int value) {
     NODE *newnode = (NODE*)malloc(sizeof(NODE));
    if (newnode == NULL) {
        printf("Memory not allocated\n");
        return;
    }
    newnode->data = value;
    newnode->left = newnode->right = NULL;

    if (root == NULL)
        root = newnode; // First node becomes root
    else
        insert(root, newnode); // Insert elsewhere
}

// Recursive insertion
void insert(NODE *root, NODE *newnode) {
    if (newnode->data < root->data) {
        if (root->left == NULL)
            root->left = newnode;
        else
            insert(root->left, newnode);
    } else {
        if (root->right == NULL)
            root->right = newnode;
        else
            insert(root->right, newnode);
    }
}
// In-order traversal of the BST
void inorder(NODE *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

// pre-order traversal of the BST
void preorder(NODE *root) {
    if (root != NULL) {
    	printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// post-order traversal of the BST
void postorder(NODE *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}
// Main menu
int main() {
    int ch, value;
    do {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n2.In-Order traversal\n3.pre-order traversal\n4.post-order traversal\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &value);
                create(value);
                break;
            case 2:
                if (root == NULL)
                    printf("Tree is empty\n");
                else {
                    printf("In-Order Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 3:
               if (root == NULL)
                    printf("Tree is empty\n");
                else {
                    printf("pre-Order Traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;
            case 4:
               if (root == NULL)
                    printf("Tree is empty\n");
                else {
                    printf("post-Order Traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (1);
}
