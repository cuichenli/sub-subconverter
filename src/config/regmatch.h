#ifndef REGMATCH_H_INCLUDED
#define REGMATCH_H_INCLUDED

#include "def.h"

struct RegexMatchConfig
{
    String Match;
    String Replace;
    String Script;

    template<class Archive>
    void serialize(Archive & archive)
    {
        archive(Match, Replace, Script); 
    }
};

using RegexMatchConfigs = std::vector<RegexMatchConfig>;

#endif // REGMATCH_H_INCLUDED
