/*
Header File for RBT_ADT
*/

#define DATA void*
#define KEY char*

#include <stdint.h>
#include <stdlib.h>

typedef struct node node;
struct node
{
  node* left;
  node* right;
  node* parent;
  // colour as boolean 0x00 = black
  uint8_t colour;
  KEY key;
  DATA data; 
};

node* makeRBT();
uint8_t contains(node* root, KEY key);
node* get(node* root, KEY key);
void insert(node* root, node* parent, KEY key, DATA data);
void* delete(node* root, KEY key);
node* createNode(node* parent, KEY key, DATA data);
uint8_t equals(KEY key1, KEY key2);
void case1(node* child);
void case2(node* child);
void case3(node* child);
void case4(node* child);
void case5(node* child);
void rotateRight(node* start);
void rotateLeft(node* start);