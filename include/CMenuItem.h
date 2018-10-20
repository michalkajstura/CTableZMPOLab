#ifndef CTABLE_CMENUITEM_H
#define CTABLE_CMENUITEM_H

#include <string>
#include <iostream>

class CMenuItem {
    protected:
        std::string m_commandName;
        std::string m_name;
    public:
        virtual void run()=0;
        virtual ~CMenuItem();
        virtual std::string getName()=0;
        virtual std::string getCommandName()=0;
};

#endif //CTABLE_CMENUITEM_H
