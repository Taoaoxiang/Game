

class CARD
{
public:
    string back() { return "X";}
    string front() { return get_string(); }
    unsigned get_value() { return value;}
    CARD(unsigned, char);
private:
    unsigned value; 
    char suit; 
protected:
    string get_string() { return to_string(value)+" of "+suit;}
};

CARD::CARD(unsigned v, char c)     
{
    value = v;
    suit = c;
}

