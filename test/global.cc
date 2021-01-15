#include "napi.h"

using namespace Napi;

namespace {

void SetPropertyWithNapiValue(const CallbackInfo& info) {
  Env env = info.Env();
  Object global = env.Global();
  Name key = info[0].As<Name>();
  Value value = info[1];
  global.Set(static_cast<napi_value>(key), value);
}

void SetPropertyWithNapiWrapperValue(const CallbackInfo& info) {
  Env env = info.Env();
  Object global = env.Global();
  Name key = info[0].As<Name>();
  Value value = info[1];
  global.Set(key, value);
}

void SetPropertyWithCStyleString(const CallbackInfo& info) {
  Env env = info.Env();
  Object global = env.Global();
  String jsKey = info[0].As<String>();
  Value value = info[1];
  global.Set(jsKey.Utf8Value().c_str(), value);
}

void SetPropertyWithCppStyleString(const CallbackInfo& info) {
  Env env = info.Env();
  Object global = env.Global();
  String jsKey = info[0].As<String>();
  Value value = info[1];
  global.Set(jsKey.Utf8Value(), value);
}

Value GetPropertyWithNapiValue(const CallbackInfo& info) {
  Env env = info.Env();
  Object global = env.Global();
  Name key = info[0].As<Name>();
  return global.Get(key);
}

Value GetPropertyWithNapiWrapperValue(const CallbackInfo& info) {
  Env env = info.Env();
  Object global = env.Global();
  Name key = info[0].As<Name>();
  return global.Get(key);
}

Value GetPropertyWithCStyleString(const CallbackInfo& info) {
  Env env = info.Env();
  Object global = env.Global();
  String jsKey = info[0].As<String>();
  return global.Get(jsKey.Utf8Value().c_str());
}

Value GetPropertyWithCppStyleString(const CallbackInfo& info) {
  Env env = info.Env();
  Object global = env.Global();
  String jsKey = info[0].As<String>();
  return global.Get(jsKey.Utf8Value());
}

} // end anonymous namespace

Object InitGlobal(Env env) {
  Object exports = Object::New(env);
  exports["setPropertyWithNapiValue"] = Function::New(env, SetPropertyWithNapiValue);
  exports["setPropertyWithNapiWrapperValue"] = Function::New(env, SetPropertyWithNapiWrapperValue);
  exports["setPropertyWithCStyleString"] = Function::New(env, SetPropertyWithCStyleString);
  exports["setPropertyWithCppStyleString"] = Function::New(env, SetPropertyWithCppStyleString);
  exports["getPropertyWithNapiValue"] = Function::New(env, GetPropertyWithNapiValue);
  exports["getPropertyWithNapiWrapperValue"] = Function::New(env, GetPropertyWithNapiWrapperValue);
  exports["getPropertyWithCStyleString"] = Function::New(env, GetPropertyWithCStyleString);
  exports["getPropertyWithCppStyleString"] = Function::New(env, GetPropertyWithCppStyleString);
  return exports;
}
