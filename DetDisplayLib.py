#$Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/DetDisplay/DetDisplayLib.py,v 1.3 2009/11/06 23:31:01 jrb Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['DetDisplay'])
    env.Tool('TkrUtilLib')
    env.Tool('GlastSvcLib')
    env.Tool('geomrepLib')
    if env['PLATFORM']=='win32' and env.get('CONTAINERNAME','')=='GlastRelease':
        env.Tool('findPkgPath', package = 'GuiSvc') 
def exists(env):
    return 1;
