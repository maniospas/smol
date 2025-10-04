import ctypes

_lib = ctypes.CDLL("tests/unit/fib")
if _lib is None:
    raise RuntimeError('Library not loaded.')

class main__186__stateState(ctypes.Structure):
    _fields_ = [
        ('err', ctypes.c_int),
    ]

class main__186__state:
    def __init__(self):
        self._fn = _lib.main__186
        self._fn.restype = None
        self._fn.argtypes = [ctypes.POINTER(main__186__stateState)]

    def __call__(self):
        state = main__186__stateState()
        self._fn(ctypes.byref(state))
        if state.err:
             raise Exception('Failed service execution')
        return ()

class fib__185__stateState(ctypes.Structure):
    _fields_ = [
        ('err', ctypes.c_int),
        ('__6E____ret', ctypes.POINTER(ctypes.c_uint64)),
        ('n', ctypes.c_uint64),
    ]

class fib__185__state:
    def __init__(self):
        self._fn = _lib.fib__185
        self._fn.restype = None
        self._fn.argtypes = [ctypes.POINTER(fib__185__stateState)]

    def __call__(self, n):
        state = fib__185__stateState()
        __6E____ret = ctypes.c_uint64(0)
        state.__6E____ret = ctypes.pointer(__6E____ret)
        assert isinstance(n, int), "n must be u64"
        state.n = n
        self._fn(ctypes.byref(state))
        if state.err:
             raise Exception('Failed service execution')
        return (state.__6E____ret.contents.value)

main = main__186__state()
fib = fib__185__state()
