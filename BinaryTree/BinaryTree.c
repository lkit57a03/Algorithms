#include "../Utility/Utility.h"
#include<stdbool.h>

struct Node{
    int Value;
    struct Node * left_child;
    struct Node * right_child;
    struct Node * parent;
};
struct Node * Root;
int left_height;
int right_height;
void insert(int Value);

struct Node * initialize(int Value){
    Root = NULL;
    if (Value != 0){
        insert(Value);
    }
    return Root;
}

void _print_tree(struct Node *pNode);

int _height(struct Node *pNode, int current_height);


struct Node * _search(struct Node *pNode, int value);

bool _delete_node(struct Node *pNode);

void _insert(int value, struct Node *pNode) {
    if (value < pNode->Value){
        if (pNode->left_child == NULL){
            pNode->left_child = (struct Node *)malloc(sizeof(struct Node));
            pNode->left_child->Value = value;
            pNode->left_child->parent = pNode;
        } else{
            _insert(value,pNode->left_child);
        }
    } else if(value > pNode->Value){
        if (pNode->right_child == NULL){
            pNode->right_child = (struct Node *)malloc(sizeof(struct Node));
            pNode->right_child->Value = value;
            pNode->right_child->parent = pNode;
        } else{
            _insert(value,pNode->right_child);
        }
    } else {
        printf("\nValue alredy in tree : %d\n",value);
    }
}

void print_tree(){
    if (Root != NULL){
        _print_tree(Root);
    }else{
        printf("Root is empty");
    }
}

void _print_tree(struct Node *pNode) {
    if(pNode != NULL){
        _print_tree(pNode->left_child);
        printf("- %d -",pNode->Value);
        _print_tree(pNode->right_child);
    }
}

void insert(int Value){
    if(Root == NULL){
        Root = (struct Node *)malloc(sizeof(struct Node));
        Root->Value = Value;
    } else _insert(Value,Root);
}

struct Node * fill_tree(struct Node * pNode,int num_of_elem){
    int * temp_list = generateRandomArray(0,num_of_elem);
    for (int i = 0; i < num_of_elem; ++i) {
        insert(temp_list[i]);
    }
    free(temp_list);
    return Root;
}
int height(struct Node * pNode){
    if (Root != NULL){
        return _height(pNode,0);
    }else return 0;
}

int _height(struct Node *pNode, int current_height) {
    if (pNode == NULL) return current_height;
    left_height = _height(pNode->left_child,current_height + 1);
    right_height=_height(pNode->right_child,current_height + 1);

    return left_height > right_height ? left_height : right_height;
}

struct Node * search(int value){
    if (Root != NULL){
        return _search(Root,value);
    } else return NULL;
}

struct Node * _search(struct Node *pNode, int value) {
    if(value == pNode->Value) return pNode;
    else if (value < pNode->Value && pNode->left_child != NULL){
        _search(pNode->left_child,value);
    }else if (value > pNode->Value && pNode->right_child != NULL){
        _search(pNode->right_child,value);
    } else return NULL;
}

struct Node * min_value_node(struct Node * pNode){
    struct Node * current = pNode;

    while (current->left_child != NULL){
        current = current->left_child;
    }
    return current;
}
int number_of_children(struct Node * pNode){
    int num_of_children = 0;
    if (pNode->left_child != NULL) num_of_children++;
    if (pNode->right_child != NULL) num_of_children++;
    return num_of_children;
}
bool _delete_node(struct Node *pNode) {
    struct Node * node_parent = pNode->parent;
    struct Node * child = NULL;
    int numberofchildren = number_of_children(pNode);

    if(numberofchildren == 0){
        if(node_parent->left_child == pNode) node_parent->left_child = NULL;
        else node_parent->right_child = NULL;
    }
    if(numberofchildren == 1) {
        if(pNode->left_child != NULL){
            child = pNode->left_child;
        } else {
            child = pNode->right_child;
        }
        if(node_parent->left_child == pNode){
            node_parent->left_child = child;
        } else {
            node_parent->right_child = child;
        }
        child->parent = node_parent;
    }

    if (numberofchildren == 2){
        struct Node * successor = min_value_node(pNode->right_child);

        pNode->Value = successor->Value;

        _delete_node(successor);
    }
    return 0;
}

delete_value(int value){
    return _delete_node(search(value));
}

int main(int argv,char ** argc){
    int d = 1;
    struct Node * temp_Root = initialize(0);
    temp_Root = fill_tree(temp_Root,1000);
    print_tree();
    printf("\n Height is : %d\n",height(temp_Root));

    while (d != 0){
        scanf("%d",&d);
        delete_value(d);

        print_tree();
    }
    return 0;
}