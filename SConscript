# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/DetDisplay/SConscript,v 1.17 2012/05/15 18:38:23 heather Exp $
# Authors: T. Burnett <tburnett@u.washington.edu>
# Version: DetDisplay-03-05-03
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




