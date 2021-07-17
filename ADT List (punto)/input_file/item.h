#ifndef ITEM_H
#define ITEM_H
typedef struct punto *item;
#endif

#define NULLITEM 0

item input_item_file(FILE *file);

item input_item(void);

item creapunto(float x, float y);

int eq(item p1, item p2);

float ascissa(item p);

float ordinata(item p);

float distanza(item p1, item p2);

void output_item (item p);
