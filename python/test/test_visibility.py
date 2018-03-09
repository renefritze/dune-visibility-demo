#/usr/bin/env python

import sys
import os
sys.setdlopenflags(os.RTLD_NOW | os.RTLD_GLOBAL)

def test_singleton_count():
    import xtvis.aaa._aaa as aa
    hidden, visible = aa.count()
    assert hidden == visible == 1

    import xtvis.bbb._bbb as bb
    hidden, visible = bb.count()
    assert hidden == 1
    assert visible == 2

    import xtvis.ccc._ccc as cc
    hidden, visible = cc.count()
    assert hidden == 1
    assert visible == 3

    bb.inc()
    hidden, visible = bb.count()
    assert hidden == 2
    assert visible == 4

