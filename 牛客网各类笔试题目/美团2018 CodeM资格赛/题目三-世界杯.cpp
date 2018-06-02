/*
[编程|1000分] 世界杯
时间限制：C/C++ 1秒，其他语言 2秒
空间限制：C/C++ 262144K，其他语言 524288K
题目描述
世界杯就要开始啦！真真正正的战斗从淘汰赛开始，
现在我们给出球队之间的胜负概率，来预测每支球队夺冠的可能性。
在接下来的篇幅中，我们将简单介绍淘汰赛阶段的规则。
淘汰赛阶段的90分钟常规时间内（含补时阶段）进球多的球队取胜，
如果参赛双方在90分钟内（含补时阶段）无法决出胜负，将进行上下半场各15分钟的加时赛。
加时赛阶段，如果两队仍未分出胜负，则通过点球大战决出胜者。
也就是说，每场比赛，有且仅有一个队能够晋级到下一轮。
淘汰赛共有16支球队参加（小组赛阶段共分8个小组，每组前两名晋级），对阵安排如下。
1/8决赛
A组第一对阵B组第二=胜者1
B组第一对阵A组第二=胜者2
C组第一对阵D组第二=胜者3
D组第一对阵C组第二=胜者4
E组第一对阵F组第二=胜者5
F组第一对阵E组第二=胜者6
G组第一对阵H组第二=胜者7
H组第一对阵G组第二=胜者8
获胜的8个队进入1/4决赛，即所谓“8强”
1/4决赛
胜者1对阵胜者3=胜者A
胜者2对阵胜者4=胜者B
胜者5对阵胜者7=胜者C
胜者6对阵胜者8=胜者D
1/4决赛的4个获胜队进入“4强”
半决赛
胜者A对阵胜者C
胜者B对阵胜者D
半决赛获胜两队进入决赛，失利的两队争夺三名
决赛获胜的队伍就是最后的冠军！
输入描述:
球队会被以1..16进行标号，其分别表示：
1 A组第一；
2 B组第二；
3 C组第一；
4 D组第二；
5 E组第一；
6 F组第二；
7 G组第一；
8 H组第二；
9 B组第一；
10 A组第二；
11 D组第一；
12 C组第二；
13 F组第一；
14 E组第二；
15 H组第一；
16 G组第二。

数据共有16行，每行16个浮点数，第i行第j列的数Fi,j表示i和j进行比赛时i获胜
（包括常规时间获胜、加时赛获胜以及点球大战获胜）的概率。
对于1 <= i, j <= 16 且 i != j, 满足0 <= Fi,j <= 1, Fi,j + Fj,i = 1；
对于1 <= i <= 16, 满足 Fi,i = 0。

输出描述:
输出一行16个浮点数，用空格隔开，分别表示每只球队获得世界杯的概率，结尾无空格。
绝对误差或相对误差在1e-5之内的解会被判为正确。
示例1
输入
0.000 0.133 0.210 0.292 0.670 0.270 0.953 0.353 0.328 0.128 0.873 0.082 0.771 0.300 0.405 0.455
0.867 0.000 0.621 0.384 0.934 0.847 0.328 0.488 0.785 0.308 0.158 0.774 0.923 0.261 0.872 0.924
0.790 0.379 0.000 0.335 0.389 0.856 0.344 0.998 0.747 0.895 0.967 0.383 0.576 0.943 0.836 0.537
0.708 0.616 0.665 0.000 0.146 0.362 0.757 0.942 0.596 0.903 0.381 0.281 0.294 0.788 0.804 0.655
0.330 0.066 0.611 0.854 0.000 0.687 0.983 0.217 0.565 0.293 0.256 0.938 0.851 0.487 0.190 0.680
0.730 0.153 0.144 0.638 0.313 0.000 0.832 0.526 0.429 0.707 0.414 0.617 0.925 0.638 0.526 0.545
0.047 0.672 0.656 0.243 0.017 0.168 0.000 0.357 0.125 0.307 0.879 0.551 0.641 0.959 0.981 0.465
0.647 0.512 0.002 0.058 0.783 0.474 0.643 0.000 0.325 0.494 0.893 0.064 0.563 0.429 0.501 0.872
0.672 0.215 0.253 0.404 0.435 0.571 0.875 0.675 0.000 0.940 0.053 0.329 0.232 0.280 0.359 0.474
0.872 0.692 0.105 0.097 0.707 0.293 0.693 0.506 0.060 0.000 0.040 0.776 0.589 0.704 0.018 0.968
0.127 0.842 0.033 0.619 0.744 0.586 0.121 0.107 0.947 0.960 0.000 0.486 0.266 0.662 0.374 0.698
0.918 0.226 0.617 0.719 0.062 0.383 0.449 0.936 0.671 0.224 0.514 0.000 0.821 0.027 0.415 0.227
0.229 0.077 0.424 0.706 0.149 0.075 0.359 0.437 0.768 0.411 0.734 0.179 0.000 0.841 0.409 0.158
0.700 0.739 0.057 0.212 0.513 0.362 0.041 0.571 0.720 0.296 0.338 0.973 0.159 0.000 0.935 0.765
0.595 0.128 0.164 0.196 0.810 0.474 0.019 0.499 0.641 0.982 0.626 0.585 0.591 0.065 0.000 0.761
0.545 0.076 0.463 0.345 0.320 0.455 0.535 0.128 0.526 0.032 0.302 0.773 0.842 0.235 0.239 0.000
输出
0.0080193239 0.1871963989 0.0797523190 0.1233859685 0.0836167329 0.0438390981 0.0079035829 0.0604644891 0.0237087902 0.0050549016 0.1149551151 0.0679247259 0.0511307364 0.0395744604 0.0800843771 0.0233889799
说明
注意：输入输出样例在小屏幕页面上可能被自动换行显示了，实际上是严格单行16个数字的。
*/