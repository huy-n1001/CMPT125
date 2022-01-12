int minValue(struct node* node) {
	struct node* current = node;
	while (current -> left != NULL) {
		current = current -> left;
	}
	return(current -> data);
}

int maxValue(struct node* node) {
	struct node* current = node;
	while (current -> right != NULL) {
		current = current -> right;
	}
	return(current -> data);
}

int DetBST1(struct node* node) {
	if (node == NULL)
		return 1;
		
	if (node -> left != NULL && node -> left -> data > node -> data)
		return 0;
	
	if (node -> right != NULL && node -> right -> data < node -> data)
		return 0;
	
	if (!DetBST1(node-> left) || !DetBST1(node -> right))
		return 0;
	
	return 1;

}

int DetBST2(struct node* node) {
	return(BSTUtil(node, INT_MIN, INT_MAX));
}

int BSTUtil(struct node* node, int min, int max) {
	if (node == NULL)
		return 1;
	
	if (node -> data < min || node -> data > max)
		return 0;
	
	return BSTUtil(node -> left, min, node -> data-1) && BSTUtil(node -> right, node -> data+1, max);
}

