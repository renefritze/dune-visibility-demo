#/usr/bin/env python

import xtvis.aaa._aaa as aa

print('hidden|visible')
print(aa.count())

import xtvis.bbb._bbb as bb
print(bb.count())

import xtvis.ccc._ccc as cc
print(cc.count())
print(bb.count())
