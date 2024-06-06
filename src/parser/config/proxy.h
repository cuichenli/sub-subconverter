#ifndef PROXY_H_INCLUDED
#define PROXY_H_INCLUDED

#include <string>
#include <vector>
#include <cereal/cereal.hpp>

#include "utils/tribool.h"

using String = std::string;
using StringArray = std::vector<String>;

enum class ProxyType
{
    Unknown,
    Shadowsocks,
    ShadowsocksR,
    VMess,
    Trojan,
    Snell,
    HTTP,
    HTTPS,
    SOCKS5,
    WireGuard
};

inline String getProxyTypeName(ProxyType type)
{
    switch(type)
    {
    case ProxyType::Shadowsocks:
        return "SS";
    case ProxyType::ShadowsocksR:
        return "SSR";
    case ProxyType::VMess:
        return "VMess";
    case ProxyType::Trojan:
        return "Trojan";
    case ProxyType::Snell:
        return "Snell";
    case ProxyType::HTTP:
        return "HTTP";
    case ProxyType::HTTPS:
        return "HTTPS";
    case ProxyType::SOCKS5:
        return "SOCKS5";
    default:
        return "Unknown";
    }
}

struct Proxy
{
    ProxyType Type = ProxyType::Unknown;
    uint32_t Id = 0;
    uint32_t GroupId = 0;
    String Group;
    String Remark;
    String Hostname;
    uint16_t Port = 0;

    String Username;
    String Password;
    String EncryptMethod;
    String Plugin;
    String PluginOption;
    String Protocol;
    String ProtocolParam;
    String OBFS;
    String OBFSParam;
    String UserId;
    uint16_t AlterId = 0;
    String TransferProtocol;
    String FakeType;
    bool TLSSecure = false;

    String Host;
    String Path;
    String Edge;

    String QUICSecure;
    String QUICSecret;

    tribool UDP;
    tribool TCPFastOpen;
    tribool AllowInsecure;
    tribool TLS13;

    uint16_t SnellVersion = 0;
    String ServerName;

    String SelfIP;
    String SelfIPv6;
    String PublicKey;
    String PrivateKey;
    String PreSharedKey;
    StringArray DnsServers;
    uint16_t Mtu = 0;
    String AllowedIPs = "0.0.0.0/0, ::/0";
    uint16_t KeepAlive = 0;
    String TestUrl;
    String ClientId;

    template<class Archive>
    void serialize(Archive & archive)
    {
        archive(
            // Type
            CEREAL_NVP(Type), CEREAL_NVP(Id), CEREAL_NVP(GroupId), CEREAL_NVP(Group), CEREAL_NVP(Remark), CEREAL_NVP(Hostname), CEREAL_NVP(Port),
            CEREAL_NVP(Username), CEREAL_NVP(Username), CEREAL_NVP(Password), CEREAL_NVP(EncryptMethod), CEREAL_NVP(Plugin), 
            CEREAL_NVP(PluginOption), CEREAL_NVP(Protocol), CEREAL_NVP(ProtocolParam), CEREAL_NVP(OBFS), CEREAL_NVP(OBFSParam), 
            CEREAL_NVP(UserId), CEREAL_NVP(AlterId), CEREAL_NVP(TransferProtocol), CEREAL_NVP(FakeType), 
            CEREAL_NVP(TLSSecure), CEREAL_NVP(Host), CEREAL_NVP(Path), CEREAL_NVP(Edge), CEREAL_NVP(QUICSecure), CEREAL_NVP(QUICSecret), 
            CEREAL_NVP(UDP), CEREAL_NVP(TCPFastOpen), CEREAL_NVP(AllowInsecure), CEREAL_NVP(TLS13), CEREAL_NVP(SnellVersion), 
            CEREAL_NVP(ServerName), CEREAL_NVP(SelfIP), CEREAL_NVP(SelfIPv6), CEREAL_NVP(PublicKey), CEREAL_NVP(PrivateKey), 
            CEREAL_NVP(PreSharedKey), CEREAL_NVP(DnsServers), CEREAL_NVP(Mtu), CEREAL_NVP(AllowedIPs), 
            CEREAL_NVP(KeepAlive), CEREAL_NVP(TestUrl), CEREAL_NVP(ClientId)
        ); 
    }
};

#define SS_DEFAULT_GROUP "SSProvider"
#define SSR_DEFAULT_GROUP "SSRProvider"
#define V2RAY_DEFAULT_GROUP "V2RayProvider"
#define SOCKS_DEFAULT_GROUP "SocksProvider"
#define HTTP_DEFAULT_GROUP "HTTPProvider"
#define TROJAN_DEFAULT_GROUP "TrojanProvider"
#define SNELL_DEFAULT_GROUP "SnellProvider"
#define WG_DEFAULT_GROUP "WireGuardProvider"

#endif // PROXY_H_INCLUDED
