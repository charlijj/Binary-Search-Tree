
#include "KV.h"
#include <iostream>


int KVtree::size()
{
   return nnodes;
}

void KVtree::printData(long key, std::string desc, double value)
{
   std::cout << key << ":" << value << ";" << desc << std::endl;
}


KVtree::KVnode *KVtree::create(long key, std::string desc, double value)
{
   KVnode * n = new KVnode;

   if (n != NULL)
   {
      n->key = key;
      n->desc = desc;
      n->value = value;
      n->left = NULL;
      n->right = NULL;
   }

   return n;
}

void KVtree::deallocate(KVnode *n)
{
   if(n != NULL)
   {
      deallocate(n->left);
      deallocate(n->right);
      delete n;
   }
}

void KVtree::inorder(KVnode *n)
{
   if (n == NULL)
   {
      return;
   }

   inorder(n->left);
   printData(n->key, n->desc, n-> value);
   inorder(n->right);
   
}

KVtree::KVtree()
{
   root = NULL;
   nnodes = 0;
}

KVtree::~KVtree()
{
   deallocate(root);
}

bool KVtree::lookup(long k, std::string &d, double &v)
{
   KVnode * n = lookup(k, root);

   if (n != NULL)
   {
      d = n->desc;
      v = n->value;
      return true;
   }
   else
   {
      return false;
   }

}

bool KVtree::insert(long k, std::string d, double v)
{
   // If key is already exists in tree
   KVnode* n = lookup(k, root);
   if (n) {
      // Update data fields
      n->desc = d;
      n->value = v;
      return true;
   }

   // If key does not exist
   n = create(k, d, v);

   if (n != NULL) {
      if( insert(root, n))
      {
         nnodes++;
         return true;
      }
      // If n was created but not inserted, delete n
      else
      {
         delete n;
      }
      
   }
   // If n was not created
   return false;

}

void KVtree::print()
{
   // Print each node in order starting from root
   inorder(root);
}


KVtree::KVnode *KVtree::lookup(long k, KVnode *n)
{
   // If tree is empty no need to search
   if (n == NULL)
   {
      return NULL;
   }

   // If the requested key is found, return that node
   if(n->key == k)
   {
      return n;
   }

   // If the reqested key is less than the currant node's key, search left subtree
   if (n->key > k)
   {
      return lookup(k, n->left);
   }
   // If the reqested key is greater than the currant node's key, search right subtree
   return lookup(k, n->right);
}

bool KVtree::insert(KVnode* &subtree, KVnode* n)
{

   if (n == NULL) {
      return false;
   }

   // If subtree has no children, insert location is found
   if (subtree == NULL) {
      subtree = n;
      return true;
   }

   // If new key is less than the subtree's key, insert location will be in the left subtree
   if (n->key < subtree->key) {
      return insert(subtree->left, n);

   } 
   // If new key is greater than subtree's key, insert location will be in the right subtree
   else 
   {
      return insert(subtree->right, n);
   }
}


