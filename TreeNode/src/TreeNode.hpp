#ifndef __TREENODE_

#include <iostream>


// Base class for n-ary tree node data containers
template <typename DataType>
class TreeNodeData
{
    public:
        virtual ~TreeNodeData () {}
        virtual DataType Data () = 0;
};


// Base class for n-ary tree nodes
class TreeNode
{
    protected:
        TreeNodeData* data;

    public:
        virtual ~TreeNode () {}
        virtual Data () = 0;
};


class StringND : public TreeNodeData
{
    private:
        std::string str;

    public:
        StringND (std::string data);
};


class StringNode : public TreeNode
{
    public:
        StringNode (std::string data);

};


StringNode::StringNode (std::string data)
{
    StringNode* node = 
}
#endif










