#include <iostream>

using String = std::string;

#include <TreeNode.hpp>


void printNode (TreeNode<String>* node)
{
    std::cout << "[" << node->Name() << "]: ";
    std::cout << node->Data() << std::endl;
}


int main ()
{
    TreeNode<String> root ("Root", new String ("One"));
    root.AddNewNode ("Child", new String ("Two"));

    root.ForEachNode (printNode);

    return 0;
}