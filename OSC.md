OSC messages:

str:address param1 param2 param3 param3 param4 ... paramN

A parameter: `str` `int` `float`


### This is what the node takes

Specific to the nodes of the installation:

```
/node/off (switches light off)
/node/testpattern (this runs an RGB testpattern)
/node/solid i:r i:g i:b
/node/gradient i:ar i:ag i:ab i:br i:bg i:bb  [a -> b]
/node/pixels i:r0 i:g0 i:b0 .... i:r35 i:g35 i:b35  (36*3 integer values)
```

str:"rrr,ggg,bbb"
int:rrr int:ggg int:bbb


### This is what Nick can produce


this is what Grasshopper seems to do:
/0/Panel string:(this actually a parameter not THE command)
