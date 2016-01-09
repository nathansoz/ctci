#pragma once

#include "linked_list/linked_list_s.h"
typedef int (*testEqu)(void*, void*);
void ll_remove_duplicates(struct linked_list_s* list, testEqu equFunc);