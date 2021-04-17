stack <int> s;
stack <int> ms;

MinStack::MinStack() {
    
    s = stack <int> ();
    ms = stack <int> ();
}

void MinStack::push(int x) {
    
    s.push(x);
    if(ms.empty())
        ms.push(x);
    else
    {
        if(x <= ms.top())
            ms.push(x);
        else
            ms.push(ms.top());
    }
}

void MinStack::pop() {
    
    if(!s.empty())
    {
        s.pop();
        ms.pop();
    }
}

int MinStack::top() {
    
    if(s.empty())
        return -1;
    return s.top();
}

int MinStack::getMin() {
    
    if(ms.empty())
        return -1;
    return ms.top();
}

