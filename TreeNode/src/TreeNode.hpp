#ifndef __TREENODE_
#define __TREENODE_

#include <iostream>
#include <vector>

template <typename DataType>
using List = std::vector<DataType>;

using String = std::string;




// Generic n-ary tree nodes
template <typename DataType>
class TreeNode
{
    protected:
        String name = "Unnamed";
        DataType* data = nullptr;

        TreeNode<DataType>* parent = nullptr;
        List <TreeNode<DataType>*> children;

    public:
        // Create a new empty child node
        TreeNode ()
        {
            data = new DataType ();
        }


        // Delete this node and all its children
        ~TreeNode ()
        {
            DeleteChildren ();
            ClearData ();
            Detach ();
        }


        // /* TODO
        // Adds a new empty child
        TreeNode<DataType>* AddNewNode ()
        {
            TreeNode<DataType>* newNode = new TreeNode<DataType>();
            newNode->AttachTo (this);
        }


        // Adds a new empty child with the given name
        TreeNode<DataType>* AddNewNode (String name)
        {
            return nullptr;
        }


        // Adds a new child with the given name and data
        TreeNode<DataType>* AddNewNode (String name, DataType* data)
        {
            return nullptr;
        }


        // Adds the given node to this one children
        TreeNode<DataType>* AddNode (TreeNode<DataType>* node) 
        {
            return nullptr;
        }


        // Attach this node to the given one
        TreeNode<DataType>* AttachTo (TreeNode<DataType>* node)
        {
            if (HasParent ())
            {
                Detach ();
            }

            node->children->push_back (this);
            this->parent = node;
        }


        // Returns a child node given its index
        TreeNode<DataType>* Child (int index)
        {
            return nullptr;
        }
        
        
        // Returns a child node given its name
        TreeNode<DataType>* Child (String name)
        {
            return nullptr;
        }
        
        
        // Returns how many children this node has
        int ChildCount ()
        {
            return -1;
        }


        // Returns the index of the given node
        int ChildIndex (TreeNode<DataType>* child)
        {
            for (int c = 0; c < children.size(); c ++)
            {
                if (children[c] == child)
                {
                    return c;
                }
            }

            return -1;
        }
        
        
        // Returns this node children
        List< TreeNode<DataType>* >& Children ()
        {
            return children
        }


        // Deletes this node data
        void ClearData ()
        {
            if (data != nullptr)
            {
                delete data;
                data = nullptr;
            }
        }
        
        
        // Copies this node below another
        // This creates a copy of this node and attach to the given one
        void CopyTo (TreeNode<DataType>* node)
        {

        }
        
        
        // Copies this node below another with another name
        void CopyTo (TreeNode<DataType>* node, String newName)
        {

        }
        
        
        // Returns this node data
        DataType* Data ()
        {
            return data;
        }
        
        
        // Delete this node
        void Delete ()
        {
            this->Detach ();
            delete this;
        }
        
        
        // Delete the given child
        void DeleteChild (TreeNode<DataType>* child)
        {
            for (int i = 0; i < children.size(); i ++)
            {
                if (children[i] == child)
                {
                    DeleteChild (child);
                }
            }
        }
        
        
        // Delete a child node given its index
        void DeleteChild (int childIndex)
        {
            if (HasChild (childIndex))
            {
                children.erase (children.begin() + childIndex);
            }
        }


        // Delete this node children
        void DeleteChildren ()
        {
            for (TreeNode<DataType>* child : children)
            {
                delete child;
            }

            children.clear ();
        }
        
        
        // Detach this node.
        // This will both unlink it from its parent and remove
        // from the parent children list.
        TreeNode<DataType>* Detach ()
        {
            TreeNode<DataType>* oldParent = parent;

            if (oldParent != nullptr)
            {

            }
        };


        // Detach the given node
        // This will both unlink it from its parent and remove
        // from the parent children list.
        void DetachNode (TreeNode<DataType>* node)
        {
            if (node != nullptr)
            {
                node->Dettach ();
            }
        }


        TreeNode<DataType>* findNode (TreeNode<DataType>* fromNode, 
                                      const String& name)
        {
            if (fromNode->name == name)
            {
                return fromNode;
            }

            for (TreeNode<DataType>* child : fromNode->children)
            {
                TreeNode<DataType>* foundNode = findNode (child, name);

                if (foundNode != nullptr)
                {
                    return foundNode;
                }
            }

            return nullptr;
        }


        List<TreeNode<DataType>*> findNodes (TreeNode<DataType>* fromNode,
                                             const String& name)
        {
            List<TreeNode<DataType>*> foundNodes;

            if (fromNode->name == name)
            {
                foundNodes.push_back(fromNode);
            }

            for (TreeNode<DataType>* child : fromNode->children)
            {
                List<TreeNode<DataType>*> foundChildren = 
                    findNodes (child, name);
                
                foundNodes.insert (foundNodes.end(), 
                                   foundChildren.begin(), 
                                   foundChildren.end());
            }

            return foundNodes;
        }


        TreeNode<DataType>* FindNode (String nodeName)
        {
            return findNode (this, nodeName);
        }


        List<TreeNode<DataType>*> FindNodes (String nodeName)
        {
            return findNodes (this, nodeName);
        }


        void ForEachNode (void (*action) (TreeNode<DataType>* node ))
        {
            // TODO
        }


        bool HasChild (int childIndex)
        {
            return ((childIndex >= 0) && (childIndex < ChildCount()));
        }


        bool HasParent ()
        {
            return !IsRoot ();
        }


        bool IsRoot ()
        {
            return (parent == nullptr);
        }


        bool MoveTo (TreeNode<DataType>* newParent)
        {
            if (newParent == nullptr)
            {
                return false;
            }
            
            // TODO
            return true;
        }


        String Name ()
        {
            return name;
        }


        TreeNode<DataType>* Parent ()
        {
            return parent;
        }


        TreeNode<DataType>* Root ()
        {
            if (parent == nullptr)
            {
                return this;
            }
            else
            {
                return parent->Root ()
            }
        }


        void SetData (DataType* data)
        {
            this->data = data;
        }


        void SetName (String name)
        {
            this->name = name;
        }
        // TODO */
};
#endif










