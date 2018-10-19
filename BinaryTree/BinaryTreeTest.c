#include "BinaryTree.h"

int main(int argv,char ** argc){
    int d = 1;
    BTNode * temp_Root = initialize(0);
    temp_Root = fill_tree(temp_Root,1000);
    print_tree(print_tree_inorder,iterative);
    printf("\n Height is : %d\n",height(temp_Root));

    while (d != 0){
        scanf("%d",&d);
        delete_value(d);

        print_tree(print_tree_inorder,iterative);
    }
    return 0;
}