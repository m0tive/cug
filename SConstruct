import os

env = Environment(ENV=os.environ)

## Only build the file when the timestamp has changed, and the MD5 hash is different
Decider('MD5-timestamp')

opt = Variables();

opt.AddVariables(
    BoolVariable('DEBUG', 'Compile a debug version of Mapnik', 'True')
    )

opt.Update(env)

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

## TODO : make debug build work properly...

env.AppendUnique( CPPDEFINES = [ env['PLATFORM'].upper() ] )

if env['DEBUG'] :
    env.AppendUnique( CPPDEFINES = [ '_DEBUG' ] )
    if 'g++' in env['TOOLS'] :
        env.AppendUnique( CCFLAGS = [ '-g', '-Wall' ] )
    elif 'msvc' in env['TOOLS'] :
        env.AppendUnique( CCFLAGS = [ '/Od', '/Gm', '/RTC1', '/W3', '/Wp64', '/Zi' ] )
else :
    env.AppendUnique( CPPDEFINES = [ 'NDEBUG' ] )
    if 'g++' in env['TOOLS'] :
        env.AppendUnique( CCFLAGS = [ '-O3', '-Wall', '-funroll-loops', '-ffast-math' ] )
    elif 'msvc' in env['TOOLS'] :
        env.AppendUnique( CCFLAGS = [ '/O3' ] )

env.AppendUnique( CPPPATH = ['#/include'] )

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
