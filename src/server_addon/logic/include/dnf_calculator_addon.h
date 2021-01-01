#pragma once

#include <napi.h>

class Main;

class DnfCalculatorAddon : public Napi::ObjectWrap<DnfCalculatorAddon>
{
public:
    DnfCalculatorAddon(const Napi::CallbackInfo&);

    Napi::Value greet(const Napi::CallbackInfo&);

    Napi::Value getWeaponJson(const Napi::CallbackInfo&);
    Napi::Value getEquipmentJson(const Napi::CallbackInfo&);
    Napi::Value getEquipmentSetJson(const Napi::CallbackInfo&);

    static Napi::Function GetClass(Napi::Env);

private:
    Napi::Object parse(const Napi::Env& env, const std::string& str) const;


    std::string _greeterName;
    std::unique_ptr<Main> main_;
};
