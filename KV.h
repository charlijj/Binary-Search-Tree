#pragma once

#include <string>

// a binary search tree of KVnodes, organized by key:
//       nodes whose keys are <= current node's key are located in left subtree,
//       greater keys are located in the right subtree
class KVtree {

   private:
      // internal container type for individual nodes
      struct KVnode {
         long key;           // unique key (no value restriction)
         std::string desc;   // a one-line description (empty strings are acceptable)
         double value;       // any real number (no vallue restriction)
         KVnode *right;       // pointer to the root of this node's right subtree
         KVnode *left;       // pointer to the root of this node's left subtree
      };

      // allocate and initialize a KVnode
      KVnode *create(long key, std::string desc, double value);

      // insert the given (non-null) node into the subtree
      bool insert(KVnode* &subtree, KVnode* n);

      // deletes each KVnode in the subtree rooted at n
      void deallocate(KVnode *n);

      // if the given key, k, is found in the given subtree
      //    return the pointer to the node containing k
      KVnode *lookup(long k, KVnode* n);

      // perform an inorder traversal from the given subtree node,
      // displaying each node's data (using printData)
      void inorder(KVnode *n);

      // tree data fields
      KVnode *root;  // original tree node (null when tree is empty)
      int nnodes;    // count of the number of nodes currently stored in tree


   public:
      // initializes the tree as empty (setting root to null, nnodes to 0)
      KVtree();

      // delete all tree nodes
      ~KVtree();

      // display a key/desc/value set
      // (this is a static method: only uses its parameters, independent of current tree's data)
      static void printData(long key, std::string desc, double value);

      // if key k is already in use within the tree
      //    this updates its associated v and d fields
      //    then returns true
      // otherwise
      //    this attempts to allocate a new KVnode
      //    if the allocation fails then it returns false
      //    otherwise it inserts the new node into the tree
      bool insert(long k, std::string d, double v);

      // if the given key, k, is found in the tree
      //    copy its desc and value fields to d and v
      //    and return true
      // otherwise return false
      bool lookup(long k, std::string &d, double &v);

      // return the current size of the tree (nnodes)
      int size();

      // display all the entries currently in the tree, in sorted order by key
      //     (i.e. carrying out an in-order traversal of the tree)
      //     using calls to KVnode's printData to display individual node info
      void print();

};



