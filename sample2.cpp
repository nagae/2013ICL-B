#include <iostream>		// 標準入出力用ライブラリを読み込む
using namespace std;		// 名前空間 std をデフォルトで利用する

// メインルーチン
int main ( void ){ // 引数無しで整数(int)型の戻り値を返す main 関数を定義
  double latitude, longitude; // 2つの倍精度実数型の変数 latitude, longitude を定義
  cout << "緯度と経度を入力して下さい" << endl; // 標準出力 cout に緯度・経度の入力を促すメッセージを表示
  cin >> latitude >> longitude;	// 標準入力から latitude と longitude の値を獲得
  cout << "緯度:" << latitude << " 経度:" << longitude << endl;
}
