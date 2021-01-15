'use strict';

const buildType = process.config.target_defaults.default_configuration;
const assert = require('assert');

test(require(`./build/${buildType}/binding.node`));
test(require(`./build/${buildType}/binding_noexcept.node`));

function test(binding) {
  function testSetProperty(nativeSetProperty) {
    nativeSetProperty('test', 1);
    assert.strictEqual(global.test, 1);
  }

  function testGetProperty(nativeGetProperty) {
    global.test = 1;
    assert.strictEqual(nativeGetProperty('test'), 1);
  }

  testSetProperty(binding.global.setPropertyWithNapiValue);
  testSetProperty(binding.global.setPropertyWithNapiWrapperValue);
  testSetProperty(binding.global.setPropertyWithCStyleString);
  testSetProperty(binding.global.setPropertyWithCppStyleString);

  testGetProperty(binding.global.getPropertyWithNapiValue);
  testGetProperty(binding.global.getPropertyWithNapiWrapperValue);
  testGetProperty(binding.global.getPropertyWithCStyleString);
  testGetProperty(binding.global.getPropertyWithCppStyleString);
}
