# pB 被遺忘的禮物
## 題目敘述

今天是平安夜，聖誕老公公的小精靈們正在整理著要送給小朋友的禮物。但是因為禮物實在是太多了，有些禮物很可憐的被小精靈遺忘了。**這些被遺忘的禮物的周遭完全沒有其他禮物**，所以就自然被小精靈們給遺忘了。現在一位名叫「熊熊」的小精靈正在檢查有沒有被遺忘的禮物，但是聖誕老公公就快要啟程了，可以幫幫他快速的找出被遺忘的禮物在哪裡嗎？

禮物倉庫的大小不盡相同，而小精靈們會利用一張地圖來記錄倉庫內的禮物位置。你的任務就是寫出一個程式，找出倉庫中，被遺忘禮物的位置，並告訴快要過勞的熊熊。

一個禮物的周遭完全沒有禮物代表其**上、下、左、右、左上、左下、右上、右下**完全沒有其他禮物。

## 輸入說明
第一行為兩個以空白分隔的數字$N, M$，代表地圖的行數及列數。

接下來$N$行，每行會有$M$個字元。若字元為`*`，則代表此處放著一個禮物。若為`.`，則代表此處沒有禮物。

測資保證：
- 10%: $1 \leq N, M \leq 100$，且沒有不被遺忘的禮物。
- 40%: $1 \leq N, M \leq 100$
- 50%: $1 \leq N, M \leq 2 \times 10^3$

## 輸出說明
第一行先輸出一個整數$K$，代表被遺忘的禮物總數。

接下來$K$行，每行輸出兩個整數$X_i, Y_i$代表被遺忘的禮物是在倉庫的第$X_i$行、第$Y_i$列。

另外輸出的順序要按照$X_i, Y_i$的順序由小排到大。也就是說先排序$X_i$的大小，若$X_i$相同，則排列$Y_i$。
## 範例輸入及輸出
### 輸入1:
```
7 5
.*...
*....
..*.*
...*.
.....
.**.*
..*..
```
### 輸出1:
```
1
6 5
```

### 輸入2:
```
6 6
...*..
*...**
*....*
*.****
..*...
*.*...
```

### 輸出2:
```
1
6 1
```
### 輸入3:
```
2 4
*..*
....
```

### 輸出3:
```
2
1 1
1 4
```

## 考點

DFS/BFS