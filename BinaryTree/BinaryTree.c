#include "NodeStack/NodeStack.h"

BTNode * initialize(int Value){
    Root = NULL;
    if (Value != 0){
        insert(Value);
    }
    return Root;
}

void _insert(int value, BTNode *pNode) {
    if (value < pNode->Value){
        if (pNode->left_child == NULL){
            pNode->left_child = (BTNode *)malloc(sizeof(BTNode));
            pNode->left_child->Value = value;
            pNode->left_child->parent = pNode;
        } else{
            _insert(value,pNode->left_child);
        }
    } else if(value > pNode->Value){
        if (pNode->right_child == NULL){
            pNode->right_child = (BTNode *)malloc(sizeof(BTNode));
            pNode->right_child->Value = value;
            pNode->right_child->parent = pNode;
        } else{
            _insert(value,pNode->right_child);
        }
    } else {
        printf("\nValue alredy in tree : %d\n",value);
    }
}

void insert(int Value){
    if(Root == NULL){
        Root = (BTNode *)malloc(sizeof(BTNode));
        Root->Value = Value;
    } else _insert(Value,Root);
}

void _print_tree_inorder(BTNode *pNode,enum print_type type) {
    if(pNode != NULL){
        if(type == recursive){    
            _print_tree_inorder(pNode->left_child,recursive);
            printf("- %d -",pNode->Value);
            _print_tree_inorder(pNode->right_child,recursive);
            
        }else if (type == iterative){
            struct Nodestack * nodeStack = init(1500);
            BTNode * current             = Root;
            while(true){
                while(current != NULL){
                    push(nodeStack,current);
                    current = current->left_child;
                }
                if(isEmpty(nodeStack)){
                    return;
                }
                current = pop(nodeStack);
                printf("%d ->",current->Value);
                current = current->right_child;
            }
        }
        
    }
}
void _print_tree_preorder(BTNode *pNode,enum print_type type) {
    if(pNode != NULL){
        if(type == recursive){
            printf("- %d -",pNode->Value);
            _print_tree_preorder(pNode->left_child,recursive);
            _print_tree_preorder(pNode->right_child,recursive);
        }else if (type == iterative){
            struct Nodestack * nodeStack = init(1500);
            BTNode * current             = Root;
            while(true){
                while(current != NULL){
                    push(nodeStack,current);
                    printf("%d ->",current->Value);
                    current = current->left_child;
                }
                if(isEmpty(nodeStack)){
                    return;
                }
                current = pop(nodeStack);
                current = current->right_child;
            }
        }
    }
}
void _print_tree_postorder(BTNode *pNode,enum print_type type) {
    if(pNode != NULL){
        if(type == recursive){
            _print_tree_postorder(pNode->left_child,recursive);
            _print_tree_postorder(pNode->right_child,recursive);
            printf("- %d -",pNode->Value);
        }else if (type == iterative){
            struct Nodestack * nodeStack = init(1500);
            BTNode * current             = Root;
            while(true){
                while(current != NULL){
                    push(nodeStack,current);
                    current = current->left_child;
                }
                if(isEmpty(nodeStack)){
                    return;
                }
                current = pop(nodeStack);
                current = current->right_child;
                printf("%d ->",current->Value);
            }
        }
    }
}

void print_tree(enum  print_order whichOrder,enum print_type type){
    if (Root != NULL){
        if (type == recursive){
            if(whichOrder == print_tree_preorder){
                _print_tree_preorder(Root,recursive);
            }else if(whichOrder == print_tree_inorder){
                _print_tree_inorder(Root,recursive);
            }else{
                _print_tree_postorder(Root,recursive);
            }
        }else if(type == iterative){
            if(whichOrder == print_tree_preorder){
                _print_tree_preorder(Root,iterative);
            }else if(whichOrder == print_tree_inorder){
                _print_tree_inorder(Root,iterative);
            }else{
                _print_tree_postorder(Root,iterative);
            }
        }
    }else{
        printf("Root is empty");
    }
}
int _height(BTNode *pNode, int current_height) {
    if (pNode == NULL) return current_height;
    left_height = _height(pNode->left_child,current_height + 1);
    right_height=_height(pNode->right_child,current_height + 1);

    return left_height > right_height ? left_height : right_height;
}

BTNode * fill_tree(BTNode * pNode,int num_of_elem){
    int * temp_list = generateRandomArray(0,num_of_elem);
    for (int i = 0; i < num_of_elem; ++i) {
        insert(temp_list[i]);
    }
    free(temp_list);
    return Root;
}
int height(BTNode * pNode){
    if (Root != NULL){
        return _height(pNode,0);
    }else return 0;
}




BTNode * _search(BTNode *pNode, int value) {
    if(value == pNode->Value) return pNode;
    else if (value < pNode->Value && pNode->left_child != NULL){
        _search(pNode->left_child,value);
    }else if (value > pNode->Value && pNode->right_child != NULL){
        _search(pNode->right_child,value);
    } else return NULL;
}

BTNode * search(int value){
    if (Root != NULL){
        return _search(Root,value);
    } else return NULL;
}

BTNode * min_value_node(BTNode * pNode){
    BTNode * current = pNode;

    while (current->left_child != NULL){
        current = current->left_child;
    }
    return current;
}

int number_of_children(BTNode * pNode){
    int num_of_children = 0;
    if (pNode->left_child != NULL) num_of_children++;
    if (pNode->right_child != NULL) num_of_children++;
    return num_of_children;
}
bool _delete_node(BTNode *pNode) {
    BTNode * node_parent = pNode->parent;
    BTNode * child = NULL;
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
        BTNode * successor = min_value_node(pNode->right_child);

        pNode->Value = successor->Value;

        _delete_node(successor);
    }
    return 0;
}

bool delete_value(int value){
    return _delete_node(search(value));
}

