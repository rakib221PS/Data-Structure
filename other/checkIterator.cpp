#include <deque>
#include <iostream>
#include <vector>
using namespace std;

template <class T>
void print(const std::string &name, const T &xs)
{
    std::cout << name << ": [";
    if (!xs.empty())
    {
        std::cout << xs.front();

        for (auto it = xs.begin() + 1; it != xs.end(); ++it)
        {
            std::cout << ", " << *it;
        }
    }

    std::cout << "]" << std::endl;
}

int main()
{
    std::string a = "hello world, I will copy from this string";
    std::vector<char> chars(20, '_');
    char char_arr[15] = {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'};
    std::deque<char> other_chars(40, '#');
    std::string final_destination = ">>put it here<<";

    print("chars", chars);
    std::copy(a.begin() + 13, a.begin() + 24, chars.begin());
    print("chars", chars);

    std::cout << "char_arr: ";
    for (int i = 0; i < 15; i++)
    {
        std::cout << char_arr[i] << " ";
    }
    std::cout << std::endl;
    std::copy(chars.begin(), chars.begin() + 15, char_arr);
    std::cout << "char_arr: ";
    for (int i = 0; i < 15; i++)
    {
        std::cout << char_arr[i] << " ";
    }
    std::cout << std::endl;

    print("other_chars", other_chars);
    std::copy(char_arr, char_arr + 15, other_chars.begin());
    print("other_chars", other_chars);
    std::cout << "final_destination: " << final_destination << std::endl;
    std::copy(
        other_chars.begin(),
        other_chars.begin() + 11,
        final_destination.begin() + 2);
    std::cout << "final_destination: " << final_destination << std::endl;

    return 0;
}