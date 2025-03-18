#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

/* Notice: sometimes, Cppcheck would find the potential NULL pointer bugs,
 * but some of them cannot occur. You can suppress them by adding the
 * following line.
 *   cppcheck-suppress nullPointer
 */

/* Create an empty queue */
struct list_head *q_new()
{
    list_head *empty_head = malloc(sizeof(list_head));
    INIT_LIST_HEAD(empty_head);
    empty_head->data = NULL;
    return empty_head;
}

/* Free all storage used by queue */
void q_free(struct list_head *head)
{
    struct list_head *next;
    struct list_head *prev;
    while (head->next != head->prev) {
        next = head->next;
        prev = head->prev;

        next->prev = prev;
        prev->next = next;

        free(head);
        head = next;
    }
}

/* Insert an element at head of queue */
bool q_insert_head(struct list_head *head, char *s)
{
    struct list_head *new_node = (struct list_head) malloc(sizeof(list_head));
    if (head == NULL | new_node == NULL) {
        return false;
    } else {
        head->prev = new_node;
        new_node->next = head;
        new_node->prev = new_node;
        new_node->data = (char) malloc(sizeof(s));
        new_node->data = *s;
        return true;
    }
}

/* Insert an element at tail of queue */
bool q_insert_tail(struct list_head *head, char *s)
{
    struct list_head *new_node = (struct list_head) malloc(sizeof(list_head));
    if (head == NULL | new_node == NULL) {
        return false;
    } else {
        struct list_head *tail = head;
        while (tail->next != tail) {
            tail = tail->next;
        }
        tail->next = new_node;
        new_node->prev = tail;
        new_node->next = new_node;
        new_node->data = (char) malloc(sizeof(s));
        new_node->data = *s;
        return true;
    }
}

/* Remove an element from head of queue */
element_t *q_remove_head(struct list_head *head, char *sp, size_t bufsize)
{
    if (head == NULL) {
        return NULL;
    } else {
        free(head->data);
        head->data = (char) malloc(bufsize);
        head->data = *sp;
    }
}

/* Remove an element from tail of queue */
element_t *q_remove_tail(struct list_head *head, char *sp, size_t bufsize)
{
    if (head == NULL) {
        return NULL;
    } else {
        struct list_head *tail = head;
        while (tail->next != tail) {
            tail = tail->next;
        }
        free(tail->data);
        tail->data = (char) malloc(bufsize);
        tail->data = *sp;
    }
}

/* Return number of elements in queue */
int q_size(struct list_head *head)
{
    if (head == NULL | head->next == head->prev) {
        return -1;
    } else {
        int counter = 0;
        while (head->next != head)
            counter++;
        return counter;
    }
}

/* Delete the middle node in queue */
bool q_delete_mid(struct list_head *head)
{
    // https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
    if (head == NULL | head->next == head->prev) {
        return false;
    } else {
        struct list_head *fast = head;
        struct list_head *slow = head;
        // ptr @fast switch to next 2 node in each iteration
        // ptr @slow switch to next node in each iteration
        // this means @fast moves 2 times faster than @slow
        while (fast->next != fast) {
            // thus when the @fast moves to tail of list
            // @slow should move to middlw of list
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next->prev = slow->prev;
        slow->prev->next = slow->next;
        free(slow);
        return true;
    }
}

/* Delete all nodes that have duplicate string */
bool q_delete_dup(struct list_head *head)
{
    // https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
    return true;
}

/* Swap every two adjacent nodes */
void q_swap(struct list_head *head)
{
    // https://leetcode.com/problems/swap-nodes-in-pairs/
    if (head == NULL | head->next == head->prev) {
        return;
    } else {
        struct list_head *even = head->next;
        struct list_head *odd = head;
        struct list_head *tmp_odd, *tmp_even;
        // ptr @fast switch to next even node in each iteration
        // ptr @slow switch to next odd  node in each iteration
        // this means @fast moves 2 times faster than @slow
        while (odd->next != odd | even->next != even) {
            tmp_odd = odd->next->next;
            tmp_even = even->next->next;
            even->next = odd;
            even->prev = odd->prev;
            odd->next = tmp_odd;
            odd->prev = even;
            odd = tmp_odd;
            even = tmp_even;
        }
        return;
    }
}

/* Reverse elements in queue */
void q_reverse(struct list_head *head) {}

/* Reverse the nodes of the list k at a time */
void q_reverseK(struct list_head *head, int k)
{
    // https://leetcode.com/problems/reverse-nodes-in-k-group/
}

/* Sort elements of queue in ascending/descending order */
void q_sort(struct list_head *head, bool descend) {}

/* Remove every node which has a node with a strictly less value anywhere to
 * the right side of it */
int q_ascend(struct list_head *head)
{
    // https://leetcode.com/problems/remove-nodes-from-linked-list/
    return 0;
}

/* Remove every node which has a node with a strictly greater value anywhere to
 * the right side of it */
int q_descend(struct list_head *head)
{
    // https://leetcode.com/problems/remove-nodes-from-linked-list/
    return 0;
}

/* Merge all the queues into one sorted queue, which is in ascending/descending
 * order */
int q_merge(struct list_head *head, bool descend)
{
    // https://leetcode.com/problems/merge-k-sorted-lists/
    return 0;
}
