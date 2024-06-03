#ifndef RULESET_H_INCLUDED
#define RULESET_H_INCLUDED

#include "def.h"

enum class RulesetType
{
    SurgeRuleset,
    QuantumultX,
    ClashDomain,
    ClashIpCidr,
    ClashClassic
};

struct RulesetConfig
{
    String Group;
    //RulesetType Type = RulesetType::SurgeRuleset;
    String Url;
    Integer Interval = 86400;
    bool operator==(const RulesetConfig &r) const
    {
        return Group == r.Group && Url == r.Url && Interval == r.Interval;
    }

    template<class Archive>
    void serialize(Archive & archive)
    {
        archive( Group, Url, Interval ); // serialize things by passing them to the archive
    }
};

using RulesetConfigs = std::vector<RulesetConfig>;

#endif // RULESET_H_INCLUDED
