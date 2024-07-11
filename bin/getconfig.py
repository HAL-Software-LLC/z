import sysconfig

config = sysconfig.get_config_vars()

for v in ['CC', 'CFLAGS', 'CCSHARED', 'INCLUDEPY', 'BLDSHARED', 'LDFLAGS', 'EXT_SUFFIX']:
  s = ' '.join((w for w in config[v].split() if w))
  print(f"{v}={s}")
