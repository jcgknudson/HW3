#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);

	list_t* cur_elt = head;
	list_t* prev_elt = NULL;
	//Find spot of insertion
	while(cur_elt != NULL && cur_elt->index < new_element->index){
		prev_elt = cur_elt;
		cur_elt = cur_elt->next;
	}

	//Insert before head
	if(prev_elt == NULL){
		new_element->next = head;
		return new_element;
	}

	prev_elt->next = new_element;
	new_element->next = cur_elt;

	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);

	list_t* cur = head;
	list_t* new_list_head = NULL;

	while(cur){
		list_t* next = cur->next;
		cur->next = new_list_head;
		new_list_head = cur;
		cur = next;
	}

	return new_list_head;
}

