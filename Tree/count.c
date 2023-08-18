#include "header.h"

static int ans = 0;
int count(bst *root)
{
    if(root != NULL)
    {
        count(root->left);
        ans++;
        count(root->right);
    }
    return ans;
}
