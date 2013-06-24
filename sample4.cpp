#include <iostream>		// 標準入出力用ライブラリを読み込む
#include <iomanip> // 入出力表示精度を指定するためのライブラリを読み込む
#include <fstream> // ファイル入出力用ライブラリを読み込む
using namespace std;		// 名前空間 std をデフォルトで利用する

// メインルーチン
int main ( void ) { // 引数無しで整数(int)型の戻り値を返す main 関数を定義
  double latitude, longitude; // 2つの倍精度実数型の変数 latitude, longitude を定義
  ofstream fout("sample4.dat");	// sample4.dat という名前の出力ファイルを開く
  cout << "緯度と経度を入力して下さい" << endl; // 標準出力 cout に緯度・経度の入力を促すメッセージを表示
  cin >> latitude >> longitude;	// 標準入力から latitude と longitude の値を獲得
  cout.setf(ios::floatfield);	// 固定小数点表記を採用する
  cout.precision(6);		// 小数点以下の桁数を 6 に指定する
  fout << "緯度:" << latitude << " 経度:" << longitude << endl; // 入力された緯度と経度を表示する
}
