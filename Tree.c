#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node* createNode(int data){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
struct node* insertNode(struct node* root, int data){
    if(root==NULL){
        return createNode(data);
    }
    if(data< root->data){
        root->left=insertNode(root->left,data);
    }else{
        root->right=insertNode(root->right,data);
    }
    return root;
}

void inorderTraversal(struct node* root){
    if(root!=NULL){
        inorderTraversal(root->left);
        printf("%d ",root->data);
        inorderTraversal(root->right);
    }
}

// Function to print the tree in a structured format
void printTree(struct node* root, int space) {
    if (root == NULL) {
        return;
    }

    // Increase distance between levels
    int COUNT = 5; // Adjust this value for spacing
    space += COUNT;

    // Print the right subtree first
    printTree(root->right, space);

    // Print the current node after spacing
    printf("\n");
    for (int i = COUNT; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    // Print the left subtree
    printTree(root->left, space);
}
int main(){
    struct node* root=NULL;
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the values to insert into the tree:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    printf("Tree structure:\n");
    printTree(root, 0);

    printf("Inorder Traversal of the tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
