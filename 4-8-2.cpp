#include <stdio.h>

struct node {
	struct node *left, *right;
	int val;
};

int __first_common_ancestor(struct node *root, struct node *n1, struct node *n2, struct node *answer)
{
	int ret = 0;

	if (root->left) {
		ret += __first_common_ancestor(root->left, n1, n2, answer);

		if (ret == -1)
			goto out;

		if (ret == 2)
			goto found;
	}

	if (root->right) {
		ret += __first_common_ancestor(root->right, n1, n2, answer);

		if (ret == -1)
			goto out;

		if (ret == 2)
			goto found;
	}

	if (root == n1)
		ret++;

	if (root == n2)
		ret++;

	return ret;

found:
	answer = root;
out:
	return -1;
}

struct node *first_common_ancestor(struct node *root, struct node *n1, struct node *n2)
{
	struct node *answer = NULL;

	__first_common_ancestor(root, n1, n2, answer);

	return answer;
}



int main(void) {



    return 0;
}