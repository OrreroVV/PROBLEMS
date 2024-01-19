#include <bits/stdc++.h>
using namespace std;

class FormatItem{
public: 
    typedef shared_ptr<FormatItem> ptr;
    FormatItem(const std::string& fmt = ""){}
    virtual ~FormatItem() {}
    
    virtual void format() = 0;
};

class MessageFormatItem: public FormatItem{
public:
    MessageFormatItem(const std::string& fmt = ""){};
    void format(){
        std::cout << "MessageFormatItem" << std::endl;
    }
};

int main()
{
    static std::map<std::string, std::function<FormatItem::ptr(const std::string& str)>> s_format_items = {
#define XX(str, C) \
         {#str, [](const std::string& fmt) { return FormatItem::ptr(new C(fmt));}}

        XX(m, MessageFormatItem),           //m:消息
#undef XX
    };
}