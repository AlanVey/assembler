/* 
Red Black Tree Abstract Data Type
(Faster insertion/deletion than AVL tree, not as rigidly balanced as though)
    Polymorphic by setting up the following:
        DATA = data type
        KEY = key type
        equals() = method to determine if two keys are equal 
NOTE: get() returns reference to the node be sure not to change internal pointers
      delete() unimplemented
*/

#include "RBT_ADT.h"

node* makeRBT()
{
  node* root = malloc(sizeof(node));
  return root = NULL;
}

uint8_t contains(node* root, KEY key)
{
  if(root == NULL)
    return 0;
  else
  {
    switch(equals(root->key, key))
    {
      case 0: return 1; break;
      case 1: return contains(root->left, key); break;
      case 2: return contains(root->right, key); break;
    }

  }
  return 0;
}

// returns 0 if not found
node* get(node* root, KEY key)
{
  if(root == NULL)
    return 0;
  else
  {
    switch(equals(root->key, key))
    {
      case 0: return root; break;
      case 1: return get(root->left, key); break;
      case 2: return get(root->right, key); break;
    }
  }
  return NULL;
}

void insert(node* root, node* parent, KEY key, DATA data)
{
  if(root == NULL)
  {
    if(parent == NULL) 
      root = createNode(NULL, key, data);
    else
    {
      root = createNode(parent, key, data);
      if(parent->left == NULL)
      {
        if(parent->right == NULL)
        { 
          if(equals(root->key, key) == 1)
            parent->left = root;
          else
            parent->right = root;
        }
        else
          parent->left = root;
      }
      else
        parent->right = root;
    }
    case1(root);
  }
  else
  {
    switch(equals(root->key, key))
    {
      case 0: root->data = data; break;
      case 1: insert(root->left, root, key, data); break;
      case 2: insert(root->right, root, key, data); break;
    }
  }
}

// returns 0 if not found
void* delete(node* root, KEY key)
{
  return NULL;
}

//===================ADT Helper Methods====================================

// returns 1 for key1 > key 2, 2 for key1 < key2, 0 otherwise
uint8_t equals(KEY key1, KEY key2)
{
  if(key1 - key2 > 0)
    return 1;
  else if(key1 - key2 < 0)
    return 2;
  else
    return 0;
}

node* createNode(node* parent, KEY key, DATA data)
{
  node* new_node = malloc(sizeof(node));
  new_node->left = NULL;
  new_node->right = NULL;
  new_node->parent = parent;
  new_node->colour = 1;
  new_node->key = key;
  new_node->data = data;
  return new_node;
}

void case1(node* child)
{
  if(child->parent == NULL) 
    child->colour = 0;
  else case2(child);
}

void case2(node* child)
{
  if(child->parent->colour != 0) 
    case3(child);
}

void case3(node* child)
{
  node* uncle = NULL;
  if(child->parent->parent->left != child->parent)
    uncle = child->parent->parent->left;
  else
    uncle = child->parent->parent->right;

  if(uncle->colour != 0)
  {
    child->parent->colour = 0;
    uncle->colour = 0;
    uncle->parent->colour = 1;
    case2(uncle->parent);
  }
  else
    case4(child);
}

void case4(node* child)
{
  node* parent =  child->parent;
  node* grandParent = parent->parent;
  if(grandParent->left == parent && parent->right == child)
    rotateLeft(parent);
  else
    rotateRight(parent);
}

void case5(node* child)
{
  node* parent = child->parent;
  node* grandParent = parent->parent;

  grandParent->colour = 1;
  parent->colour = 0;

  if(grandParent->left == parent && parent->left == child)
    rotateRight(grandParent);
  else
    rotateLeft(grandParent);
}

void rotateRight(node* start)
{
  node* left = start->left;
  start->left = left->right;
  left->right->parent = start;
  left->right = start;
  start->parent = left;
}

void rotateLeft(node* start)
{
  node* right = start->right;
  start->right = right->left;
  right->left->parent = start;
  right->left = start;
  start->parent = right;
}