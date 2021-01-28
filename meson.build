project(
    '7kaa', # project name
    'cpp', # C++ project, e.g: for C project
    version : '2.15.5',
    license : 'GPL-2.0',
    default_options : ['cpp_std=c++11']) # compile for C++

libcurl = dependency('libcurl')
libenet = dependency('libenet')
libopenal = dependency('openal')
libsdl = dependency('sdl2', version:'>=2.0.4')

if libopenal.found()
    add_global_arguments('-DUSE_OPENAL=true', language : 'cpp')
    add_global_arguments('-DOPENAL_AL_H=<AL/al.h>', language : 'cpp')
    add_global_arguments('-DOPENAL_ALC_H=<AL/alc.h>', language : 'cpp')
else
    error('Open AL could not be found')
endif

if libcurl.found()
    add_global_arguments('-DHAVE_LIBCURL=1', language : 'cpp')
endif

#add_global_arguments('-DUSE_POSIX=1', language : 'c')
add_global_arguments('-DUSE_POSIX=1', language : 'cpp')
add_global_arguments('-DHAVE_STRING_STRCASECMP=1', language : 'cpp')
add_global_arguments('-DNO_MEM_CLASS=1', language : 'cpp')
#add_global_arguments('-DUSE_ASM=1', language : 'cpp')

add_global_arguments('-DDEBUG=0', language : 'cpp')
add_global_arguments('-DDYNARRAY_DEBUG_ELEMENT_ACCESS=0', language : 'cpp')
##conf_data.set('DEBUG', 'false')
#add_project_link_arguments('-fsigned-char' ,'-mfpmath=387', '-ffloat-store', language :'cpp')

summary({'bindir': get_option('bindir'),
         'libdir': get_option('libdir'),
         'datadir': get_option('datadir'),
         'prefix': get_option('prefix'),
        }, section: 'Directories')

summary({'buildtype': get_option('buildtype'),
         #'Another boolean': true,
         #'Some string': 'Hello World',
         #'A list': ['string', 1, true],
         'libcurl found' : libcurl.found()
        }, section: 'Configuration')



# it will be referred from subdir projects
inc = include_directories('include')

# meson will try to find a meson.build file inside following directories
subdir('include')
subdir('po')
subdir('src')

install_subdir('data', install_dir: get_option('prefix') / get_option('datadir'))
