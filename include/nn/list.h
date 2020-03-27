#ifndef _NN_LIST_H_
#define _NN_LIST_H_

/**
 * Malloc free list implementation.
 */

#ifdef __cplusplus
extern "C" {
#endif

struct nn_list_item;

struct nn_list_item {
    struct nn_list_item* next;
    struct nn_list_item* prev;

    void* element;
};

struct nn_list {
    struct nn_list_item sentinel;
};

struct nn_list_iterator {
    const struct nn_list* list;
    struct nn_list_item* item;
};

// malloc free list

void nn_list_init(struct nn_list* list);
void nn_list_deinit(struct nn_list* list);


// return true if the list is empty
bool nn_list_empty(const struct nn_list* list);

size_t nn_list_size(const struct nn_list* list);

// add an item to the end of the list
void nn_list_append(struct nn_list* list, struct nn_list_item* item, void* element);

// erase an element from the list.
void nn_list_erase_item(struct nn_list_item* item);

void nn_list_erase_iterator(struct nn_list_iterator* iterator);

// return front element of the list or NULL if empty
struct nn_list_iterator nn_list_begin(const struct nn_list* list);

void nn_list_next(struct nn_list_iterator* iterator);

bool nn_list_end(const struct nn_list_iterator* iterator);

void* nn_list_get_element(const struct nn_list_iterator* iterator);
struct nn_list_item* nn_list_get_item

#ifdef __cplusplus
} //extern "C"
#endif

#endif
