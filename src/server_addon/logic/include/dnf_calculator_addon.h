#pragma once

#include <memory>

#include <napi.h>

class Main;

class DnfCalculatorAddon : public Napi::ObjectWrap<DnfCalculatorAddon>
{
public:
    DnfCalculatorAddon(const Napi::CallbackInfo&);

    Napi::Value Greet(const Napi::CallbackInfo&);

    static Napi::Function GetClass(Napi::Env);

private:
    std::string _greeterName;
    std::unique_ptr<Main> main;
};
