#include "stdafx.h"

#include "dnf_calculator_addon.h"

#include "main.h"

using namespace Napi;

#define REGISTER(func_name) DnfCalculatorAddon::InstanceMethod(#func_name, &DnfCalculatorAddon::func_name)

DnfCalculatorAddon::DnfCalculatorAddon(const Napi::CallbackInfo& info) : ObjectWrap(info), main_(new Main("src/data")) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments")
            .ThrowAsJavaScriptException();
        return;
    }

    if (!info[0].IsString()) {
        Napi::TypeError::New(env, "You need to name yourself")
            .ThrowAsJavaScriptException();
        return;
    }

    this->_greeterName = info[0].As<Napi::String>().Utf8Value();
}

Napi::Value DnfCalculatorAddon::greet(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments")
            .ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsString()) {
        Napi::TypeError::New(env, "You need to introduce yourself to greet")
            .ThrowAsJavaScriptException();
        return env.Null();
    }

    Napi::String name = info[0].As<Napi::String>();

    printf("Hello %s\n", name.Utf8Value().c_str());
    printf("I am %s\n", this->_greeterName.c_str());

    return Napi::String::New(env, this->_greeterName);
}

Napi::Value DnfCalculatorAddon::getWeaponJson(const Napi::CallbackInfo& info)
{
    auto env = info.Env();

    return parse(env, this->main_->getWeaponJson().dump());
}

Napi::Value DnfCalculatorAddon::getEquipmentJson(const Napi::CallbackInfo& info)
{
    auto env = info.Env();

    return parse(env, this->main_->getEquipmentJson().dump());
}

Napi::Value DnfCalculatorAddon::getEquipmentSetJson(const Napi::CallbackInfo& info)
{
    auto env = info.Env();

    return parse(env, this->main_->getEquipmentSetJson().dump());
}

Napi::Function DnfCalculatorAddon::GetClass(Napi::Env env) {
    return DefineClass(env, "DnfCalculatorAddon", {
        REGISTER(greet),
        REGISTER(getWeaponJson),
        REGISTER(getEquipmentJson),
        REGISTER(getEquipmentSetJson),
        });
}

Napi::Object DnfCalculatorAddon::parse(const Napi::Env& env, const std::string& str) const
{
    auto json = env.Global().Get("JSON").As<Napi::Object>();
    auto parse = json.Get("parse").As<Napi::Function>();
    auto jsonString = Napi::String::New(env, str);

    return parse.Call(json, { jsonString }).As<Napi::Object>();
}
