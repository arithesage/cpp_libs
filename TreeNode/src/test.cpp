#include <iostream>

using String = std::string;

#include <TreeNode.hpp>


int main ()
{
    TreeNode<String> root ("Root", new String ("One"));
    root.AddNewNode ("Child", new String ("Two"));

    std::cout << "Root: " << root.Data () << std::endl;
    std::cout << " - Child: " << root.Child(0)->Data() << std::endl;

    return 0;
}