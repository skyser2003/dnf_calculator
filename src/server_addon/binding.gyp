{
  'targets': [
    {
      'target_name': 'dnf_calculator_addon-native',
      'sources': [ 'src/register.cpp' ],
      'include_dirs': ["<!@(node -p \"require('node-addon-api').include\")", "include", "logic/include", "logic/stdafx", "logic/external/json/include"],
      'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"],
      'cflags!': [ '-fno-exceptions' ],
      'cflags_cc!': [ '-fno-exceptions' ],
      'libraries': ['<(module_root_dir)/logic/x64/Debug/dnf_addon_logic'],
      'xcode_settings': {
        'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
        'CLANG_CXX_LIBRARY': 'libc++',
        'MACOSX_DEPLOYMENT_TARGET': '10.7'
      },
      'msvs_settings': {
        'VCCLCompilerTool': { 'ExceptionHandling': 1 },
      }    }
  ]
}