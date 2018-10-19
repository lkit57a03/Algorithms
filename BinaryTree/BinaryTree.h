#include "../Utility/Utility.h"
#include<stdbool.h>


struct Node{
    int Value;
    struct Node * left_child;
    struct Node * right_child;
    struct Node * parent;
};

enum print_order{print_tree_preorder = 0,print_tree_inorder= 1,print_tree_postorder = 2};
enum print_type{recursive = 0,iterative = 1};

struct Node * Root;
int left_height;
int right_height;
void insert(int Value);


struct Node * initialize(int Value);

//void print_tree(enum  print_order);

bool delete_value(int value);

struct Node * min_value_node(struct Node * pNode);

struct Node * search(int value);

int height(struct Node * pNode);

struct Node * fill_tree(struct Node * pNode,int num_of_elem);

void insert(int Value);

void print_tree(enum  print_order whichOrder,enum print_type type);

int number_of_children(struct Node * pNode);

