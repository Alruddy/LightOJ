# Day 10
***
**1074 - Extended Traffic**

`$(u,v)$`的边权是`$ (b[v] - b[u])^3$`，输出从顶点1到各点最短路径，因为存在负环，所以从负环到达的点的最短路是-inf。
* 如果最短路径小于3（包括负数）输出 '？'
* 否则输出最短路

***
**1108 - Instant View of Big Bang**

穿越回去看大爆炸，找到可以通往负环的点作为起点，并将起点列出来。

**思路**

可以将图反过来建，就转变成了可以从负环走到的点，跟上题一样。

***
**1221 - Travel Company**

旅游公司规划旅游路线，要求走完一条路线后 `总收入/总支出 > p`，转化一下就是
```math
in[0] + in[1] + \cdots + in[k] > p\times(out[0]+out[2]+\cdots+out[k])

in[0] + in[1] + \cdots + in[k] > p\times out[0]+ p \times out[2]+ \cdots+ p \times out[k]

(p\times out[0] - in[0])+ (p\times out[1] - in[1]) + \cdots + (p\times out[k] - in[k]) < 0
```
就直接令`$w = out*p - in$` 最后结出现一个负环即可

