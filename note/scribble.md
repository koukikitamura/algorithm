- switch(expression)のexpressionは数値である必要がある。stringはだめ。
- operatorはc++の予約語
- シングルクォートはchar、ダブルクォーとはchar*。char*とstringは==比較可能。
- breakはループとswitch文のみで使える。if文では使えない
- 文末には全てセミコロンをつける
- mainは関数でreturnを省略すると0を返すようにコンパイルされる。
  0以外を返すと異常値として扱われるが処理が決まっている訳ではない｡
  0以外を返すとAtCoderでRE(Runtime Error)になる。
  void mainはc++の標準では禁止されている
- boolean型ではなくbool型
- c++は0とfalseが偽、0以外の数値とtrueが真
