#ifndef __INPUT_H_INCLUDED__
#define __INPUT_H_INCLUDED__

#include <vector>
#include "node.h"

class Input : public Node
{
    private:
    std::vector<Node*> m_outputs;

    public:
    bool add_output(Node *out_node);
    bool rem_output(Node *out_node);
    void print_info();
};

#endif //__INPUT_H_INCLUDED__