#include "../Utility/Utility.h"


typedef struct BTNode{
    int Value;
    struct BTNode * left_child;
    struct BTNode * right_child;
    struct BTNode * parent;
}BTNode;

enum print_order{print_tree_preorder = 0,print_tree_inorder= 1,print_tree_postorder = 2};
enum print_type{recursive = 0,iterative = 1};

BTNode * Root;
int left_height;
int right_height;
void insert(int Value);


BTNode * initialize(int Value);

//void print_tree(enum  print_order);

bool delete_value(int value);

BTNode * min_value_node(BTNode * pNode);

BTNode * search(int value);

int height(BTNode * pNode);

BTNode * fill_tree(BTNode * pNode,int num_of_elem);

void insert(int Value);

void print_tree(enum  print_order whichOrder,enum print_type type);

int number_of_children(BTNode * pNode);

