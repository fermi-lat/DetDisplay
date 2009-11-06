#$Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/DetDisplay/DetDisplayLib.py,v 1.2 2008/11/12 17:51:29 ecephas Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['DetDisplay'])
    env.Tool('TkrUtilLib')
    env.Tool('GlastSvcLib')
    env.Tool('geomrepLib')
def exists(env):
    return 1;
