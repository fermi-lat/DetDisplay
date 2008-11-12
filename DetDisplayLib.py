#$Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/DetDisplay/DetDisplayLib.py,v 1.1 2008/08/15 21:42:34 ecephas Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['DetDisplay'])
    env.Tool('TkrUtilLib')
def exists(env):
    return 1;
