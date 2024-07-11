import sysconfig

config = sysconfig.get_config_vars()

for v in ['CC', 'CFLAGS', 'CCSHARED', 'INCLUDEPY', 'BLDSHARED', 'LDFLAGS', 'EXT_SUFFIX']:
  print(f'{v}={config[v]}')
