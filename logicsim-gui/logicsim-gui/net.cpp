#include "net.h"

Net::Net(const int &id)
{
    this->set_state(node_state::UNDEFINED);
    this->set_id(id);
    MAXINPUTS=-1;
    STR_NODETYPE = "NET";
}

bool Net::calc_state()
{
    std::cout<<"resolving node "<<this->get_id()<<std::endl;
    bool offFound = false;
    bool onFound = false;
    for (unsigned int i = 0; i<m_inputs.size(); i++)
    {
        switch(m_inputs[i]->get_state())
        {
            case node_state::UNDEFINED:
                std::cout<<"Warning: "<<this->get_id()<<" calculating state from unresolved input ("<<m_inputs[i]->get_id()<< ")" <<std::endl;
                break;
            case node_state::ON:
                onFound = true;
                break;
            case node_state::OFF:
                offFound = true;
                break;
        }
    }

    if (onFound == true)
    {
        this->set_state(node_state::ON);
        return true;
    }
    else if (offFound == true)
    {
        this->set_state(node_state::OFF);
        return true;
    }
    else
    {
        this->set_state(node_state::UNDEFINED);
        std::cout<<"Warning: Failed to resolve state for node "<<this->get_id()<<std::endl;
        return false;
    }
}


