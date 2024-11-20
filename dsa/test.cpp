#include <iostream>
#include <string>
#include <filesystem>

template <typename T>
class GenericTree
{
private:
    struct Node
    {
        T data;      // Could be a folder path or a file path
        bool isFile; // True if it's a file, false if it's a folder
        Node *first_subdir;
        Node *next_sub_dir;

        Node(const T &value, bool file) : data(value), isFile(file), first_subdir(nullptr), next_sub_dir(nullptr) {}
    };

    Node *main_folder;
    size_t count;

public:
    GenericTree(const T &value, bool isFile) : main_folder(new Node(value, isFile)), count(1) {}

    void addChild(Node *parent, const T &childValue, bool isFile)
    {
        Node *childNode = new Node(childValue, isFile);
        if (!parent->first_subdir)
        {
            parent->first_subdir = childNode;
        }
        else
        {
            Node *temp = parent->first_subdir;
            while (temp->next_sub_dir)
            {
                temp = temp->next_sub_dir;
            }
            temp->next_sub_dir = childNode;
        }
        count++;
    }

    void addFolderWithContents(Node *parent, const T &folderPath)
    {
        addChild(parent, folderPath, false);  
        Node *folderNode = parent->first_subdir;

        for (const auto &entry : std::filesystem::directory_iterator(folderPath))
        {
            if (entry.is_directory())
            {
                addFolderWithContents(folderNode, entry.path().string()); // Recursive call for subdirectories
            }
            else if (entry.is_regular_file())
            {
                addChild(folderNode, entry.path().string(), true); // Add files
            }
        }
    }

    Node *GetRoot()
    {
        return main_folder;
    }

    size_t size() const
    {
        return count;
    }

    void checkFilesWithoutSubfolders() const
    {
        std::cout << "Files without subfolders:\n";
        checkFilesWithoutSubfolders(main_folder);
    }

    ~GenericTree()
    {
        clear(main_folder);
    }

private:
    void clear(Node *node)
    {
        if (node)
        {
            clear(node->first_subdir);
            clear(node->next_sub_dir);
            delete node;
        }
    }

    void checkFilesWithoutSubfolders(Node *node) const
    {
        if (!node)
            return;

        if (node->isFile && !node->first_subdir)
        {
            std::cout << node->data << " (File)\n"; // No subfolders
        }

        checkFilesWithoutSubfolders(node->first_subdir);
        checkFilesWithoutSubfolders(node->next_sub_dir);
    }
};

int main()
{
    // Assuming "C:\\Root" is a directory that exists
    GenericTree<std::string> tree("C:\\Root", false); // Assuming the main_folder is a directory

    // Add folders and their contents
    tree.addFolderWithContents(tree.GetRoot(), "C:\\Root\\Folder1"); // This folder's contents will be added automatically
    tree.addChild(tree.GetRoot(), "File1.txt", true);                // Add a file manually

    tree.checkFilesWithoutSubfolders(); // This will print files without subfolders

    return 0;
}
