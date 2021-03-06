#ifndef __FORWARDER_HPP
#define __FORWARDER_HPP

template<typename Function, typename ...Params>
void forwarder(Function fun, Params &&...params)
{
    fun(std::forward<Params>(params)...);
}

#endif