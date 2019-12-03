class battery : private component
{
    public:
        string name;
        float voltage;

};

class resistor
{
    public:
        string name;
        float resistance;
};

class capacitor
{
    public:
        string name;
        float storage;
};

class component {
    protected:
        char p;
        char n;
};
