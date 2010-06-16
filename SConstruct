import os

env = Environment(ENV=os.environ)

Export('env')

# Run the src SConscript, setting the build output to ./obj/
SConscript('src/SConscript', build_dir='obj',duplicate=0)
SConscript('demo/SConscript', duplicate=0)
