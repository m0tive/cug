import os

env = Environment(ENV=os.environ)

def CheckCtags(context, version):
    context.Message( 'Checking for ctags...' )
    ret = context.TryAction('ctags --version')[0]
    context.Result( ret )
    return ret

def CheckTouch(context):
    context.Message( 'Checking for touch...' )
    ret = context.TryAction('touch --version')[0]
    context.Result( ret )
    return ret

conf_tests = { 'CheckCtags' : CheckCtags,
               'CheckTouch' : CheckTouch
             }

HAS_CTAGS=True
HAS_TOUCH=True

conf = Configure(env, custom_tests = conf_tests)

if not conf.CheckCtags('0'):
    HAS_CTAGS = False

if not conf.CheckTouch():
    HAS_TOUCH = False

env = conf.Finish()

Export('env')

# Run the src SConscript, setting the build output to ./obj/
SConscript('libshp/SConscript',duplicate=0)
SConscript('src/SConscript', build_dir='obj',duplicate=0)
SConscript('demo/SConscript', duplicate=0)

if HAS_CTAGS :
    ctags_sources = Glob('src/*.cpp')
    ctags_sources.extend(Glob('include/cug/*.hpp'))
    tags = []
    for ctags_src in ctags_sources:
        if HAS_TOUCH :
            t = env.Command('.tags.' + str(ctags_src), ctags_src,
                "ctags -R --sort=yes --c++-kinds=+p --fields=+iaS --extra=+q $SOURCES && touch $TARGET")
        else:
            t = env.Command('.tags.' + str(ctags_src), ctags_src,
                "ctags -R --sort=yes --c++-kinds=+p --fields=+iaS --extra=+q $SOURCES")

        tags.append(t)
    env.Alias('tags', tags)
