#include <iostream>
#include "SeqStack.h"

int SeqStack::isEmpty(SeqStack st)
{
    if (st.t == -1)return 1;
    else return 0;
}

void SeqStack::SeqPush(SeqStack& st, DataType x)
{
    if (st.t == st.MaxNum-1)
    {
        std::cout << "The stack is full cannot be inserted" << std::endl;
        return;
    }
    st.t++;
    st.val[st.t] = x;
}

void SeqStack::SeqPop(SeqStack& st)
{       
    if (st.t=0)
    {
        st.t--;
    }
    else
    {
        std::cout << "This SeqStack is empty." << std::endl;
    }
}

DataType SeqStack::SeqTop(SeqStack st)
{
    return st.val[st.t];
}
