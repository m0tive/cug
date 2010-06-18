import os

env = Environment(ENV=os.environ)

Export('env')

# Run the src SConscript, setting the build output to ./obj/
SConscript('src/SConscript', build_dir='obj',duplicate=0)
SConscript('demo/SConscript', duplicate=0)

ctags_sources = Glob('src/*.cpp')
ctags_sources.extend(Glob('include/cug/*.hpp'))
ctags = env.Command('tags', ctags_sources,"ctags -R --sort=yes --c++-kinds=+p --fields=+iaS --extra=+q $SOURCES")
env.Alias('TAGS',ctags)
