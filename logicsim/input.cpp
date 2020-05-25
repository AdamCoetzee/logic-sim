#include "input.h"
#include <iostream>

bool Input::add_output(Node *out_node)
{
    //check if node already set as output
    bool nodeExists = false;
    int i=0;
    while((i < m_outputs.size()) && (nodeExists == false))
    {
        if (out_node == m_outputs[i])
        {
            nodeExists = true;
        }
        i++;
    }
    
    if (nodeExists == false)
    {
        m_outputs.push_back(out_node);
        return true;
    }
    else
    {
        return false;
    }
}

bool Input::rem_output(Node *out_node)
{
    bool nodeExists = false;
    int nodeID = -1;
    //check if node doesn't exist and find ID of deletion query
    int i=0;
    while((i < m_outputs.size()) && (nodeExists == false))
    {
        if (out_node == m_outputs[i])
        {
            nodeExists = true;
            nodeID = i;
        }
        i++;
    }
    
    if (nodeExists == true)
    {
        m_outputs.erase(m_outputs.begin()+nodeID);
        return true;
    }
    else
    {
        return false;
    }
}

void Input::print_info()
{
    std::cout << "[NODE " << this->get_id() << "](INPUT)\n STATE: ";
    switch(this->get_state())
    {
        case node_state::UNDEFINED:
            std::cout << "UNDEFINED" << std::endl;
            break;
        case node_state::OFF:
            std::cout << "OFF" << std::endl;
            break;
        case node_state::ON:
            std::cout << "ON" << std::endl;
            break;
    }
    
    std::cout << " OUTPUTS: ";
    for (int i = 0; i<m_outputs.size(); i++)
    {
        std::cout << (m_outputs[i]->get_id()) << ", ";
    }
    
    std::cout << std::endl;
}
