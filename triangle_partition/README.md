# Triangle Partition
- 三角形の中心分割

## 入力
- 1行目: 各グループの点の数N
- 2行目以降: 3N行ですべての点集合
- problemgen.pyで自動生成

## 出力
- 三角形の各頂点と結んで、入力された点を3等分する点の座標
- plot.pyでプロットするために、これより前の行で点の情報を出力している。

## 要件
- C++20に対応したコンパイラ
- GNU Make
- Python3
  - matplotlib

## 実行
```
$ make run
g++ -std=c++20 -O2 -mtune=native -march=native -flto -c main.cpp -o main.o
g++ -std=c++20 -O2 -mtune=native -march=native -flto -c triangle.cpp -o triangle.o
g++ -std=c++20 -O2 -mtune=native -march=native -flto main.o triangle.o -o triangle
./problemgen.py | ./triangle | ./plot.py
result: 0.26972 0.38938
$
```
以下の画像のように表示される。

<img src=fig1.png>

## 点の数の変更
- problemgen.pyの5行目のNの値を適当に変更する。
