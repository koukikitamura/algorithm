- switch(expression)のexpressionは数値である必要がある。stringはだめ。
- operatorはc++の予約語
- シングルクォートはchar、ダブルクォートはchar*。char*とstringは==比較可能。
- breakはループとswitch文のみで使える。if文では使えない
- 文末には全てセミコロンをつける
- mainは関数でreturnを省略すると0を返すようにコンパイルされる。
  0以外を返すと異常値として扱われるが処理が決まっている訳ではない｡
  0以外を返すとAtCoderでRE(Runtime Error)になる。
  void mainはc++の標準では禁止されている
- boolean型ではなくbool型
- c++は0とfalseが偽、0以外の数値とtrueが真
- プロパティをコンストラクタで初期化するとそのクラスの型をもつ変数を定義した時にコンストラクトに渡す
　引数を持っていないとだめ。
- vectorは可変長配列。メモリをあらかじめ確保するにはresizeとreserveがある。resizeはiteratorのendをsize - 1に動かすがreserveが動かさない。[]でアクセスする場合はresizeを使って、push_backを使う場合はreserveを使う。
