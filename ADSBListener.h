#pragma once
#include <chrono>
#include <functional>
#include <thread>

namespace ADSB
{
struct Config
{
    std::chrono::duration<std::chrono::system_clock> ttl;
};

struct IModeMessage
{
    virtual ~IModeMessage() = default;
};

struct IAirCraft
{
    virtual ~IAirCraft() = default;
};

struct IListener
{
    IListener(std::string_view const& deviceName) : _deviceName(deviceName) {}
    //    using Callback = std::function<void(IModeMessage const&, IAirCraft const&)>;

    virtual void OnMessage(IModeMessage const&, IAirCraft const&) = 0;
    void         Start();
    void         Stop();

    private:
    std::string _deviceName;
    //  Callback    _callback;
};
}    // namespace ADSB
