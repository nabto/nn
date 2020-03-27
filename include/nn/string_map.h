#ifndef _NN_STRING_MAP_
#define _NN_STRING_MAP_

#include "nn_list.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Dynamic allocated map<string,string>
 */
struct nn_string_map_item {
    struct nn_list_item item;
    char* key;
    char* value;
};

struct nn_string_map {
    struct nn_list items;
};

struct nn_string_map_iterator {
    struct nn_list_iterator it;
};

/**
 * If an item with the key exists return it, else return NULL;
 */
struct nn_string_map_item* nn_string_map_get(const struct nn_string_map* map, const char* key);
struct nn_string_map_item* nn_string_map_getn(const struct nn_string_map* map, const char* key, size_t keyLength);

/**
 * insert an item into a string map
 */
nn_error_code nn_string_map_insert(struct nn_string_map* map, const char* key, const char* value);


void nn_string_map_init(struct nn_string_map* map);
void nn_string_map_deinit(struct nn_string_map* map);

void nn_string_map_destroy_item(struct nn_string_map_item* item);

bool nn_string_map_empty(const struct nn_string_map* map);
size_t nn_string_map_size(const struct nn_string_map* map);

// iterator
void nn_string_map_front(const struct nn_string_map* map, struct nn_string_map_iterator* it);
struct nn_string_map_iterator nn_string_map_front2(const struct nn_string_map* map);
bool nn_string_map_end(const struct nn_string_map_iterator* it);
void nn_string_map_next(struct nn_string_map_iterator* it);

struct nn_string_map_item* nn_string_map_get_element(const struct nn_string_map_iterator* it);

#define NN_STRING_MAP_FOREACH(item, map) for(struct nn_string_map_iterator it = nn_string_map_front2(map); item = nn_string_map_get_element(&it), !nn_string_map_end(&it); nn_string_map_next(&it))

#ifdef __cplusplus
} //extern "C"
#endif

#endif
