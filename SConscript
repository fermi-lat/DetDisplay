# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/DetDisplay/SConscript,v 1.7 2010/06/11 00:34:32 jrb Exp $
# Authors: T. Burnett <tburnett@u.washington.edu>
# Version: DetDisplay-03-03-02
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('addLinkDeps', package='DetDisplay', toBuild='component')

DetDisplay = libEnv.SharedLibrary('DetDisplay',
				  listFiles(['src/*.cxx','src/Dll/*.cxx']))

progEnv.Tool('DetDisplayLib')
progEnv.Tool('GuiSvcLib')
progEnv.Tool('guiLib')

if baseEnv['PLATFORM'] != 'win32':
	progEnv.AppendUnique(LINKFLAGS=['-u GuiSvc_loadRef'])

else:
	progEnv.AppendUnique(LINKFLAGS=['/include:_GuiSvc_loadRef'])
	progEnv.AppendUnique(LINKFLAGS=['/subsystem:windows'])  #from macro guiapp_linkopts in ../gui/cmt/requirements

testDetDisplay = progEnv.GaudiProgram('TestDetDisplay', [], test=1,
				      package='DetDisplay')
progEnv.Tool('registerTargets', package = 'DetDisplay',
             libraryCxts = [[DetDisplay, libEnv]],
             testAppCxts = [[testDetDisplay, progEnv]],
	     jo = ['src/test/jobOptions.txt'])




