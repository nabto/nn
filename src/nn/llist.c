#include <nn/llist.h>

void nn_llist_init(struct nn_llist* llist)
{
    llist->sentinel.next = &llist->sentinel;
    llist->sentinel.prev = &llist->sentinel;
    llist->sentinel.item = NULL;
}


void nn_llist_deinit(struct nn_llist* llist)
{

}


// return true if the llist is empty
bool nn_llist_empty(const struct nn_llist* llist)
{
    return llist->sentinel.next == &llist->sentinel;
}

size_t nn_llist_size(const struct nn_llist* llist)
{
    size_t size = 0;
    void* item;
    NN_LLIST_FOREACH(item, llist) {
        size++;
    }
    return size;
}

// add an node to the end of the llist
struct nn_llist_iterator nn_llist_append(struct nn_llist* llist, struct nn_llist_node* node, void* item)
{
    node->item = item;
    struct nn_llist_node* before = llist->sentinel.prev;
    struct nn_llist_node* after = before->next;

    before->next = node;
    node->next = after;
    after->prev = node;
    node->prev = before;

    struct nn_llist_iterator it;
    it.list = llist;
    it.node = node;
    return it;
}

// erase an node from the llist.
void nn_llist_erase_node(struct nn_llist_node* node)
{
    struct nn_llist_node* before = node->prev;
    struct nn_llist_node* after = node->next;
    before->next = after;
    after->prev = before;

    node->prev = node;
    node->next = node;
}

void nn_llist_erase(struct nn_llist_iterator* iterator)
{
    nn_llist_erase_node(iterator->node);
}

// return iterator pointing to the front of the llist
struct nn_llist_iterator nn_llist_begin(const struct nn_llist* llist)
{
    struct nn_llist_iterator iterator;
    iterator.list = llist;
    iterator.node = llist->sentinel.next;
    return iterator;
}

void nn_llist_next(struct nn_llist_iterator* iterator)
{
    iterator->node = iterator->node->next;
}

struct nn_llist_iterator nn_llist_end(const struct nn_llist* llist)
{
    struct nn_llist_iterator iterator;
    iterator.list = llist;
    iterator.node = &llist->sentinel;
    return iterator;
}

bool nn_llist_is_end(const struct nn_llist_iterator* iterator)
{
    return iterator->node == &iterator->list->sentinel;
}

struct nn_llist_node* nn_llist_get_node(const struct nn_llist_iterator* iterator)
{
    return iterator->node;
}

void* nn_llist_get_item(const struct nn_llist_iterator* iterator)
{
    return iterator->node->item;
}
