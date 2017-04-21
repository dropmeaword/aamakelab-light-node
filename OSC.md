OSC messages:

str:address param1 param2 param3 param3 param4 ... paramN

A parameter: `str` `int` `float`


### This is what the node takes

Nodes listen on port `54321`.

Specific to the nodes of the installation:

|OSC address|params|description|
|---------|---------|----------|
|/node/off|(n.a.)|turn node off|
|/node/testpattern|(n.a.)|run test pattern on node|
|/node/solid|i:r i:g i:b|paint the whole node in one color|
|/node/solid|i:r i:g i:b|paint the whole node in one color|
|/node/pixels|i:r0 i:g0 i:b0 .... i:r35 i:g35 i:b35 | applies rgb values to all 36 pixels in a node|

str:"rrr,ggg,bbb"
int:rrr int:ggg int:bbb


### This is what Nick can produce


this is what Grasshopper seems to do:

|Grasshopper|Processing|
|---------|---------|
|`/0/Panel /node/solid str:node.x,node.y r,g,b`|`/node/solid i:r i:g i:b`|
|`/0/Panel node_xy /node/testpattern str:nodex,nodeyy`|`/node/testpattern`|
|`/0/Panel node_xy /node/gradient str:nodex,nodeyy r0,g0,b0,r1,g1,b1`|`/node/gradient i:r0 i:g0 i:b0 i:r1 i:g1 i:b1`|
|`/0/Panel node_xy /node/pixels str:nodex,nodeyy ar,ag,ab,br,bg,bb`|`/node/gradient i:ar i:ag i:ab i:br i:bg i:bb`|


#### Example

```
[/0/Panel OSC-string:`/node/solid 0,1 255,0,0']
[/0/Panel OSC-string:`/node/solid 0,1 255,0,0']
[/0/Panel OSC-string:`/node/solid 0,1 255,0,0']
[/0/Panel OSC-string:`/node/solid 0,1 255,0,0']
[/0/Panel OSC-string:`/node/solid 0,1 255,0,0']
[/0/Panel OSC-string:`/node/solid 0,1 255,0,0']
[/0/Panel OSC-string:`/node/solid 0,1 255,0,0']
[/0/Panel OSC-string:`/node/solid 0,1 255,0,0']
[/0/Panel OSC-string:`/node/solid 0,1 255,0,0']
[/0/Panel OSC-string:`/node/solid 0,1 255,0,0']
[/0/Panel OSC-string:`/node/solid 0,1 255,0,0']
[/0/Panel OSC-string:`/node/solid 0,1 255,0,0']
[/0/Panel OSC-string:`/node/solid 0,1 255,0,0']
[/0/Panel OSC-string:`/node/solid 0,1 255,0,0']
[/0/Panel OSC-string:`/node/solid 0,1 255,0,0']
[/0/Panel OSC-string:`/node/solid 0,1 255,0,0']```
