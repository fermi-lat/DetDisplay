# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/DetDisplay/SConscript,v 1.20 2015/07/24 09:32:04 glastrm Exp $
# Authors: T. Burnett <tburnett@u.washington.edu>
# Version: DetDisplay-03-06-00
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('addLinkDeps', package='DetDisplay', toBuild='component')

DetDisplay = libEnv.ComponentLibrary('DetDisplay',
				  listFiles(['src/*.cxx']))

progEnv.Tool('DetDisplayLib')
progEnv.Tool('GuiSvcLib')
progEnv.Tool('guiLib')

testDetDisplay = progEnv.GaudiProgram('TestDetDisplay', [], test=1,
				      package='DetDisplay')
progEnv.Tool('registerTargets', package = 'DetDisplay',
             libraryCxts = [[DetDisplay, libEnv]],
             testAppCxts = [[testDetDisplay, progEnv]],
	     jo = ['src/test/jobOptions.txt'])




