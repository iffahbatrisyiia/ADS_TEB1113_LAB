#include <iostream>
using namespace std;

struct Node {
    string name;
    Node* left;
    Node* right;

    Node(string newName){
        name = newName;
        left = NULL;
        right = NULL;
    }
};

//Insert into BST
Node* insert(Node* root, string newName){
    if(root == NULL){
        return new Node(newName);
    }

    if(newName < root->name){
        root->left = insert(root->left, newName);
    }
    else if (newName >root->name){
        root->right = insert(root->right, newName);
    }
    return root;
}

//find minimum node (to be used for deletion)
Node* findMin(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

//delete from BST
Node* deleteNode(Node* root, string targetName){
    if(root == NULL){
        return NULL;
    }

    if(targetName < root->name){
        root->left = deleteNode(root->left, targetName);
    }
    else if(targetName > root->name){
        root->right = deleteNode(root->right, targetName);
    }
    else{
        //Node found
        // targetName == root->name

        //No child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //One child
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //two children
        Node* temp = findMin(root->right);
        root->name = temp->name;
        root->right = deleteNode(root->right, temp->name);
    }
    return root;
}

//search in BST
Node* search(Node* root, string targetName){
    if(root == NULL || root->name == targetName){
        return root;
    }

    if(targetName < root->name){
        return search(root->left, targetName);
    }
    return search(root->right, targetName);
}

//display (InOrder traversal)
//Left subtree -> Root -> Right subtree
void display(Node* root){
    if(root != NULL){
        display(root->left);
        cout << root->name << endl;
        display(root->right);
    }
}

int main(){
    Node* root = NULL;

    //insert original data 
    root =  insert(root, "Ali");
    root =  insert(root, "Batrisyia");
    root =  insert(root, "Claire");
    root =  insert(root, "Dmitri");

    cout << "Original BST (InOrder):\n";
    display(root);

    // Insert Zara
    root = insert(root, "Zara");
    cout << "\nAfter inserting Zara:\n";
    display(root);

    // Insert Kelly
    root = insert(root, "Kelly");
    cout << "\nAfter inserting Kelly:\n";
    display(root);

    // Insert Eleanor
    root = insert(root, "Eleanor");
    cout << "\nAfter inserting Eleanor:\n";
    display(root);

    // Delete Claire
    root = deleteNode(root, "Claire");
    cout << "\nAfter deleting Claire:\n";
    display(root);

    // Search
    cout << "\nSearching for Dmitri...\n";
    if (search(root, "Dmitri"))
        cout << "Dmitri found.\n";
    else
        cout << "Dmitri not found.\n";

    return 0;
}