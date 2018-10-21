#ifndef CTABLE_CMENUITEM_H
#define CTABLE_CMENUITEM_H

#include <string>
#include <iostream>
#include <vector>

class CMenuItem {
    protected:
        std::string m_commandName;
        std::string m_name;
        int m_arguments_number;
    public:
        virtual void run(std::vector<std::string> arguments)=0;
        virtual ~CMenuItem()=0;
        virtual std::string getName()=0;
        virtual std::string getCommandName()=0;
        virtual std::string toString()=0;
};

#endif //CTABLE_CMENUITEM_H
