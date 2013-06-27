#include <iostream>		// 標準入出力用ライブラリを読み込む
#include <iomanip> 		// 入出力表示精度を指定するためのライブラリを読み込む
#include <fstream>	       	// ファイル入出力用ライブラリを読み込む
#include <string>		// 文字列用ライブラリを読み込む

using namespace std;		// 名前空間 std をデフォルトで利用する

// メインルーチン
int main ( void ) { // 引数無しで整数(int)型の戻り値を返す main 関数を定義
  ifstream fin("bus-short.csv"); // ファイル入力ストリーム
  while ( !fin.eof() ) {	 // fin がファイルの終わりまできていない間繰り返す
    // ファイルから1行読み込んで文字列に一時保管
    string line;		 // 読み込み用文字列
    getline(fin, line);	 // 1行読み込む

    // 一時保管された文字列からバス停データを読み込む
    int ID;			// バス停ID用の整数型の変数を定義
    char name[100];		// バス停名用の文字列型の変数を定義
    double latitude, longitude; // 緯度・経度用の2つの倍精度実数型の変数を定義
    sscanf(line.c_str(),
	   "%d,%lf,%lf,%[^\n]",
	   &ID, &latitude, &longitude, name
	   );
    cout << "ID:" << ID
	 << " 緯度:" << latitude
	 << " 経度:" << longitude
	 << " バス停名:" << name << endl;
  }
}
