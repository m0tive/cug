import os

env = Environment(ENV=os.environ)

Export('env')

# Run the src SConscript, setting the build output to ./obj/
SConscript('libshp/SConscript',duplicate=0)
SConscript('src/SConscript', build_dir='obj',duplicate=0)
SConscript('demo/SConscript', duplicate=0)

ctags_sources = Glob('src/*.cpp')
ctags_sources.extend(Glob('include/cug/*.hpp'))
tags = []
for ctags_src in ctags_sources:
    t = env.Command('.tags.' + str(ctags_src), ctags_src,"ctags -R --sort=yes --c++-kinds=+p --fields=+iaS --extra=+q $SOURCES && touch $TARGET")
    tags.append(t)
env.Alias('tags', tags)
