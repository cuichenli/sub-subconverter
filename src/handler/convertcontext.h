#ifndef CONVERTCONTEXT_H_INCLUDED
#define CONVERTCONTEXT_H_INCLUDED
#include "utils/string.h"

struct base_configs 
{
    std::string clashBase;
    std::string surgeBase;
    std::string mellowBase;
    std::string surfboardBase;
    std::string quanBase;
    std::string quanXBase;
    std::string loonBase;
    std::string SSSubBase;
    std::string singBoxBase;
    RulesetConfigs customRulesets;
    ProxyGroupConfigs customProxyGroups;
    string_array includeRemarks;
    string_array excludeRemarks;
    std::vector<RulesetContent> rulesetContent;

    base_configs() = default;

    base_configs(Settings global) 
    {
        this->clashBase = global.clashBase;
        this->surgeBase = global.surgeBase;
        this->mellowBase = global.mellowBase;
        this->surfboardBase = global.surfboardBase;
        this->quanBase = global.quanBase;
        this->quanXBase = global.quanXBase;
        this->loonBase = global.loonBase;
        this->SSSubBase = global.SSSubBase;
        this->singBoxBase = global.singBoxBase;
        this->customRulesets = global.customRulesets;
        this->customProxyGroups = global.customProxyGroups;
        this->includeRemarks = global.includeRemarks;
        this->excludeRemarks = global.excludeRemarks;
        this->rulesetContent;
    };
};

struct convertcontext
{
    string_multimap init_argument;
    base_configs base_configs;
    string_icase_map request_header;
    tribool argAddEmoji;
    tribool argRemoveEmoji;

    convertcontext() = default;
};


#endif