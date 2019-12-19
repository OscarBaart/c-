/*
TODO:
1. insert(), remove_value() parameters should be const. --DONE
2. Functions, size, print, isempty should be const and perhaps more? --DONE
*/
//CHANGES:
// -Added const on: insert - and remove_value parameters
// -Added const on is_empty(), size(), print() and clean() 

class Sorted_List
{
    public:
        Sorted_List() = default;
        void insert(int const&);
        bool const is_empty();
        int const& size();
        void const print();
        void remove_value(int const&);
        ~Sorted_List();
        Sorted_List(Sorted_List& other);
        Sorted_List& operator=(Sorted_List& other);
        Sorted_List(Sorted_List && other);
        Sorted_List& operator=(Sorted_List && other);
        void const clean();

    private:
        struct node
        {
            int data{};
            node* next{};
        };
        node* first{nullptr};
        int list_size{0};
        void insert(int const&, node*);
        void const print(node*);
};
