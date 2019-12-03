class Sorted_List
{
    public:
        Sorted_List() = default;
        void insert(int);
        bool is_empty();
        int size();
        void print();
        void remove_value(int);
        ~Sorted_List();
        Sorted_List(Sorted_List const& other);
        Sorted_List& operator=(Sorted_List const& other);
        Sorted_List(Sorted_List && other);
        Sorted_List& operator=(Sorted_List&& other);
        void clean();

    private:
        struct node
        {
            int data{};
            node* next{};
        };
        node* first{nullptr};
        int list_size{0};
        void insert(int, node*);
        void print(node*);
};