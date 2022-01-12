#include "LL.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*
typedef struct {
    node_t * head;
    node_t * tail;
} LL_t;
*/

// Creates and returns a new, empty list
LL_t * LLcreate() {
    LL_t * ret = malloc(sizeof(LL_t));
    if (ret != NULL) {
        ret->head = NULL;
        ret->tail = NULL;
    }
    return ret;
}

// Adds a new element to the tail end of a list
void LLappendNode(LL_t * intlist, node_t * newNode) {
    if (newNode != NULL) {
        newNode->next = NULL;
        if (intlist->tail == NULL) {
            // empty list
            assert(intlist->head == NULL);
            intlist->head = newNode;
            intlist->tail = newNode;
        } else {
            // non empty list
            intlist->tail->next = newNode; // seg fault
            intlist->tail = newNode;
        }
    }
}

// Adds a new element to the tail end of a list
void LLappend(LL_t * intlist, int value) {
    node_t * newNode = malloc(sizeof(node_t));
    if (newNode != NULL) {
        newNode->data = value;
        LLappendNode(intlist, newNode);
    }
}




// Outputs the list elements in order from head to tail
void LLprint(LL_t * intlist) {
    // for ( init ; entry ; increment ) {
    for ( node_t * current = intlist->head; current != NULL ; current = current->next ) {
        printf(" %d", current->data);
    }
    putchar('\n');

    /*
    node_t * current = intlist->head;
    while (current != NULL) {
        printf(" %d", current->data);
        current = current->next;
    }
    putchar('\n');
    */
}


// Return 1 iff target in intlist; 0 otherwise
int LLsearch(LL_t * intlist, int target) {
    // for ( init ; entry ; increment ) {
    /*
    for ( node_t * current = intlist->head; current != NULL ; current = current->next ) {
        printf(" %d", current->data);
    }
    putchar('\n');
    */

    node_t * current = intlist->head;
    while (current != NULL) {
        if (current->data == target) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}


// joins different L1, L2 such that L1 <- L1 + L2, frees L2
void LLcatenate(LL_t * L1, LL_t * L2) {
    if (L2->head == NULL) {
        assert(L2->tail == NULL);
    } else if (L1->head == NULL) {
        assert(L1->tail == NULL);
        //L1->head = L2->head;
        //L1->tail = L2->tail;
        *L1 = *L2;
    } else {
        L1->tail->next = L2->head;
        L1->tail= L2->tail;
    }
    free(L2);
}


// Pre/Post:  intlist is sorted; newNode contains data already
void LLinsertNode(LL_t * intlist, node_t * newNode) {
    // list empty
    if (intlist->head == NULL) {
        assert(intlist->tail == NULL);
        intlist->head = newNode;
        intlist->tail = newNode;
        newNode->next = NULL;
    } else if (intlist->head->data >= newNode->data) {
        // new head
        newNode->next = intlist->head;
        intlist->head = newNode;
    } else {
        // typical case
        node_t * prev = intlist->head;
        node_t * curr = intlist->head->next;
        while (curr != NULL && curr->data < newNode->data) {
            curr = curr->next;
            prev = prev->next;
        }
        newNode->next = curr;
        prev->next = newNode;
        if (curr == NULL) {
            // new tail
            intlist->tail = newNode;
        }
    }
}

// Pre/Post:  intlist is sorted
void LLinsert(LL_t * intlist, int value) {
    node_t *newNode = malloc(sizeof(node_t));
    if (newNode != NULL) {
        newNode->data = value;
        LLinsertNode(intlist, newNode);
    }
}

// ***********************************
// ***** IMPLEMENT METHODS BELOW *****
// ***********************************

// Removes and returns the head of the list; 
// returns -1 if empty
int LLremoveHead(LL_t * intlist) {
	if (intlist -> head == NULL)
		return -1;
	else
	{
		int data = intlist -> head -> data;
		node_t * temp = intlist -> head;
		intlist -> head = intlist -> head -> next;
		if (intlist -> head == NULL)
			intlist -> tail = NULL;
		free(temp);
		return data;
	}
}

// Removes a list and all of the nodes it contains from memory
void LLdestroy(LL_t * intlist) {
	while(intlist -> head != NULL)
		LLremoveHead(intlist);
}
