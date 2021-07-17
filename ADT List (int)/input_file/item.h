#ifndef ITEM_H
#define ITEM_H
typedef int item;
#endif

#define NULLITEM NULL

int eq(item x, item y);
void input_item(item *x); 
void output_item(item x);
