import ctypes

lib = ctypes.CDLL('./main.so')

lib.run.argtypes = []

lib.run()