#pragma once

#include "dnf_calculator_addon.h"

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    Napi::String name = Napi::String::New(env, "DnfCalculatorAddon");
    exports.Set(name, DnfCalculatorAddon::GetClass(env));

    return exports;
}

NODE_API_MODULE(addon, Init)
