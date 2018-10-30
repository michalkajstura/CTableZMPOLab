#ifndef CTABLE_CMENUITEM_H
#define CTABLE_CMENUITEM_H

#include <string>
#include <iostream>
#include <vector>

const std::string INSTEAD = "Zamiast tego jest: ";
const std::string EXPECTED_COMMA = "Miało być: ,";

class CMenuItem {
    protected:
        std::string loadString(std::string bigString, int *index);
        std::string m_commandName;
        std::string m_name;
        int m_arguments_number;
    public:
        virtual void run(std::vector<std::string> arguments)=0;
        virtual ~CMenuItem()=0;
        virtual std::string getName()=0;
        virtual std::string getCommandName()=0;
        virtual std::string toString()=0;
        virtual std::string save()=0;
};

#endif //CTABLE_CMENUITEM_H
