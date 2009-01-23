# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/DetDisplay/SConscript,v 1.2 2008/11/12 17:47:14 ecephas Exp $
# Authors: T. Burnett <tburnett@u.washington.edu>
# Version: DetDisplay-03-03-00
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('DetDisplayLib', depsOnly = 1)

DetDisplay = libEnv.SharedLibrary('DetDisplay', listFiles(['src/*.cxx','src/Dll/*.cxx']))

progEnv.Tool('DetDisplayLib')
progEnv.Tool('GuiSvcLib')
progEnv.Tool('guiLib')

if baseEnv['PLATFORM'] != 'win32':
	progEnv.AppendUnique(LINKFLAGS=['-u GuiSvc_loadRef'])

if baseEnv['PLATFORM'] == 'win32':
	progEnv.AppendUnique(LINKFLAGS=['/include:_GuiSvc_loadRef'])
	progEnv.AppendUnique(LINKFLAGS=['/subsystem:windows'])  #from macro guiapp_linkopts in ../gui/cmt/requirements

progEnv.Tool('registerObjects', package = 'DetDisplay', libraries = [DetDisplay])




