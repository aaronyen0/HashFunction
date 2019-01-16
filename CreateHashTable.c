#define TABLESIZE 1024

struct LinkedList {
	int val;
	struct LinkedList* next;
};

struct LinkedList* InsertVal(struct LinkedList* root, int val) {
	struct LinkedList* preNode = NULL;
	struct LinkedList* node = root;
    //先檢查val也沒有在list中
	while (node) {
		if (node->val == val) {
			return root;
		}
		preNode = node;
		node = node->next;
	}
    //若出迴圈，則
	struct LinkedList* node = (struct LinkedList*)malloc(sizeof(struct LinkedList));
	node->val = val;
	node->next = NULL;

	if (preNode) {
		preNode->next = node;
		return root;
	}
	return node;
}

int main() {
    struct LinkedList* hashTable[TABLESIZE] = { NULL };
    
}
