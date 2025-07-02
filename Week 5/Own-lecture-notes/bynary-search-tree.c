// Concepts
// Defining a structure that allows binary search
typedef struct node
{
    int number;
    struct node *right;
    struct node *left;
} node;

// Using recursion to search a binary search tree
bool search(node *tree, int number)
{
    if (tree == NULL)
    {
        return false;
    }
    else if (number < tree->number)
    {
        return search(tree->left, number);
    }
    else if (number > tree->number)
    {
        return search(tree->right, number)
    }
    else if (number == tree->number)
    {
        return true;
    }
}
