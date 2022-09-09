#include <iostream>
#include <stdexcept>
struct Node
{
    char value;
    Node *next;

    Node(char _value, Node *_next = nullptr) : value(_value),
                                               next(_next)
    {
    }
};

class Stack
{
    Node *head = nullptr;

public:
    Stack() : head(nullptr) {}
    void push(int x)
    {
        head = new Node(x, head);
    }

    bool empty() const
    {
        return head == nullptr;
    }

    char top() const
    {
        if (empty())
        {
            throw std::runtime_error("top on an empty stack");
        }
        return head->value;
    }

    void pop()
    {
        if (empty())
        {
            throw std::runtime_error("pop on an empty stack");
        }
        pop_unsafe();
    }

    void clear()
    {
        while (!empty())
        {
            pop_unsafe();
        }
    }

    ~Stack()
    {
        clear();
    }

private:
    void pop_unsafe()
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
};

bool is_balanced(std::string str)
{
    Stack balance;
    bool notNeedNextIf = true;
    int length = str.length();
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '\'' || str[i] == '\"')
        {
            if (balance.empty())
            {
                balance.push(str[i]);
                notNeedNextIf = false;
            }
            else if (balance.top() != '\'' && balance.top() != '\"')
            {
                balance.push(str[i]);
                notNeedNextIf = false;
            }
            else if (balance.top() == '\'')
            {
                if (str[i] == '\'')
                {
                    balance.pop();
                    notNeedNextIf = false;
                }
                else
                {
                    continue;
                }
            }
            else if (balance.top() == '\"')
            {
                if (str[i] == '\"')
                {
                    balance.pop();
                    notNeedNextIf = false;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                continue;
            }
        }
        else if (!balance.empty())
        {
            if (balance.top() == '\'' || balance.top() == '\"')
            {
                continue;
            }
        }
        // if (notNeedNextIf)
        // {
            if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            {
                balance.push(str[i]);
            }
            else
            {
                if (str[i] == ')')
                {
                    if (balance.top() == '(')
                    {
                        balance.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (str[i] == '}')
                {
                    if (balance.top() == '{')
                    {
                        balance.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (str[i] == ']')
                {
                    if (balance.top() == '[')
                    {
                        balance.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        // }
    }
    if (balance.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    std::string s = "asdf";
    std::cout << std::boolalpha;
    std::cout << s << ": " << is_balanced(s) << std::endl;
    s = "()";
    std::cout << s << ": " << is_balanced(s) << std::endl;
    s = "([])";
    std::cout << s << ": " << is_balanced(s) << std::endl;
    s = "([)]";
    std::cout << s << ": " << is_balanced(s) << std::endl;
    s = "[()]";
    std::cout << s << ": " << is_balanced(s) << std::endl;
    s = "[()";
    std::cout << s << ": " << is_balanced(s) << std::endl;
    s = "[(";
    std::cout << s << ": " << is_balanced(s) << std::endl;
    s = "[(([])[()])]";
    std::cout << s << ": " << is_balanced(s) << std::endl;
    s = "[(' ')]";
    std::cout << s << ": " << is_balanced(s) << std::endl;
    s = "[('[')]";
    std::cout << s << ": " << is_balanced(s) << std::endl;
    s = "[('[()')]";
    std::cout << s << ": " << is_balanced(s) << std::endl;
    s = "[('[()')(\")\")]";
    std::cout << s << ": " << is_balanced(s) << std::endl;
    s = "\"()[]";
    std::cout << s << ": " << is_balanced(s) << std::endl;
    s = "\"'''\"";
    std::cout << s << ": " << is_balanced(s) << std::endl;
    s = "'''";
    std::cout << s << ": " << is_balanced(s) << std::endl;
    s = "\"\"\"";
    std::cout << s << ": " << is_balanced(s) << std::endl;
    s = "'\"'\"\"";
    std::cout << s << ": " << is_balanced(s) << std::endl;
    return 0;
}