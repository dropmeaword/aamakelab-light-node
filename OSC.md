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
`/0/Panel node_nr /node/solid str:r,g,b` -> `/node/solid i:r i:g i:b`

`/0/Panel node_nr /node/testpattern` -> `/node/testpattern`

`/0/Panel node_nr /node/gradient str:r0,g0,b0,r1,g1,b1` -> `/node/gradient i:r0 i:g0 i:b0 i:r1 i:g1 i:b1`

`/0/Panel node_nr /node/pixels str:ar,ag,ab,br,bg,bb` -> `/node/gradient i:ar i:ag i:ab i:br i:bg i:bb`
