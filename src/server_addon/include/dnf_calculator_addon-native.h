#pragma once

#include <napi.h>

class DnfCalculatorAddon : public Napi::ObjectWrap<DnfCalculatorAddon>
{
public:
    DnfCalculatorAddon(const Napi::CallbackInfo&);
    Napi::Value Greet(const Napi::CallbackInfo&);

    static Napi::Function GetClass(Napi::Env);

private:
    std::string _greeterName;
};
